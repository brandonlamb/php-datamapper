
/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Di
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Di;

/**
 * Interface for dependency injection containers.
 *
 * @package Pdm\Di
 */
interface ContainerInterface
{
    /**
     * Registers a service in the services container
     *
     * @param string offset
     * @param mixed definition
     * @param boolean shared
     * @return Pdm\Di\ContainerInterface
     */
    public function set(string! offset, var definition, boolean shared = false) -> <\Pdm\Di\ContainerInterface>;

    /**
     * Removes a service in the services container
     *
     * @param string offset
     * @return \Pdm\Di\ContainerInterface
     */
    public function remove(string! offset) -> <\Pdm\Di\ContainerInterface>;

    /**
     * Resolves the service based on its configuration
     *
     * @param string offset
     * @return mixed
     */
    public function get(string! offset);

    /**
     * Returns a shared service based on their configuration
     *
     * @param string offset
     * @return mixed
     */
    public function getShared(string! offset);

    /**
     * Check whether the DI contains a service by a name
     *
     * @param string offset The service key to look up.
     * @return boolean
     */
    public function has(string! offset) -> boolean;

    /**
     * Set a default dependency injection container to be obtained into static methods
     *
     * @param Pdm\Di\ContainerInterface dependencyInjector
     */
    public static function setDefault(dependencyInjector) -> <\Pdm\Di\ContainerInterface>;

    /**
     * Return the last DI created
     *
     * @return Pdm\Di\ContainerInterface
     */
    public static function getDefault() -> <\Pdm\Di\ContainerInterface>;

    /**
     * Gets the list of shared services provided.
     *
     * @return array
     */
    public function getSharedServices() -> array;

    /**
     * Gets the list of service definitions.
     *
     * @return array
     */
    public function getServices() -> array;

    /**
     * Gets the list of parameters.
     *
     * @return array
     */
    public function getParams() -> array;
}
