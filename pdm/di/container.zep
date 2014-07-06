
/**
 * Dependency Injection container
 *
 * @package \Pdm\Di
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Di;

class Container implements ContainerInterface
{
    /**
     * @var \Pdm\Di
     */
    protected static defaultInstance;

    /**
     * @var array
     */
    protected container;

    /**
     * Shared objects for classes that should get instantiated only once such as a database object
     * @var array
     */
    protected sharedContainer;

    /**
     * @var array, hold parameters
     */
    protected paramContainer;

    /**
     * Accept an array as a container to populate
     *
     * @param array $container
     * @param array $sharedContainer
     * @param array $paramContainer
     */
    public function __construct(var container = null, var sharedContainer = null, var paramContainer = null)
    {
        var defaultInstance;

        let defaultInstance = self::defaultInstance;
        if !defaultInstance {
            let self::defaultInstance = this;
        }

        if typeof container == "array" {
            let this->container = container;
        } else {
            let this->container = [];
        }

        if typeof sharedContainer == "array" {
            let this->sharedContainer = sharedContainer;
        } else {
            let this->sharedContainer = [];
        }

        if typeof paramContainer == "array" {
            let this->paramContainer = paramContainer;
        } else {
            let this->paramContainer = [];
        }
    }

    /**
     * Magic getter to access container objects
     *
     * @param string offset
     * @return mixed
     */
    public function __get(string! offset)
    {
        return this->getShared(offset);
    }

    /**
     * Magic getter to set container objects
     *
     * @param string offset
     * @param mixed value
     */
    public function __set(string! offset, var value) -> <\Pdm\Di\ContainerInterface>
    {
        return this->set(offset, value, true);
    }

    /**
     * Set an object into the container
     *
     * @param string offset
     * @param mixed value
     * @throws \Pdm\Exception
     * @return \Pdm\Di\ContainerInterface
     */
    public function set(string! offset, var value, boolean shared = false) -> <\Pdm\Di\ContainerInterface>
    {
        // If config is an array, verify it has a required className key
        if typeof value == "array" && !isset value["className"] {
            throw new Exception("Must contain a className key.");
        }

        if !shared {
            let this->container[offset] = value;
        } else {
            let this->sharedContainer[offset] = value;
        }

        return this;
    }

    /**
     * Set an object/value into the parameter container
     *
     * @param string offset
     * @param mixed value
     * @return \Pdm\Di\ContainerInterface
     */
    public function setParam(string! offset, var value) -> <\Pdm\Di\ContainerInterface>
    {
        let this->paramContainer[offset] = value;
        return this;
    }

    /**
     * Get an object from the container
     *
     * @param string offset
     * @throws \Pdm\Di\Exception\ServiceNotFound
     * @return mixed
     */
    public function get(string! offset)
    {
        var service;
        var className;
        var instance;

        if !fetch service, this->container[offset] {
            throw new Exception\ServiceNotFound(offset . " is not defined.");
        }

        // If the object is a string, return new object using the value as the class name
        if typeof service == "string" {
            return new {service}();
        }

        // If the object is an array, return a new object using the defined class name
        // and pass in the object as the constructor parameter. If the class is an instance
        // of a InjectionAwareInterface then set the Di container for the object
        if typeof service == "array" {
            if fetch className, service["className"] {
                let instance = new {className}(service);

                if typeof instance == "object" {
                    if instance instanceof \Pdm\Di\InjectionAwareInterface {
                        instance->setDi(this);
                    }
                }

                return instance;
            }
        }

        // If the object is a Closure, just return it
        if typeof service == "object" {
            if service instanceof \Closure {
                return {service}();
            }
        }

        // Object is an already instantiated object, just return it
        return service;
    }

    /**
     * Get an object from the shared container
     *
     * @param string offset
     * @return mixed
     */
    public function getShared(string! offset)
    {
        var instance;

        // If the shared object is already set then just return if
        if fetch instance, this->sharedContainer[offset] {
            return instance;
        }

        // Pull in a new instance of the requested alias from the container.
        // Equivalent of $obj = $di->get('abc'), $di->setShared('abc', $obj)
        let instance = this->get(offset);
        let this->sharedContainer[offset] = instance;

        return instance;
    }

    /**
     * Get an object from the param container
     *
     * @param string offset
     * @throws \Pdm\Di\Exception\ParamterNotFound
     * @return mixed
     */
    public function getParam(string! offset)
    {
        var param;
        if fetch param, this->paramContainer[offset] {
            return param;
        }
        throw new Exception\ParameterNotFound("Parameter " . offset . " not set");
    }

    /**
     * Remove an object from the container
     *
     * @param string offset
     * @throws Exception
     * @return DiInterface
     */
    public function remove(string! offset) -> <\Pdm\Di\ContainerInterface>
    {
        if isset this->container[offset] {
            unset this->container[offset];
        }

        if isset this->sharedContainer[offset] {
            unset this->sharedContainer[offset];
        }

        if isset this->paramContainer[offset] {
            unset this->paramContainer[offset];
        }

        return this;
    }

    /**
     * Set the default Di container to return by getDefault()
     *
     * @param DiInterface $di
     * @return DiInterface
     */
    public static function setDefault(<\Pdm\Di\ContainerInterface> di) -> <\Pdm\Di\ContainerInterface>
    {
        let self::defaultInstance = di;
        return di;
    }

    /**
     * Returns the default Di container instance, or if one was not created
     * then created a new instance and set the default
     *
     * @return DiInterface
     */
    public static function getDefault()
    {
        return self::defaultInstance;
    }

    /**
     * Check if the container contains the index
     *
     * @param string offset
     * @return bool
     */
    public function has(string! offset) -> boolean
    {
        return isset this->container[offset];
    }

    /**
     * Check if the shared container contains the index
     *
     * @param string offset
     * @return bool
     */
    public function hasShared(string! offset) -> boolean
    {
        return isset this->sharedContainer[offset];
    }

    /**
     * Check if the param container contains the index
     *
     * @param string offset
     * @return bool
     */
    public function hasParam(string! offset) -> boolean
    {
        return isset this->paramContainer[offset];
    }

    /**
     * Gets the list of shared services provided.
     *
     * @return array
     */
    public function getSharedServices() -> array
    {
        return array_keys(this->sharedContainer);
    }

    /**
     * Gets the list of service definitions.
     *
     * @return array
     */
    public function getServices() -> array
    {
        return array_keys(this->container);
    }

    /**
     * Gets the list of parameters.
     *
     * @return array
     */
    public function getParams() -> array
    {
        return this->paramContainer;
    }
}
