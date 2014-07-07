
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
 * An interface for LIMIT...OFFSET clauses.
 *
 * @package \Pdm\Query
 *
 */
interface LimitOffsetInterface extends LimitInterface
{
    /**
     *
     * Sets a limit offset on the query.
     *
     * @param int $offset Start returning after this many rows.
     *
     * @return LimitOffsetInterface
     *
     */
    public function offset(int offset) -> <\Pdm\Query\Common\LimitOffsetInterface>;
}
