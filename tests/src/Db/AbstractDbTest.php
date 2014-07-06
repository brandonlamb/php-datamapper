<?php
namespace Pdm\Db;

use Pdm\Db\AbstractDb;

class AbstractDbTest extends \PHPUnit_Framework_TestCase
{
    protected $pdo;

    protected function setUp()
    {
        $this->pdo = new Pdo(
            'mock:host=db.example.com',
            'username',
            'password',
            []
        );
    }

    public function testCreateAdapter()
    {
        $adapter = AbstractDb::createAdapter('db2', $this->pdo);
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Db2', $adapter);

        $adapter = AbstractDb::createAdapter('ibm', $this->pdo);
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Db2', $adapter);

        $adapter = AbstractDb::createAdapter('mysql', $this->pdo);
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Mysql', $adapter);

        $adapter = AbstractDb::createAdapter('oci', $this->pdo);
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Oracle', $adapter);

        $adapter = AbstractDb::createAdapter('oracle', $this->pdo);
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Oracle', $adapter);

        $adapter = AbstractDb::createAdapter('pgsql', $this->pdo);
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Pgsql', $adapter);

        $adapter = AbstractDb::createAdapter('postgres', $this->pdo);
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Pgsql', $adapter);

        $pdo = $adapter->getInternalHandler();
        $expect = 'mock:host=db.example.com';
        $actual = $pdo->getDsn();
        $this->assertSame($expect, $actual);
    }
}
