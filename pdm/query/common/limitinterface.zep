
/**
 *
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 *
 */
namespace Pdm\Query\Common;

/**
 *
 * An interface for LIMIT clauses.
 *
 * @package \Pdm\Query
 *
 */
interface LimitInterface
{
    /**
     *
     * Sets a limit count on the query.
     *
     * @param int $limit The number of rows to select.
     *
     * @return LimitInterface
     *
     */
    public function limit(int limit) -> <\Pdm\Query\Common\LimitInterface>;
}
