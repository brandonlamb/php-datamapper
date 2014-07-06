
/**
 * Pdm\Db\Dialect\Oracle
 *
 * Generates database specific SQL for the Oracle RBDM
 */

namespace Pdm\Db\Dialect;

use Pdm\Db\AbstractDialect;
use Pdm\Db\DialectInterface;

class Oracle extends AbstractDialect implements DialectInterface
{
	protected escapeChar = "";
}
