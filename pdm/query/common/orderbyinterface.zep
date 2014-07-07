
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
 * An interface for ORDER BY clauses.
 *
 * @package \Pdm\Query
 *
 */
interface OrderByInterface
{
    /**
     *
     * Adds a column order to the query.
     *
     * @param array $spec The columns and direction to order by.
     *
     * @return OrderByInterface
     *
     */
    public function orderBy(var spec) -> <\Pdm\Query\Common\OrderByInterface>;
}
