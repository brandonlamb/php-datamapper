
/**
 * Mysql PDO Adapter
 *
 * Specific functions for the Mysql database system
 *
 * <code>
 *   $connection = new \Pdm\Db\Adapter\Pdo\Mysql($pdo);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db\Adapter\Pdo;

use Pdm\Db\Adapter\AbstractPdo;
use Pdm\Db\AdapterInterface;

class Mysql extends AbstractPdo implements AdapterInterface
{
	/**
	 * @var string
	 */
	protected type = "mysql" { get };

	/**
	 * @var string
	 */
	protected dialectType = "mysql" { get };

	/**
	 * Escapes a column/table/schema name
	 *
	 * @param string|array identifier
	 * @return string
	 */
	public function escapeIdentifier(var identifier) -> string
	{
		var domain, name;

		if typeof identifier == "array" {
			let domain = identifier[0],
				name = identifier[1];
			if globals_get("db.escape_identifiers") {
				return "`" . domain . "`.`" . name . "`";
			}
			return domain . "." . name;
		}

		if globals_get("db.escape_identifiers") {
			return "`" . identifier . "`";
		}

		return identifier;
	}
}
