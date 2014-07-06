
/**
 * Sqlite PDO Adapter
 *
 * Specific functions for the Sqlite database system
 *
 * <code>
 *   $connection = new \Pdm\Db\Adapter\Pdo\Sqlite($pdo);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db\Adapter\Pdo;

use Pdm\Db\Adapter\AbstractPdo;
use Pdm\Db\AdapterInterface;

class Sqlite extends AbstractPdo implements AdapterInterface
{
	/**
	 * @var string
	 */
	protected type = "sqlite" { get };

	/**
	 * @var string
	 */
	protected dialectType = "sqlite" { get };
}
