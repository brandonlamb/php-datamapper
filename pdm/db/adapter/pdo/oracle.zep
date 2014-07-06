
/**
 * Oracle PDO Adapter
 *
 * Specific functions for the Oracle database system
 *
 * <code>
 *   $connection = new \Phalcon\Db\Adapter\Pdo\Oracle($config);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db\Adapter\Pdo;

use Pdm\Db\Adapter\AbstractPdo;
use Pdm\Db\AdapterInterface;

class Oracle extends AbstractPdo implements AdapterInterface
{
	/**
	 * @var string
	 */
	protected type = "oci" { get };

	/**
	 * @var string
	 */
	protected dialectType = "oracle" { get };
}
