
/**
 * Pdm\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */

namespace Pdm\Db\Dialect;

use Pdm\Db\AbstractDialect;
use Pdm\Db\DialectInterface;

class MySQL extends AbstractDialect implements DialectInterface
{
	protected escapeChar = "`";
}
