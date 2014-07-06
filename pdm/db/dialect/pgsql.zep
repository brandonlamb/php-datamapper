
/**
 * Pdm\Db\Dialect\Pgsql
 *
 * Generates database specific SQL for the PostgreSQL RBDM
 */

namespace Pdm\Db\Dialect;

use Pdm\Db\AbstractDialect;
use Pdm\Db\DialectInterface;

class Pgsql extends AbstractDialect implements DialectInterface
{
	protected escapeChar = "\"";
}
