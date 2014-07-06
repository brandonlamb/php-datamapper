<?php
namespace Pdm\Db\Adapter\Pdo;

use Pdm\Db\AbstractPdoTest;
use Pdm\Db\Pdo;
use Pdm\Db\Adapter\Pdo\Sqlite;

class SqliteTest extends AbstractPdoTest
{
    protected $pdo;
    protected $adapter;

    public function setUp()
    {
        parent::setUp();
        $this->adapter = new Sqlite($this->pdo);
    }

    protected function newPdo()
    {
        return new Pdo('sqlite::memory:');
    }

    protected function getMockPdo()
    {
        return new Pdo(
            'mock:host=db.example.com',
            'username',
            'password',
            []
        );
    }

    public function testCreateAdapter()
    {
        $adapter = new Sqlite($this->getMockPdo());
        $this->assertInstanceOf('\Pdm\Db\AdapterInterface', $adapter);
        $this->assertInstanceOf('\Pdm\Db\Adapter\Pdo\Sqlite', $adapter);

        $pdo = $adapter->getInternalHandler();
        $expect = 'mock:host=db.example.com';
        $actual = $pdo->getDsn();
        $this->assertSame($expect, $actual);
    }

    public function testSupportSequences()
    {
        $this->assertFalse($this->adapter->supportSequences());
    }

    public function testGetType()
    {
        $this->assertEquals('sqlite', $this->adapter->getType());
    }

    public function testGetDialectType()
    {
        $this->assertEquals('sqlite', $this->adapter->getDialectType());
    }
}
