
/**
 * Pdm\Db\Dialect\Db2
 *
 * Generates database specific SQL for the PostgreSQL RBDM
 */

namespace Pdm\Db\Dialect;

use Pdm\Db\AbstractDialect;
use Pdm\Db\DialectInterface;

class Db2 extends AbstractDialect implements DialectInterface
{
	protected escapeChar = "'";

	/**
	 * {@inheritDoc}
	 */
	public function limit(string! sqlQuery, int number) -> string
	{
		if is_numeric(number) {
			return sqlQuery . " FETCH FIRST " . number . " ROWS ONLY";
		}
		return sqlQuery;
	}

	/**
	 * {@inheritDoc}
	 */
	public function offset(string! sqlQuery, int number) -> string
	{
		return sqlQuery;
	}
}
