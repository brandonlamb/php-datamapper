
/**
 * Base DB class liberally borrowed from PhalconPHP
 *
 * @package \Pdm\Db
 * @author Andres Gutierrez <andres@phalconphp.com>
 * @author Eduar Carvajal <eduar@phalconphp.com>
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db;

use Pdm\Db\Adapter\Pdo as PdoAdapter;

abstract class AbstractDb
{
	/**
	 * Enables/disables options in the Database component
	 *
	 * @param array options
	 */
	public static function setup(var options) -> void
	{
		var escapeIdentifiers;

		if typeof options != "array" {
			throw new Exception("Options must be an array");
		}

		// Enables/Disables globally the escaping of SQL identifiers
		if fetch escapeIdentifiers, options["escapeSqlIdentifiers"] {
			globals_set("db.escape_identifiers", escapeIdentifiers);
		}
	}

	/**
	 * Adapter factory method
	 *
	 * @param string type
	 * @param \PDO pdo
	 * @return AdapterInterface
	 */
	public static function createAdapter(string! type, <\PDO> pdo) -> <\Pdm\Db\AdapterInterface>
	{
		var adapter;

		switch (type->lower()) {
			case "db2":
				let adapter = new PdoAdapter\Db2(pdo);
				break;

			case "ibm":
				let adapter = new PdoAdapter\Db2(pdo);
				break;

			case "mysql":
				let adapter = new PdoAdapter\Mysql(pdo);
				break;

			case "oci":
				let adapter = new PdoAdapter\Oracle(pdo);
				break;

			case "oracle":
				let adapter = new PdoAdapter\Oracle(pdo);
				break;

			case "pgsql":
				let adapter = new PdoAdapter\Pgsql(pdo);
				break;

			case "postgres":
				let adapter = new PdoAdapter\Pgsql(pdo);
				break;

			case "sqlite":
				let adapter = new PdoAdapter\Sqlite(pdo);

			default:
				throw new Exception("Unsupported database type '" . type . "'");
		}

		return adapter;
	}
}
