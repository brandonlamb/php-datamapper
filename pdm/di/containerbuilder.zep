
/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Di
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Di;

use Pdm\Di\Container;

/**
 * Creates and configures a new DI container.
 *
 * @package Pdm\Di
 */
class ContainerBuilder
{
    /**
     * Creates a new DI container, adds pre-existing service objects, applies
     * Config classes to define() services, locks the container, and applies
     * the Config instances to modify() services.
     *
     * @param array services Pre-existing service objects to set into the
     * container.
     * @return Container
     */
    public function newInstance(var services = []) -> <\Pdm\Di\ContainerInterface>
    {
        var di, key, val;

        let di = new Container();

        for key, val in services {
            di->set(key, val);
        }

        return di;
    }
}
