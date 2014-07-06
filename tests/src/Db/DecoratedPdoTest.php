<?php
namespace Pdm\Db;

use Pdm\Db\Adapter\Pdo\SqliteTest;

class DecoratedPdoTest extends SqliteTest
{
    protected $decorated_pdo;

    protected function newPdo()
    {
        $this->decorated_pdo = new \PDO('sqlite::memory:');
        return new Pdo($this->decorated_pdo);
    }

    public function testGetPdo()
    {
        $this->assertSame($this->decorated_pdo, $this->pdo->getPdo());
    }
}
