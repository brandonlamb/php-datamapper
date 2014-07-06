
/**
 * Pdm\Db\ResultInterface
 *
 * Interface for Pdm\Db\Result objects
 *
 * @package \Pdm\Db
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db;

interface ResultInterface
{
	/**
	 * Pdm\Db\Result\Pdo constructor
	 *
	 * @param Pdm\Db\AdapterInterface connection
	 * @param \PDOStatement pdoStatement
	 * @param string sqlStatement
	 * @param array bindParams
	 * @param array bindTypes
	 */
	//public function __construct(<\Pdm\Db\AdapterInterface> connection, string! result, sqlStatement = null, bindParams = null, bindTypes = null);
	public function __construct(<\Pdm\Db\AdapterInterface> adapter, <\PDOStatement> pdoStatement, string! sqlStatement = null, array bindParams = null, array bindTypes = null);

	/**
	 * Allows to executes the statement again. Some database systems don't support scrollable cursors,
	 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
	 *
	 * @return boolean
	 */
	public function execute() -> boolean;

	/**
	 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
	 *
	 * @return mixed
	 */
	public function $fetch();

	/**
	 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
	 *
	 * @return array | boolean
	 */
	public function fetchArray() -> array | boolean;

	/**
	 * Returns an array of arrays containing all the records in the result
	 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
	 *
	 * @return array
	 */
	public function fetchAll() -> array;

	/**
	 * Gets number of rows returned by a resulset
	 *
	 * @return int
	 */
	public function numRows() -> int;

	/**
	 * Changes the fetching mode affecting Pdm\Db\Result\Pdo::fetch()
	 *
	 * @param int fetchMode
	 */
	public function setFetchMode(int fetchMode) -> int;

	/**
	 * Gets the internal PDO result object
	 *
	 * @return \PDOStatement
	 */
	public function getInternalResult() -> <\PDOStatement>;
}
