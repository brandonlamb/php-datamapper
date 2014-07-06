/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Db;

/**
 * Locates PDO connections for default, read, and write databases.
 *
 * @package Pdm\Db
 */
interface ConnectionLocatorInterface
{
    /**
     * Sets the default connection registry entry.
     *
     * @param callable $callback The registry entry.
     * @return void
     *
     */
    public function setDefault(var callback) -> void;

    /**
     * Returns the default connection object.
     *
     * @return PdoInterface
     */
    public function getDefault() -> <\Pdm\Db\PdoInterface>;

    /**
     * Sets a read connection registry entry by name.
     *
     * @param string $name The name of the registry entry.
     * @param callable $callback The registry entry.
     * @return void
     */
    public function setRead(string! name, var callback) -> void;

    /**
     * Returns a read connection by name; if no name is given, picks a
     * random connection; if no read connections are present, returns the
     * default connection.
     *
     * @param string $name The read connection name to return.
     * @return PdoInterface
     */
    public function getRead(string! name = null) -> <\Pdm\Db\PdoInterface>;

    /**
     * Sets a write connection registry entry by name.
     *
     * @param string $name The name of the registry entry.
     * @param callable $callback The registry entry.
     * @return void
     */
    public function setWrite(string! name, var callback) -> void;

    /**
     * Returns a write connection by name; if no name is given, picks a
     * random connection; if no write connections are present, returns the
     * default connection.
     *
     * @param string $name The write connection name to return.
     * @return PdoInterface
     */
    public function getWrite(string! name = null) -> <\Pdm\Db\PdoInterface>;
}
