<?php
namespace Pdm\Db;

abstract class AbstractPdoTest extends \PHPUnit_Framework_TestCase
{
    protected $pdo;

    protected $data = array(
        1 => 'Anna',
        2 => 'Betty',
        3 => 'Clara',
        4 => 'Donna',
        5 => 'Fiona',
        6 => 'Gertrude',
        7 => 'Hanna',
        8 => 'Ione',
        9 => 'Julia',
        10 => 'Kara',
    );

    public function setUp()
    {
        if (! extension_loaded('pdo_sqlite')) {
            $this->markTestSkipped("Need 'pdo_sqlite' to test in memory.");
        }

        $this->pdo = $this->newPdo();

        $this->createTable();
        $this->fillTable();
    }

    abstract protected function newPdo();

    protected function createTable()
    {
        $stm = "CREATE TABLE pdotest (
            id   INTEGER PRIMARY KEY AUTOINCREMENT,
            name VARCHAR(10) NOT NULL
        )";

        $this->pdo->exec($stm);
    }

    // only fills in schema 1
    protected function fillTable()
    {
        foreach ($this->data as $id => $name) {
            $this->insert(array('name' => $name));
        }
    }

    protected function insert(array $data)
    {
        $cols = array_keys($data);
        $vals = array();
        foreach ($cols as $col) {
            $vals[] = ":$col";
        }
        $cols = implode(', ', $cols);
        $vals = implode(', ', $vals);
        $stm = "INSERT INTO pdotest ({$cols}) VALUES ({$vals})";
        $this->pdo->perform($stm, $data);
    }

    public function testPrepare()
    {
        $sth = $this->adapter->prepare("select * from pdotest");
        $this->assertInstanceof('PDOStatement', $sth);
    }

    public function testExecutePrepared()
    {
        $sth = $this->adapter->prepare("select * from pdotest");
        $this->assertInstanceof('PDOStatement', $sth);
        $this->assertInstanceof('PDOStatement', $this->adapter->executePrepared($sth));

        $binds = [1];
        $bindTypes = [Column::BIND_PARAM_INT];
        $sth = $this->adapter->prepare("select * from pdotest where id > ?");

        $this->assertInstanceof('PDOStatement', $sth);
        $this->assertInstanceof('PDOStatement', $this->adapter->executePrepared($sth, $binds, $bindTypes));
        $this->assertInstanceof('PDOStatement', $this->adapter->executePrepared($sth, $binds, []));
        $this->assertInstanceof('PDOStatement', $this->adapter->executePrepared($sth, $binds));
    }

    /**
     * @xrequires extension disabled
     */
    public function testQuery()
    {
        $statement = "select * from pdotest";

        $sth = $this->adapter->query($statement);
        $this->assertInstanceof('\Pdm\Db\ResultInterface', $sth);

        $sth = $this->adapter->query($statement . ' where id > ?', [1]);
        $this->assertInstanceof('\Pdm\Db\ResultInterface', $sth);

        $sth = $this->adapter->query($statement . ' where id = ?', [1]);
        $this->assertInstanceof('\Pdm\Db\ResultInterface', $sth);

        $sth = $this->adapter->query($statement . ' where id > ?', [1], [Column::BIND_PARAM_INT]);
        $this->assertInstanceof('\Pdm\Db\ResultInterface', $sth);

        $sth = $this->adapter->query($statement . ' where id = ?', [1], [Column::BIND_PARAM_INT]);
        $this->assertInstanceof('\Pdm\Db\ResultInterface', $sth);
    }

    public function testExecute()
    {
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);

        $statement = "select * from pdotest where id > ?";
        $result = $this->adapter->execute($statement, [1], [Column::BIND_PARAM_INT]);
        $this->assertTrue($result);

        $statement = "select * from pdotest where id > ?";
        $result = $this->adapter->execute($statement, [1]);
        $this->assertTrue($result);

        $statement = "select * from pdotest";
        $result = $this->adapter->execute($statement);
        $this->assertTrue($result);
    }

    /**
     * @xrequires extension disabled
     */
    public function testAffectedRows()
    {
        $statement = "select * from pdotest where id > ?";
        $result = $this->adapter->query($statement, [1], [Column::BIND_PARAM_INT]);
        $this->assertEquals(0, $this->adapter->affectedRows());

        $statement = "UPDATE pdotest SET name = ? WHERE id = ?";
        $result = $this->adapter->execute($statement, ['Bill', 1], [Column::BIND_PARAM_STR, Column::BIND_PARAM_INT]);
        $this->assertEquals(1, $this->adapter->affectedRows());
    }

    public function testClose()
    {
        $this->assertTrue($this->adapter->close());
    }

    public function testEscapeIdentifier()
    {
        $before = 'test';
        $after = $this->adapter->escapeIdentifier($before);
        $expected = '"test"';
        $this->assertEquals($expected, $after);

        $before = 'test1.test2';
        $after = $this->adapter->escapeIdentifier($before);
        $expected = '"test1.test2"';
        $this->assertEquals($expected, $after);
    }

    public function testLastInsertId()
    {
        $statement = "insert into pdotest (name) values(?)";
        $result = $this->adapter->execute($statement, ['Test User']);
        $this->assertEquals(1, $this->adapter->affectedRows());
        $this->assertTrue($this->adapter->lastInsertId() > 0);
    }

    public function testSetDialect()
    {
        $dialect = new \Pdm\Db\Dialect\Mysql();
        $this->adapter->setDialect($dialect);
        $this->assertInstanceof('\Pdm\Db\DialectInterface', $this->adapter->getDialect());
    }

    public function testGetDialect()
    {
        $this->assertInstanceof('\Pdm\Db\DialectInterface', $this->adapter->getDialect());
    }

    /**
     * @xrequires extension disabled
     */
    public function testFetchOne()
    {
        $statement = 'SELECT * FROM pdotest WHERE id = ? OR id = ?';
        $result = $this->adapter->fetchOne($statement, \PDO::FETCH_ASSOC, [1,2], [Column::BIND_PARAM_INT, Column::BIND_PARAM_INT]);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest';
        $result = $this->adapter->fetchOne($statement);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE 1';
        $result = $this->adapter->fetchOne($statement);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > 1';
        $result = $this->adapter->fetchOne($statement);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > ?';
        $result = $this->adapter->fetchOne($statement, \PDO::FETCH_ASSOC, [1]);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > ?';
        $result = $this->adapter->fetchOne($statement, \PDO::FETCH_ASSOC, [1], []);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > ?';
        $result = $this->adapter->fetchOne($statement, \PDO::FETCH_ASSOC, [1], [Column::BIND_PARAM_INT]);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);
    }

    /**
     * @xrequires extension disabled
     */
    public function testFetchAll()
    {
        $statement = 'SELECT * FROM pdotest WHERE id > ? AND id < ?';
        $result = $this->adapter->fetchAll($statement, \PDO::FETCH_ASSOC, [1 ,10], [Column::BIND_PARAM_INT, Column::BIND_PARAM_INT]);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest';
        $result = $this->adapter->fetchAll($statement);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE 1';
        $result = $this->adapter->fetchAll($statement);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > 1';
        $result = $this->adapter->fetchAll($statement);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > ?';
        $result = $this->adapter->fetchAll($statement, \PDO::FETCH_ASSOC, [1]);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > ?';
        $result = $this->adapter->fetchAll($statement, \PDO::FETCH_ASSOC, [1], []);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);

        $statement = 'SELECT * FROM pdotest WHERE id > ?';
        $result = $this->adapter->fetchAll($statement, \PDO::FETCH_ASSOC, [1], [Column::BIND_PARAM_INT]);
        #$this->assertInstanceof('\Pdm\Db\ResultInterface', $result);
        $this->assertInternalType('array', $result);
    }

    public function testIsNestedTransactionsWithSavepoints()
    {
        $this->assertFalse($this->adapter->isNestedTransactionsWithSavepoints());
    }

    public function testGetNestedTransactionSavepointName()
    {
        $expected = 'Pdm_SAVEPOINT_0';
        $this->assertEquals($expected, $this->adapter->getNestedTransactionSavepointName());
    }
}
