
/**
 * PostgreSQL PDO Adapter
 *
 * Specific functions for the Postgresql database system
 *
 * <code>
 *   $connection = new \Pdm\Db\Adapter\Pdo\Pgsql($pdo);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db\Adapter\Pdo;

use Pdm\Db\Adapter\AbstractPdo;
use Pdm\Db\AdapterInterface;

class Pgsql extends AbstractPdo implements AdapterInterface
{
	/**
	 * @var string
	 */
	protected type = "pgsql" { get };

	/**
	 * @var string
	 */
	protected dialectType = "pgsql" { get };

	/**
	 * {@inheritDoc}
	 */
	public function supportSequences() -> boolean
	{
		return true;
	}
}
