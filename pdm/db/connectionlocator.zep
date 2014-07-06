/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Db;

/**
 * Manages PDO connection objects for default, read, and write connections.
 *
 * @package Pdm\Db
 */
class ConnectionLocator implements ConnectionLocatorInterface
{
    /**
     * A registry of PDO connection entries.
     *
     * @var array
     */
    protected registry;

    /**
     * Whether or not registry entries have been converted to objects.
     *
     * @var array
     */
    protected converted;

    /**
     * Constructor.
     *
     * @param callable $defaultCallback A callable to create a default connection.
     * @param array $read An array of callables to create read connections.
     * @param array $write An array of callables to create write connections.
     */
    public function __construct(var defaultCallback = null, array read = [], array write = [])
    {
        var name, callback;

        let this->registry = [
            "default": null,
            "read": [],
            "write": []
        ];

        let this->converted = [
            "default": false,
            "read": [],
            "write": []
        ];

        if typeof defaultCallback != "null" {
            this->setDefault(defaultCallback);
        }

        for name, callback in read {
            this->setRead(name, callback);
        }

        for name, callback in write {
            this->setWrite(name, callback);
        }
    }

    /**
     * Sets the default connection registry entry.
     *
     * @param callable $callback The registry entry.
     * @return ConnnectionLocatorInterface
     */
    public function setDefault(var callback) -> <\Pdm\Db\ConnnectionLocatorInterface>
    {
        if typeof callback == "object" {
            if callback instanceof \Closure {
                let this->registry["default"] = callback;
                let this->converted["default"] = false;
                return this;
            }
        }

        throw new \Exception("Must pass a callable to " . __FUNCTION__);
    }

    /**
     * Returns the default connection object.
     *
     * @return PdoInterface
     */
    public function getDefault() -> <\Pdm\Db\PdoInterface>
    {
        var callback;

        if !this->converted["default"] {
            let callback = this->registry["default"];
            let this->registry["default"] = call_user_func(callback);
            let this->converted["default"] = true;
        }

        return this->registry["default"];
    }

    /**
     * Sets a read connection registry entry by name.
     *
     * @param string $name The name of the registry entry.
     * @param callable $callback The registry entry.
     * @return ConnnectionLocatorInterface
     */
    public function setRead(string! name, var callback) -> <\Pdm\Db\ConnnectionLocatorInterface>
    {
        var registry, converted;

        if typeof callback == "object" {
            if callback instanceof \Closure {
                let registry = this->registry["read"];
                let converted = this->converted["read"];

                let registry[name] = callback;
                let converted[name] = false;

                let this->registry["read"] = registry;
                let this->converted["read"] = converted;

                return this;
            }
        }

        return this;
    }

    /**
     * Returns a read connection by name; if no name is given, picks a
     * random connection; if no read connections are present, returns the
     * default connection.
     *
     * @param string $name The read connection name to return.
     * @return PdoInterface
     */
    public function getRead(string! name = null) -> <\Pdm\Db\PdoInterface>
    {
        return this->getConnection("read", name);
    }

    /**
     * Sets a write connection registry entry by name.
     *
     * @param string $name The name of the registry entry.
     * @param callable $callback The registry entry.
     * @return ConnnectionLocatorInterface
     *
     */
    public function setWrite(string! name, var callback) -> <\Pdm\Db\ConnnectionLocatorInterface>
    {
        var registry, converted;

        if typeof callback == "object" {
            if callback instanceof \Closure {
                let registry = this->registry["write"];
                let converted = this->converted["write"];

                let registry[name] = callback;
                let converted[name] = false;

                let this->registry["write"] = registry;
                let this->converted["write"] = converted;

                return this;
            }
        }

        return this;
    }

    /**
     * Returns a write connection by name; if no name is given, picks a
     * random connection; if no write connections are present, returns the
     * default connection.
     *
     * @param string $name The write connection name to return.
     * @return PdoInterface
     */
    public function getWrite(string! name = null) -> <\Pdm\Db\PdoInterface>
    {
        return this->getConnection("write", name);
    }

    /**
     * Returns a connection by name.
     *
     * @param string $type The connection type ("read" or "write").
     * @param string $name The name of the connection.
     * @return PdoInterface
     * @throws Exception\ConnectionNotFound
     */
    protected function getConnection(string! type, var name) -> <\Pdm\Db\PdoInterface>
    {
        var callback;

        if !this->registry[type] {
            return this->getDefault();
        }

        if name == "" {
            let name = array_rand(this->registry[type]);
        }

        if !isset this->registry[type][name] {
            throw new Exception\ConnectionNotFound(type . ":" . name);
        }

        if !this->converted[type][name] {
            let callback = this->registry[type][name];
            let this->registry[type][name] = call_user_func(callback);
            let this->converted[type][name] = true;
        }

        return this->registry[type][name];
    }
}
