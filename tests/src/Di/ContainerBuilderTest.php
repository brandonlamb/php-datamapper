<?php
namespace Pdm\Di;

class ContainerBuilderTest extends \PHPUnit_Framework_TestCase
{
    public function testNewInstance()
    {
        $builder = new ContainerBuilder;

        $preset_service = (object) array('irk' => 'doom');
        $services = array(
            'preset_service' => $preset_service
        );

        $di = $builder->newInstance($services);

        $this->assertInstanceOf('Pdm\Di\ContainerInterface', $di);
        $this->assertSame($preset_service, $di->get('preset_service'));
    }
}
