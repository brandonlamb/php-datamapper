<?php
namespace Pdm\Db;

class RawValueTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @covers \Pdm\Db\RawValue::__construct
     */
    public function testConstruct()
    {
        $value = new \Pdm\Db\RawValue('test');
        $this->assertEquals('test', (string) $value);
    }

    /**
     * @covers \Pdm\Db\RawValue::getValue
     */
    public function testGetValue()
    {
        $value = new \Pdm\Db\RawValue('test');
        $this->assertEquals('test', $value->getValue());
    }

    /**
     * @covers \Pdm\Db\RawValue::getValue
     */
    public function testToString()
    {
        $value = new \Pdm\Db\RawValue('test');
        $this->assertEquals('test', $value->__toString());
    }
}
