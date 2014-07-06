<?php
namespace Pdm\Di;

class ContainerTest extends \PHPUnit_Framework_TestCase
{
    protected $container;

    protected function setUp()
    {
        parent::setUp();
        $this->container = new Container();
    }

    public function testMagicGet()
    {
        $expect = new FakeParentClass;
        $this->container->foo = $expect;

        $this->assertSame($expect, $this->container->foo);
    }

    public function testHasGet()
    {
        $expect = new FakeParentClass;
        $this->container->set('foo', $expect);

        $this->assertTrue($this->container->has('foo'));
        $this->assertFalse($this->container->has('bar'));

        $actual = $this->container->get('foo');
        $this->assertSame($expect, $actual);

        // get it again for coverage
        $again = $this->container->get('foo');
        $this->assertSame($actual, $again);
    }

    public function testGetNoSuchService()
    {
        $this->setExpectedException('\Pdm\Di\Exception\ServiceNotFound');
        $this->container->get('foo');
    }

    public function testGetServiceInsideClosure()
    {
        $di = $this->container;
        $di->set('foo', function() use ($di) {
            return new FakeParentClass;
        });

        $actual = $this->container->get('foo');
        $this->assertInstanceOf('\Pdm\Di\FakeParentClass', $actual);
    }

    public function testGetServicesAndInstances()
    {
        $this->container->set('foo', new \StdClass);
        $this->container->set('bar', new \StdClass);
        $this->container->set('baz', new \StdClass);

        $expect = array('foo', 'bar', 'baz');
        $actual = $this->container->getServices();
        $this->assertSame($expect, $actual);

        $service = $this->container->getShared('bar');
        $expect = array('bar');
        $actual = $this->container->getSharedServices();
        $this->assertSame($expect, $actual);
    }

    public function testMagicGetNoSuchProperty()
    {
        $this->setExpectedException('Pdm\Di\Exception\ServiceNotFound');
        $actual = $this->container->no_such_property;
    }

    public function testGetShared()
    {
        $expect = new FakeParentClass;
        $this->container->set('foo', $expect);

        $actual = $this->container->getShared('foo');
        $this->assertInstanceOf('Pdm\Di\FakeParentClass', $actual);
    }
}
