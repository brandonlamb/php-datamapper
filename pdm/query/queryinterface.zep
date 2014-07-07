
/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Query;

/**
 * Interface for query objects.
 *
 * @package \Pdm\Query
 */
interface QueryInterface
{
    /**
     * Builds this query object into a string.
     *
     * @return string
     */
    public function __toString() -> string;

    /**
     * Adds values to bind into the query; merges with existing values.
     *
     * @param array bindValues Values to bind to the query.
     * @return QueryInterface
     */
    public function bindValues(var bindValues) -> <\Pdm\Query\QueryInterface>;

    /**
     * Binds a single value to the query.
     *
     * @param string $name The placeholder name or number.
     * @param mixed $value The value to bind to the placeholder.
     * @return QueryInterface
     *
     */
    public function bindValue(string! name, var value) -> <\Pdm\Query\QueryInterface>;

    /**
     * Gets the values to bind into the query.
     *
     * @return array
     */
    public function getBindValues() -> array;
}
