
/**
 * Pdm\Db\DialectInterface
 *
 * Interface for Pdm\Db dialects
 */

namespace Pdm\Db;

interface DialectInterface
{
	/**
	 * Gets escape character
	 *
	 * @return string
	 */
	public function getEscapeChar() -> string;

	/**
	 * Generates the SQL for LIMIT
	 *
	 * @param string sqlQuery
	 * @param int number
	 * @return string
	 */
	public function limit(string! sqlQuery, int number) -> string;

	/**
	 * Generates the SQL for OFFSET
	 *
	 * @param string sqlQuery
	 * @param int number
	 * @return string
	 */
	public function offset(string! sqlQuery, int number) -> string;

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 *
	 * @param string sqlQuery
	 * @return string
	 */
	public function forUpdate(sqlQuery) -> string;

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 *
	 * @param string sqlQuery
	 * @return string
	 */
	public function sharedLock(sqlQuery) -> string;

	/**
	 * Builds a SELECT statement
	 *
	 * @param array definition
	 * @return string
	 */
	public function select(definition) -> string;

	/**
	 * Gets a list of columns
	 *
	 * @param array columnList
	 * @return string
	 */
	public function getColumnList(columnList) -> string;

	/**
	 * Checks whether the platform supports savepoints
	 *
	 * @return boolean
	 */
	public function supportsSavepoints() -> boolean;

	/**
	 * Checks whether the platform supports releasing savepoints.
	 *
	 * @return boolean
	 */
	public function supportsReleaseSavepoints() -> boolean;

	/**
	 * Generate SQL to create a new savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function createSavepoint(name) -> string;

	/**
	 * Generate SQL to release a savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function releaseSavepoint(name) -> string;

	/**
	 * Generate SQL to rollback a savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function rollbackSavepoint(name) -> string;
}
