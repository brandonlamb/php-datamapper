%{
#include <ext/pdo/php_pdo_driver.h>
}%

/**
 * Pdm\Db\Adapter
 *
 * Base class for Pdm\Db adapters
 */

namespace Pdm\Db;

abstract class AbstractAdapter
	// implements \Pdm\Events\EventsAwareInterface
{
	/**
	 * Event Manager
	 *
	 * @var Pdm\Events\Manager
	 */
	protected eventsManager;

	/**
	 * Type of database system the adapter is used for
	 */
	protected type { get };

	/**
	 * Name of the dialect used
	 */
	protected dialectType { get };

	/**
	 * Dialect instance
	 */
	protected dialect;

	/**
	 * Active connection ID
	 *
	 * @var long
	 */
	protected connectionId { get };

	/**
	 * Active SQL Statement
	 *
	 * @var string
	 */
	protected sqlStatement { get };

	/**
	 * Active SQL bound parameter variables
	 *
	 * @var string
	 */
	protected sqlVariables { get };

	/**
	 * Active SQL Bind Types
	 *
	 * @var string
	 */
	protected sqlBindTypes;

	/**
	 * @var int
	 */
	protected transactionLevel { get };

	/**
	 * @var bool
	 */
	protected transactionsWithSavepoints { get };

	/**
	 * Connection ID
	 */
	protected static _connectionConsecutive = 0;

	/**
	 * Pdm\Db\Adapter constructor
	 */
	public function __construct()
	{
		var dialectClass;
		let dialectClass = "\\Pdm\\Db\\Dialect\\" . this->getDialectType();

		let this->connectionId = 0;
		let this->transactionLevel = 0;
		let this->transactionsWithSavepoints = false;
		let this->dialect = new {dialectClass}();
	}

	/**
	 * Sets the event manager
	 *
	 * @param Pdm\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<\Pdm\Events\ManagerInterface> eventsManager) -> void
	{
		let this->eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Pdm\Events\ManagerInterface
	 */
	public function getEventsManager() -> <\Pdm\Events\ManagerInterface>
	{
		return this->eventsManager;
	}

	/**
	 * Sets the dialect used to produce the SQL
	 *
	 * @param Pdm\Db\DialectInterface
	 */
	public function setDialect(<\Pdm\Db\DialectInterface> dialect) -> void
	{
		let this->dialect = dialect;
	}

	/**
	 * Returns internal dialect instance
	 *
	 * @return Pdm\Db\DialectInterface
	 */
	public function getDialect() -> <\Pdm\Db\DialectInterface>
	{
		return this->dialect;
	}

	/**
	 * Returns the first row in a SQL query result
	 *
	 *<code>
	 *	//Getting first robot
	 *	$robot = $connection->fecthOne("SELECT * FROM robots");
	 *	print_r($robot);
	 *
	 *	//Getting first robot with associative indexes only
	 *	$robot = $connection->fecthOne("SELECT * FROM robots", PDO::FETCH_ASSOC);
	 *	print_r($robot);
	 *</code>
	 *
	 * @param string sqlStatement
	 * @param int fetchType
	 * @param array bindParams
	 * @param array bindTypes
	 * @return mixed
	 */
	public function fetchOne(string! sqlStatement, var fetchType = 2, var bindParams = [], var bindTypes = [])
	{
		var result;

		let result = call_user_func([this, "query"], sqlStatement, bindParams, bindTypes);

		if typeof result == "object" {
			result->setFetchMode(fetchType);
			return result->$fetch();
		}

		return [];
	}

	/**
	 * Dumps the complete result of a query into an array
	 *
	 *<code>
	 *	//Getting all robots with associative indexes only
	 *	$robots = $connection->fetchAll("SELECT * FROM robots", PDO::FETCH_ASSOC);
	 *	foreach ($robots as $robot) {
	 *		print_r($robot);
	 *	}
	 *
	 *  //Getting all robots that contains word "robot" withing the name
	 *  $robots = $connection->fetchAll("SELECT * FROM robots WHERE name LIKE :name",
	 *		PDO::FETCH_ASSOC,
	 *		array('name' => '%robot%')
	 *  );
	 *	foreach($robots as $robot){
	 *		print_r($robot);
	 *	}
	 *</code>
	 *
	 * @param string sqlStatement
	 * @param int fetchType
	 * @param array bindParams
	 * @param array bindTypes
	 * @return array
	 */
	public function fetchAll(string! sqlStatement, var fetchType = 2, var bindParams = [], var bindTypes = []) -> array
	{
		var results, result, row;

		let results = [];
		let result = call_user_func([this, "query"], sqlStatement, bindParams, bindTypes);

		if typeof result == "object" {
			result->setFetchMode(fetchType);

			loop {
				let row = result->$fetch();
				if !row {
					break;
				}
				let results[] = row;
			}
		}

		return results;
	}

	/**
	 * Inserts data into a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Inserting a new robot
	 * $success = $connection->insert(
	 *     "robots",
	 *     array("Astro Boy", 1952),
	 *     array("name", "year")
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
	 * </code>
	 *
	 * @param string|array table
	 * @param array values
	 * @param array fields
	 * @param array dataTypes
	 * @return 	boolean
	 */
	public function insert(var table, var values, var fields = null, var dataTypes = null) -> boolean
	{
		var placeholders, insertValues, bindDataTypes, bindType,
			position, value, escapedTable, joinedValues, escapedFields,
			field, insertSql;

		if typeof values != "array" {
			throw new Exception("The second parameter for insert isn't an Array");
		}

		// A valid array with more than one element is required
		if !count(values) {
			throw new Exception("Unable to insert into " . table . " without data");
		}

		let placeholders = [];
		let insertValues = [];

		if typeof dataTypes != "array" {
			let bindDataTypes = [];
		} else {
			let bindDataTypes = dataTypes;
		}

		// Objects are casted using __toString, null values are converted to string "null", everything else is passed as "?"
		for position, value in values {
			if typeof value == "object" {
				let placeholders[] = (string) value;
			} else {
				if typeof value == "null" {
					let placeholders[] = "null";
				} else {
					let placeholders[] = "?";
					let insertValues[] = value;
					if typeof dataTypes == "array" {
						if !fetch bindType, dataTypes[position] {
							throw new Exception("Incomplete number of bind types");
						}
						let bindDataTypes[] = bindType;
					}
				}
			}
		}

		if globals_get("db.escape_identifiers") {
			let escapedTable = this->{"escapeIdentifier"}(table);
		} else {
			let escapedTable = table;
		}

		// Build the final SQL INSERT statement
		let joinedValues = join(", ", placeholders);

		if typeof fields == "array" {
			if globals_get("db.escape_identifiers") {
				let escapedFields = [];
				for field in fields {
					let escapedFields[] = this->{"escapeIdentifier"}(field);
				}
			} else {
				let escapedFields = fields;
			}

			let insertSql = "INSERT INTO " . escapedTable . " (" . join(", ", escapedFields) . ") VALUES (" . joinedValues . ")";
		} else {
			let insertSql = "INSERT INTO " . escapedTable . " VALUES (" . joinedValues . ")";
		}

		// Perform the execution via PDO::execute
		if !count(bindDataTypes) {
			return this->{"execute"}(insertSql, insertValues);
		}

		return this->{"execute"}(insertSql, insertValues, bindDataTypes);
	}

	/**
	 * Updates data on a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Updating existing robot
	 * $success = $connection->update(
	 *     "robots",
	 *     array("name"),
	 *     array("New Astro Boy"),
	 *     "id = 101"
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
	 * </code>
	 *
	 * @param string|array table
	 * @param array fields
	 * @param array values
	 * @param string whereCondition
	 * @param array dataTypes
	 * @return 	boolean
	 */
	public function update(var table, fields, values, whereCondition = null, dataTypes = null) -> boolean
	{
		var placeholders, updateValues, position, value,
			field, bindDataTypes, escapedField, bindType, escapedTable,
			setClause, updateSql, conditions, whereBind, whereTypes;

		let placeholders = [];
		let updateValues = [];

		if typeof dataTypes == "array" {
			let bindDataTypes = [];
		} else {
			let bindDataTypes = dataTypes;
		}

		// Objects are casted using __toString, null values are converted to string 'null', everything else is passed as '?'
		for position, value in values {
			if !fetch field, fields[position] {
				throw new Exception("The number of values in the update is not the same as fields");
			}

			if globals_get("db.escape_identifiers") {
				let escapedField = this->{"escapeIdentifier"}(field);
			} else {
				let escapedField = field;
			}

			if typeof value == "object" {
				let placeholders[] = escapedField . " = " . value;
			} else {
				if typeof value == "null" {
					let placeholders[] = escapedField . " = null";
				} else {
					let updateValues[] = value;
					if typeof dataTypes == "array" {
						if !fetch bindType, dataTypes[position] {
							throw new Exception("Incomplete number of bind types");
						}
						let bindDataTypes[] = bindType;
					}
					let placeholders[] = escapedField . " = ?";
				}
			}
		}

		if globals_get("db.escape_identifiers") {
			let escapedTable = this->{"escapeIdentifier"}(table);
		} else {
			let escapedTable = table;
		}

		let setClause = join(", ", placeholders);

		if whereCondition !== null {
			let updateSql = "UPDATE " . escapedTable . " SET " . setClause . " WHERE ";

			// String conditions are simply appended to the SQL
			if typeof whereCondition == "string" {
				let updateSql .= whereCondition;
			} else {
				// Array conditions may have bound params and bound types
				if typeof whereCondition != "array" {
					throw new Exception("Invalid WHERE clause conditions");
				}

				// If an index 'conditions' is present it contains string where conditions that are appended to the UPDATE sql
				if fetch conditions, whereCondition["conditions"] {
					let updateSql .= conditions;
				}

				// Bound parameters are arbitrary values that are passed by separate
				if fetch whereBind, whereCondition["bind"] {
					merge_append(updateValues, whereBind);
				}

				// Bind types is how the bound parameters must be casted before be sent to the database system
				if fetch whereTypes, whereCondition["bindTypes"] {
					merge_append(bindDataTypes, whereTypes);
				}
			}
		} else {
			let updateSql = "UPDATE " . escapedTable . " SET " . setClause;
		}

		// Perform the update via PDO::execute
		if !count(bindDataTypes) {
			return this->{"execute"}(updateSql, updateValues);
		}

		return this->{"execute"}(updateSql, updateValues, bindDataTypes);
	}

	/**
	 * Deletes data from a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Deleting existing robot
	 * $success = $connection->delete(
	 *     "robots",
	 *     "id = 101"
	 * );
	 *
	 * //Next SQL sentence is generated
	 * DELETE FROM `robots` WHERE `id` = 101
	 * </code>
	 *
	 * @param string table
	 * @param string whereCondition
	 * @param array placeholders
	 * @param array dataTypes
	 * @return boolean
	 */
	public function delete(string! table, whereCondition = null, placeholders = null, dataTypes = null) -> boolean
	{
		var sql, escapedTable;

		if globals_get("db.escape_identifiers") {
			let escapedTable = this->{"escapeIdentifier"}(table);
		} else {
			let escapedTable = table;
		}

		if !empty whereCondition {
			let sql = "DELETE FROM " . escapedTable . " WHERE " . whereCondition;
		} else {
			let sql = "DELETE FROM " . escapedTable;
		}

		// Perform the update via PDO::execute
		return this->{"execute"}(sql, placeholders, dataTypes);
	}

	/**
	 * Gets a list of columns
	 *
	 * @param array columnList
	 * @return	string
	 */
	public function getColumnList(var columnList) -> string
	{
		return this->dialect->getColumnList(columnList);
	}

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 *
	 * @param string sqlQuery
	 * @return	string
	 */
	public function forUpdate(string! sqlQuery) -> string
	{
		return this->dialect->forUpdate(sqlQuery);
	}

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 *
	 * @param string sqlQuery
	 * @return	string
	 */
	public function sharedLock(string! sqlQuery) -> string
	{
		return this->dialect->sharedLock(sqlQuery);
	}

	/**
	 * Returns the SQL column definition from a column
	 *
	 * @param Pdm\Db\ColumnInterface column
	 * @return	string
	 */
	public function getColumnDefinition(<\Pdm\Db\ColumnInterface> column) -> boolean
	{
		return this->dialect->getColumnDefinition(column);
	}

	/**
	 * Creates a new savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function createSavepoint(string! name) -> boolean
	{
		var dialect;

		let dialect = this->dialect;

		if !dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter.");
		}

		return this->{"execute"}(dialect->createSavepoint(name));
	}

	/**
	 * Releases given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function releaseSavepoint(string! name) -> boolean
	{
		var dialect;

		let dialect = this->dialect;

		if !dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter");
		}

		if dialect->supportsReleaseSavePoints() {
			return false;
		}

		return this->{"execute"}(dialect->releaseSavepoint(name));
	}

	/**
	 * Rollbacks given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function rollbackSavepoint(string! name) -> boolean
	{
		var dialect;

		let dialect = this->dialect;

		if !dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter");
		}

		return this->{"execute"}(dialect->rollbackSavepoint(name));
	}

	/**
	 * Set if nested transactions should use savepoints
	 *
	 * @param boolean nestedTransactionsWithSavepoints
	 * @return Pdm\Db\AdapterInterface
	 */
	public function setNestedTransactionsWithSavepoints(boolean nestedTransactionsWithSavepoints) -> <\Pdm\Db\AdapterInterface>
	{
		if this->transactionLevel > 0 {
			throw new Exception("Nested transaction with savepoints behavior cannot be changed while a transaction is open");
		}

		if !this->dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter");
		}

		let this->transactionsWithSavepoints = nestedTransactionsWithSavepoints;

		return this;
	}

	/**
	 * Returns if nested transactions should use savepoints
	 *
	 * @return boolean
	 */
	public function isNestedTransactionsWithSavepoints() -> boolean
	{
		return this->transactionsWithSavepoints;
	}

	/**
	 * Returns the savepoint name to use for nested transactions
	 *
	 * @return string
	 */
	public function getNestedTransactionSavepointName() -> string
	{
		return "Pdm_SAVEPOINT_" . this->transactionLevel;
	}

	/**
	 * Returns the default identity value to be inserted in an identity column
	 *
	 *<code>
	 * //Inserting a new robot with a valid default value for the column 'id'
	 * $success = $connection->insert(
	 *     "robots",
	 *     array($connection->getDefaultIdValue(), "Astro Boy", 1952),
	 *     array("id", "name", "year")
	 * );
	 *</code>
	 *
	 * @return Pdm\Db\RawValue
	 */
	public function getDefaultIdValue() -> <\Pdm\Db\RawValue>
	{
		var rawValue;
		let rawValue = new \Pdm\Db\RawValue("null");
		return rawValue;
	}

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 *
	 * @return boolean
	 */
	public function supportSequences() -> boolean
	{
		return false;
	}

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 *
	 * @return boolean
	 */
	public function useExplicitIdValue() -> boolean
	{
		return false;
	}
}
