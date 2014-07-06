
/**
 * Pdm\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RBDM
 */

namespace Pdm\Db\Dialect;

use Pdm\Db\AbstractDialect;
use Pdm\Db\DialectInterface;

class Sqlite extends AbstractDialect implements DialectInterface
{
	protected escapeChar = "\"";
}
