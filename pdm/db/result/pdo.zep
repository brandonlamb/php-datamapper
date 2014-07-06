%{
#include <ext/pdo/php_pdo_driver.h>
}%

/**
 * Pdm\Db\Result\Pdo
 *
 * Encapsulates the resultset internals
 *
 * <code>
 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(PDO::FETCH_NUM);
 *	while ($robot = $result->fetchArray()) {
 *		print_r($robot);
 *	}
 * </code>
 */

namespace Pdm\Db\Result;

use Pdm\Db\ResultInterface;

class Pdo implements ResultInterface
{
	/**
	 * @var \Pdm\Db\AdapterInterface
	 */
	protected adapter;

	/**
	 * Active fetch mode
	 * @var int
	 */
	protected fetchMode { get };

	/**
	 * Internal resultset
	 *
	 * @var \PDOStatement
	 */
	protected pdoStatement;

	/**
	 * SQL statement
	 * @var string
	 */
	protected sqlStatement { get };

	/**
	 * Bound parameters array
	 * @var array
	 */
	protected bindParams;

	protected bindTypes;

	protected rowCount;

	/**
	 * Pdm\Db\Result\Pdo constructor
	 *
	 * @param Pdm\Db\AdapterInterface adapter
	 * @param \PDOStatement pdoStatement
	 * @param string sqlStatement
	 * @param array bindParams
	 * @param array bindTypes
	 */
	public function __construct(
		<\Pdm\Db\AdapterInterface> adapter,
		<\PDOStatement> pdoStatement,
		string! sqlStatement = null,
		var bindParams = [],
		var bindTypes = []
	)
	{
		let this->fetchMode = 4;
		let this->rowCount = false;
		let this->adapter = adapter;
		let this->pdoStatement = pdoStatement;

		if typeof sqlStatement != "null" {
			let this->sqlStatement = sqlStatement;
		}
		if typeof bindParams != "null" {
			let this->bindParams = bindParams;
		}
		if typeof bindTypes != "null" {
			let this->bindTypes = bindTypes;
		}
	}

	/**
	 * Allows to execute the statement again. Some database systems don't support scrollable cursors,
	 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
	 *
	 * @return boolean
	 */
	public function execute() -> boolean
	{
		return this->getInternalResult()->execute();
	}

	/**
	 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
	 *
	 *<code>
	 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
	 *	$result->setFetchMode(PDO::FETCH_OBJ);
	 *	while ($robot = $result->fetch()) {
	 *		echo robot->name;
	 *	}
	 *</code>
	 *
	 * @return mixed
	 */
	public function $fetch()
	{
		return this->getInternalResult()->$fetch();
	}

	/**
	 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
	 *
	 *<code>
	 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
	 *	$result->setFetchMode(PDO::FETCH_NUM);
	 *	while ($robot = result->fetchArray()) {
	 *		print_r($robot);
	 *	}
	 *</code>
	 *
	 * @return array | bool
	 */
	public function fetchArray() -> array | boolean
	{
		return this->getInternalResult()->$fetch();
	}

	/**
	 * Returns an array of arrays containing all the records in the result
	 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
	 *
	 *<code>
	 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
	 *	$robots = $result->fetchAll();
	 *</code>
	 *
	 * @return array
	 */
	public function fetchAll() -> array | boolean
	{
		return this->getInternalResult()->fetchAll();
	}

	/**
	 * Gets number of rows returned by a resulset
	 *
	 *<code>
	 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
	 *	echo 'There are ', $result->numRows(), ' rows in the resulset';
	 *</code>
	 *
	 * @return int
	 */
	public function numRows() -> int
	{
		var sqlStatement, rowCount, adapter, type, pdoStatement, matches, result, row;

		let rowCount = this->rowCount;

		if rowCount === false {
			let adapter = this->adapter;
			let type = adapter->getType();

			// MySQL library properly returns the number of records PostgreSQL too
			if type == "pgsql" || type == "mysql" {
				let pdoStatement = this->pdoStatement;
				let rowCount = pdoStatement->rowCount();
			}

			// We should get the count using a new statement :(
			if rowCount === false {
				// SQLite/Oracle/SQLServer returns resultsets that to the client eyes (PDO) has an arbitrary number of rows, so we need to perform an extra count to know that
				let sqlStatement = this->sqlStatement;

				// If the sql_statement starts with SELECT COUNT(*) we don't make the count
				if !starts_with(sqlStatement, "SELECT COUNT(*) ") {
					let matches = null;
					if preg_match("/^SELECT\\s+(.*)/i", sqlStatement, matches) {
						let result = adapter->query("SELECT COUNT(*) \"numrows\" FROM (SELECT " . matches[1] . ")", this->bindParams, this->bindTypes);
						let row = result->$fetch();
						let rowCount = row["numrows"];
					}
				} else {
					let rowCount = 1;
				}
			}

			// Update the value to avoid further calculations
			let this->rowCount = rowCount;
		}
		return rowCount;
	}

	/**
	 * Changes the fetching mode affecting Pdm\Db\Result\Pdo::fetch()
	 *
	 *<code>
	 *	//Return array with integer indexes
	 *	$result->setFetchMode(PDO::FETCH_NUM);
	 *
	 *	//Return associative array without integer indexes
	 *	$result->setFetchMode(PDO::FETCH_ASSOC);
	 *
	 *	//Return associative array together with integer indexes
	 *	$result->setFetchMode(PDO::FETCH_BOTH);
	 *
	 *	//Return an object
	 *	$result->setFetchMode(PDO::FETCH_OBJ);
	 *</code>
	 *
	 * @param int fetchMode
	 */
	public function setFetchMode(var fetchMode) -> void
	{
		if typeof fetchMode != "integer" {
			let fetchMode = (int) fetchMode;
		}

		switch (fetchMode) {
			case \PDO::FETCH_BOTH:
				break;

			case \PDO::FETCH_ASSOC:
				break;

			case \PDO::FETCH_NUM:
				break;

			case \PDO::FETCH_OBJ:
				break;

			default:
				let fetchMode = (string) fetchMode;
				throw new \Pdm\Db\Exception("Unsupported fetch mode '" . fetchMode . "'");
		}

		let this->fetchMode = fetchMode;
		this->getInternalResult()->setFetchMode(fetchMode);
	}

	/**
	 * Gets the internal PDO result object
	 *
	 * @return \PDOStatement
	 */
	public function getInternalResult() -> <\PDOStatement>
	{
		if unlikely !(this->pdoStatement instanceof \PDOStatement) {
			throw new \Pdm\Db\Exception("Invalid PDOStatement");
		}
		return this->pdoStatement;
	}
}
