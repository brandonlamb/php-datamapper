<?php
namespace Pdm\Db;

use Pdm\Db\Adapter\Pdo\SqliteTest;

class PdoTest extends SqliteTest
{
    protected function newPdo()
    {
        return new Pdo('sqlite::memory:');
    }

    public function testGetPdo()
    {
        $lazy_pdo = $this->pdo->getPdo();
        $this->assertInstanceOf('PDO', $lazy_pdo);
        $this->assertNotSame($this->pdo, $lazy_pdo);
    }
}
