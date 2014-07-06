%{
#include <ext/pdo/php_pdo_driver.h>
}%

/**
 * Interface for PDO Adapter
 *
 * @package Pdm\Db
 */

namespace Pdm\Db;

/**
 * Pdm\Db\Adapter\Pdo\Mysql
 *
 * Interface for Pdm\Db adapters
 */

interface AdapterInterface
{
	/**
	 * Constructor for Pdm\Db\Adapter
	 *
	 * @param array descriptor
	 */
	public function __construct(descriptor);

	/**
	 * Returns the first row in a SQL query result
	 *
	 * @param string sqlStatement
	 * @param int fetchType
	 * @param array bindParams
	 * @param array bindTypes
	 * @return mixed
	 */
	public function fetchOne(string! sqlStatement, var fetchType = 2, var bindParams = [], var bindTypes = []);

	/**
	 * Dumps the complete result of a query into an array
	 *
	 * @param string sqlStatement
	 * @param int fetchType
	 * @param array bindParams
	 * @param array bindTypes
	 * @return array
	 */
	 public function fetchAll(string! sqlStatement, var fetchType = 2, var bindParams = [], var bindTypes = []) -> array;

	/**
	 * Inserts data into a table using custom RBDM SQL syntax
	 *
	 * @param string table
	 * @param array values
	 * @param array fields
	 * @param array dataTypes
	 * @return 	boolean
	 */
	public function insert(string! table, values, fields = null, dataTypes = null) -> boolean;

	/**
	 * Updates data on a table using custom RBDM SQL syntax
	 *
	 * @param string table
	 * @param array fields
	 * @param array values
	 * @param string whereCondition
	 * @param array dataTypes
	 * @return 	boolean
	 */
	public function update(string! table, fields, values, whereCondition = null, dataTypes = null) -> boolean;

	/**
	 * Deletes data from a table using custom RBDM SQL syntax
	 *
	 * @param string table
	 * @param string whereCondition
	 * @param array placeholders
	 * @param array dataTypes
	 * @return boolean
	 */
	public function delete(string! table, whereCondition = null, placeholders = null, dataTypes = null) -> boolean;

	/**
	 * Gets a list of columns
	 *
	 * @param array columnList
	 * @return string
	 */
	public function getColumnList(columnList) -> string;

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 *
	 * @param string sqlQuery
	 * @return string
	 */
	public function forUpdate(string! sqlQuery) -> string;

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 *
	 * @param string sqlQuery
	 * @return string
	 */
	public function sharedLock(string! sqlQuery) -> string;

	/**
	 * Gets the active connection unique identifier
	 *
	 * @return string
	 */
	public function getConnectionId() -> string;

	/**
	 * Active SQL statement in the object
	 *
	 * @return array
	 */
	public function getSQLVariables() -> array;

	/**
	 * Returns type of database system the adapter is used for
	 *
	 * @return string
	 */
	public function getType() -> string;

	/**
	 * Returns the name of the dialect used
	 *
	 * @return string
	 */
	public function getDialectType() -> string;

	/**
	 * Returns internal dialect instance
	 *
	 * @return Pdm\Db\DialectInterface
	 */
	public function getDialect() -> <\Pdm\Db\DialectInterface>;

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server return rows
	 *
	 * @param string sqlStatement
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Pdm\Db\ResultInterface|\PDOStatement|bool
	 * <\Pdm\Db\ResultInterface> | <\PDOStatement> | boolean
	 */
	public function query(string! sqlStatement, var bindParams = [], var bindTypes = []);

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server don't return any row
	 *
	 * @param string sqlStatement
	 * @param array placeholders
	 * @param array dataTypes
	 * @return boolean
	 */
	public function execute(string! sqlStatement, var bindParams = [], var bindTypes = []) -> boolean;

	/**
	 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
	 *
	 * @return int
	 */
	public function affectedRows() -> int;

	/**
	 * Closes active connection returning success. Pdm automatically closes and destroys active connections within Pdm\Db\Pool
	 *
	 * @return boolean
	 */
	public function close() -> boolean;

	/**
	 * Escapes a column/table/schema name
	 *
	 * @param string identifier
	 * @return string
	 */
	public function escapeIdentifier(string! identifier) -> string;

	/**
	 * Escapes a value to avoid SQL injections
	 *
	 * @param string str
	 * @return string
	 */
	public function escapeString(string! str) -> string;

	/**
	 * Returns insert id for the auto_increment column inserted in the last SQL statement
	 *
	 * @param string sequenceName
	 * @return int
	 */
	public function lastInsertId(string! sequenceName = null) -> int;

	/**
     * Starts a transaction in the connection
     *
     * @return boolean
     */
	public function begin(boolean nesting = true) -> boolean;

    /**
     * Rollbacks the active transaction in the connection
     *
     * @return boolean
     */
	public function rollback(boolean nesting = true) -> boolean;

    /**
     * Commits the active transaction in the connection
     *
     * @return boolean
     */
	public function commit(boolean nesting = true) -> boolean;

	/**
	 * Checks whether connection is under database transaction
	 *
	 * @return boolean
	 */
	public function isUnderTransaction() -> boolean;

	/**
	 * Return internal PDO handler
	 *
	 * @return \PDO
	 */
	public function getInternalHandler() -> <\PDO>;

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 *
	 * @return boolean
	 */
	public function useExplicitIdValue() -> boolean;

	/**
	 * Return the default identity value to insert in an identity column
	 *
	 * @return Pdm\Db\RawValue
	 */
	public function getDefaultIdValue() -> <\Pdm\Db\RawValue>;

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 *
	 * @return boolean
	 */
	public function supportSequences() -> boolean;

	/**
	 * Creates a new savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function createSavepoint(string! name) -> boolean;

	/**
	 * Releases given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function releaseSavepoint(string! name) -> boolean;

	/**
	 * Rollbacks given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function rollbackSavepoint(string! name) -> boolean;

	/**
	 * Set if nested transactions should use savepoints
	 *
	 * @param boolean nestedTransactionsWithSavepoints
	 * @return Pdm\Db\AdapterInterface
	 */
	public function setNestedTransactionsWithSavepoints(boolean nestedTransactionsWithSavepoints) -> <\Pdm\Db\AdapterInterface>;

	/**
	 * Returns if nested transactions should use savepoints
	 *
	 * @return boolean
	 */
	public function isNestedTransactionsWithSavepoints() -> boolean;

	/**
	 * Returns the savepoint name to use for nested transactions
	 *
	 * @return string
	 */
	public function getNestedTransactionSavepointName() -> string;
}
