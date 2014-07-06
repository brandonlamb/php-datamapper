/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Db;

/**
 * Retains query profiles.
 *
 * @package Pdm\Db
 */
class Profiler implements ProfilerInterface
{
    /**
     * Is the profiler active?
     *
     * @var bool
     */
    protected active = false;

    /**
     * Retained profiles.
     *
     * @var array
     */
    protected profiles = [];

    /**
     * Turns the profiler on and off.
     *
     * @param bool $active True to turn on, false to turn off.
     * @return ProfilerInterface
     */
    public function setActive(boolean! active) -> <\Pdm\Db\ProfilerInterface>
    {
        let this->active = active;
        return this;
    }

    /**
     * Is the profiler active?
     *
     * @return bool
     */
    public function isActive() -> boolean
    {
        return this->active;
    }

    /**
     * Adds a profile entry.
     *
     * @param float $duration The query duration.
     * @param string $functionName The PDO method that made the entry.
     * @param string $statement The SQL query statement.
     * @param array $bind_values The values bound to the statement.
     * @return ProfilerInterface
     */
    public function addProfile(var duration, string! functionName, string! statement, array bindValues = []) -> <\Pdm\Db\ProfilerInterface>
    {
        var e;

        if !this->isActive() {
            return this;
        }

        let e = new \Exception;
        let this->profiles[] = [
            "duration":     duration,
            "function":     functionName,
            "statement":    statement,
            "bindValues":   bindValues,
            "trace":        e->getTraceAsString()
        ];

        return this;
    }

    /**
     * Returns all the profile entries.
     *
     * @return array
     */
    public function getProfiles() -> array
    {
        return this->profiles;
    }
}
