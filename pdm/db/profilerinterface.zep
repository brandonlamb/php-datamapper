/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Db;

/**
 * Interface for query profilers.
 *
 * @package Pdm\Db
 */
interface ProfilerInterface
{
    /**
     * Turns the profiler on and off.
     *
     * @param bool $active True to turn on, false to turn off.
     * @return void
     */
    public function setActive(boolean! active) -> void;

    /**
     * Is the profiler active?
     *
     * @return bool
     */
    public function isActive() -> boolean;

    /**
     * Adds a profile entry.
     *
     * @param float $duration The query duration.
     * @param string $functionName The PDO method that made the entry.
     * @param string $statement The SQL query statement.
     * @param array $bind_values The values bound to the statement.
     * @return void
     */
    public function addProfile(var duration, string! functionName, string! statement, array bindValues);

    /**
     * Returns all the profiles.
     *
     * @return array
     */
    public function getProfiles() -> array;
}
