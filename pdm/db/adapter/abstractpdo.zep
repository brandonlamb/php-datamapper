%{
#include <ext/pdo/php_pdo_driver.h>
}%

/**
 * Pdm\Db\Adapter\Pdo
 *
 * Pdm\Db\Adapter\Pdo is the Pdm\Db that internally uses Pdo to connect to a database
 *
 *<code>
 *	$connection = new \Pdm\Db\Adapter\Pdo\Mysql(array(
 *		'host' => '192.168.0.11',
 *		'username' => 'sigma',
 *		'password' => 'secret',
 *		'dbname' => 'blog',
 *		'port' => '3306'
 *	));
 *</code>
 */

namespace Pdm\Db\Adapter;

use Pdm\Db\AbstractAdapter;
use Pdm\Db\Column;
use Pdm\Db\ResultInterface;
use Pdm\Db\Result\Pdo as PdoResult;

abstract class AbstractPdo extends AbstractAdapter
{
	/**
	 * Pdo Handler
	 * @var \Pdo
	 */
	protected pdo;

	/**
	 * Last affected rows
	 * @var int
	 */
	protected affectedRows { get };

	/**
	 * Pdm\Db\Adapter constructor
	 *
	 * @param \PDO pdo
	 */
	public function __construct(<\PDO> pdo)
	{
		parent::__construct();

		if typeof pdo != "object" {
			throw new Exception("A resource of PDO must be passed");
		}

		let this->pdo = <\PDO> pdo;
		let this->affectedRows = 0;
	}

	/**
	 * Returns a PDO prepared statement to be executed with 'executePrepared'
	 *
	 * <code>
	 *   $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
	 *   $result = $connection->executePrepared($statement, ['name' => 'Voltron']);
	 * </code>
	 *
	 * @param string statement
	 * @return \PDOStatement
	 */
	public function prepare(string! statement) -> <\PDOStatement>
	{
		return this->pdo->prepare(statement);
	}

	/**
	 * Executes a prepared statement binding. This function uses integer indexes starting from zero
	 *
	 * <code>
	 *   $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
	 *   $result = $connection->executePrepared($statement, array('name' => 'Voltron'));
	 * </code>
	 *
	 * @param \PDOStatement statement
	 * @param array bindParams
	 * @param array bindTypes
	 * @return \PDOStatement
	 */
	public function executePrepared(<\PDOStatement> statement, var bindParams = [], var bindTypes = []) -> <\PDOStatement>
	{
		if typeof bindParams != "array" {
			let bindParams = [];
		}

		//this->bindStatmentParameters(statement, bindParams, bindTypes);
		statement->execute(bindParams);

		return statement;
	}

	protected function bindStatmentParameters(<\PDOStatement> statement, var bindParams = [], var bindTypes = []) -> <\PDOStatement>
	{
		var wildcard, value, parameter, type, castValue, hasBindParams, hasBindTypes;

		if typeof bindTypes != "array" {
			let bindTypes = [];
		}

		if count(bindParams) > 0 {
			let hasBindParams = true;
		} else {
			let hasBindParams = false;
		}

		if count(bindTypes) > 0 {
			let hasBindTypes = true;
		} else {
			let hasBindTypes = false;
		}

		for wildcard, value in bindParams {
			if typeof wildcard == "integer" {
				let parameter = wildcard + 1;
			} else {
				if typeof wildcard == "string" {
					let parameter = wildcard;
				} else {
					throw new Exception("Invalid bind parameter (1)");
				}
			}

			if hasBindParams && hasBindTypes {
				if !fetch type, bindTypes[wildcard] {
					let type = Column::BIND_PARAM_STR;
				}

				// The bind type is double so we try to get the double value
				if type == Column::BIND_PARAM_DECIMAL {
					let castValue = doubleval(value);
					let type = Column::BIND_SKIP;
				} else {
					let castValue = value;
				}

				// 1024 is ignore the bind type
				if type == Column::BIND_SKIP {
					statement->bindParam(parameter, castValue);
				} else {
					statement->bindParam(parameter, castValue, type);
				}
			} else {
				statement->bindParam(parameter, value, Column::BIND_PARAM_STR);
			}
		}

		return statement;
	}

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server is returning rows
	 *
	 * <code>
	 *   //Querying data
	 *   $resultset = $connection->query("SELECT * FROM robots WHERE type = 'mechanical'");
	 *   $resultset = $connection->query("SELECT * FROM robots WHERE type = ?", ["mechanical"]);
	 * </code>
	 *
	 * @param string sqlStatement
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Pdm\Db\ResultInterface|\PDO|bool
	 * <\Pdm\Db\ResultInterface> | <\PDOStatement> | boolean
	 */
	public function query(string! sqlStatement, var bindParams = [], var bindTypes = [])
	{
		//var eventsManager;
		var statement, result, affectedRows;

        if typeof bindParams == "array" && count(bindParams) > 0 {
            let statement = this->pdo->prepare(sqlStatement);
            if typeof statement == "object" {
            	let statement = this->executePrepared(statement, bindParams, bindTypes);
            }
        } else {
            let statement = this->pdo->query(sqlStatement);
        }

        // Execute the afterQuery event if a EventsManager is available
        if typeof statement == "object" {
            // if typeof eventsManager == "object" {
            //  eventsManager->fire("db:afterQuery", this, bindParams);
            // }

            if statement instanceof \PDOStatement {
				let affectedRows = statement->rowCount();

				// Execute the afterQuery event if an EventsManager is available
				if typeof affectedRows == "integer" {
					let this->affectedRows = affectedRows;
				}

                let result = new PdoResult(this, statement, sqlStatement, bindParams, bindTypes);
                return result;
            }
        }

        return statement;
	}

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server doesn't return any row
	 *
	 *<code>
	 *	//Inserting data
	 *	$success = $connection->execute("INSERT INTO robots VALUES (1, 'Astro Boy')");
	 *	$success = $connection->execute("INSERT INTO robots VALUES (?, ?)", array(1, 'Astro Boy'));
	 *</code>
	 *
	 * @param string sqlStatement
	 * @param array bindParams
	 * @param array bindTypes
	 * @return boolean
	 */
	public function execute(string! sqlStatement, var bindParams = [], var bindTypes = []) -> boolean
	{
		//var eventsManager;
		var affectedRows, newStatement, statement;

		// Execute the beforeQuery event if a EventsManager is available
		// let eventsManager = <\Pdm\Events\Manager> this->_eventsManager;
		// if typeof eventsManager == "object" {
		// 	let this->_sqlStatement = sqlStatement,
		// 		this->_sqlVariables = bindParams,
		// 		this->_sqlBindTypes = bindTypes;
		// 	if eventsManager->fire("db:beforeQuery", this, bindParams) === false {
		// 		return false;
		// 	}
		// }

		// Initialize affectedRows to 0
		let affectedRows = 0;

		if typeof bindParams == "array" {
			let statement = this->pdo->prepare(sqlStatement);
			if typeof statement == "object" {
				let newStatement = this->executePrepared(statement, bindParams, bindTypes);
				let affectedRows = newStatement->rowCount();
			}
		} else {
			let affectedRows = this->pdo->exec(sqlStatement);
		}

		// Execute the afterQuery event if an EventsManager is available
		if typeof affectedRows == "integer" {
			let this->affectedRows = affectedRows;
			// if typeof eventsManager == "object" {
			// 	eventsManager->fire("db:afterQuery", this, bindParams);
			// }
		}

		return true;
	}

	/**
	 * Returns the number of affected rows by the lastest INSERT/UPDATE/DELETE executed in the database system
	 *
	 *<code>
	 *	$connection->execute("DELETE FROM robots");
	 *	echo $connection->affectedRows(), ' were deleted';
	 *</code>
	 *
	 * @return int
	 */
	public function affectedRows() -> int
	{
		return this->affectedRows;
	}

	/**
	 * Closes the active connection returning success. Pdm automatically closes and destroys
	 * active connections when the request ends
	 *
	 * @return boolean
	 */
	public function close() -> boolean
	{
		var pdo;

		let pdo = <\PDO> this->pdo;
		if typeof pdo == "object" {
			let this->pdo = null;
			return true;
		}

		return false;
	}

	/**
	 * Escapes a column/table/schema name
	 *
	 *<code>
	 *	$escapedTable = $connection->escapeIdentifier('robots');
	 *	$escapedTable = $connection->escapeIdentifier(array('store', 'robots'));
	 *</code>
	 *
	 * @param string identifier
	 * @return string
	 */
	public function escapeIdentifier(var identifier) -> string
	{
		if typeof identifier == "array" {
			return "\"" . identifier[0] . "\".\"" . identifier[1] . "\"";
		}
		return "\"" . identifier . "\"";
	}

	/**
	 * Escapes a value to avoid SQL injections according to the active charset in the connection
	 *
	 *<code>
	 *	$escapedStr = $connection->escapeString('some dangerous value');
	 *</code>
	 *
	 * @param string str
	 * @return string
	 */
	public function escapeString(string! str) -> string
	{
		return this->pdo->quote(str);
	}

	/**
	 * Returns the insert id for the auto_increment/serial column inserted in the lastest executed SQL statement
	 *
	 *<code>
	 * //Inserting a new robot
	 * $success = $connection->insert(
	 *     "robots",
	 *     array("Astro Boy", 1952),
	 *     array("name", "year")
	 * );
	 *
	 * //Getting the generated id
	 * $id = $connection->lastInsertId();
	 *</code>
	 *
	 * @param string sequenceName
	 * @return int|boolean
	 */
	public function lastInsertId(sequenceName = null) -> int | boolean
	{
		return this->pdo->lastInsertId(sequenceName);
	}

	/**
	 * Starts a transaction in the connection
	 *
	 * @param boolean nesting
	 * @return boolean
	 */
	public function begin(boolean nesting = true) -> boolean
	{
		//var eventsManager;
		var transactionLevel;
		var savepointName;

		// Increase the transaction nesting level
		let this->transactionLevel++;

		// Check the transaction nesting level
		let transactionLevel = this->transactionLevel;

		if transactionLevel == 1 {
			// Notify the events manager about the started transaction
			// let eventsManager = <\Pdm\Events\Manager> this->_eventsManager;
			// if typeof eventsManager == "object" {
			// 	eventsManager->fire("db:beginTransaction", this);
			// }

			return this->pdo->beginTransaction();
		} else {
			if transactionLevel {
				if nesting {
					if this->isNestedTransactionsWithSavepoints() {
						let savepointName = this->getNestedTransactionSavepointName();

						// Notify the events manager about the created savepoint
						// let eventsManager = <\Pdm\Events\Manager> this->_eventsManager;
						// if typeof eventsManager == "object" {
						// 	eventsManager->fire("db:createSavepoint", this, savepointName);
						// }

						return this->createSavepoint(savepointName);
					}
				}
			}
		}

		return false;
	}

	/**
	 * Rollbacks the active transaction in the connection
	 *
	 * @param boolean nesting
	 * @return boolean
	 */
	public function rollback(boolean nesting = true) -> boolean
	{
		//var eventsManager;
		var  transactionLevel, savepointName;

		// Check the transaction nesting level
		let transactionLevel = this->transactionLevel;
		if !transactionLevel {
			throw new Exception("There is no active transaction");
		}

		if transactionLevel == 1 {
			// Notify the events manager about the rollbacked transaction
			// let eventsManager = <\Pdm\Events\Manager> this->_eventsManager;
			// if typeof eventsManager == "object" {
			// 	eventsManager->fire("db:rollbackTransaction", this);
			// }

			// Reduce the transaction nesting level
			let this->transactionLevel--;

			return this->pdo->rollback();
		} else {
			if transactionLevel {
				if nesting {
					if this->isNestedTransactionsWithSavepoints() {
						let savepointName = this->getNestedTransactionSavepointName();

						// Notify the events manager about the rolled back savepoint
						// let eventsManager = <\Pdm\Events\Manager> this->_eventsManager;
						// if typeof eventsManager == "object" {
						// 	eventsManager->fire("db:rollbackSavepoint", this, savepointName);
						// }

						// Reduce the transaction nesting level
						let this->transactionLevel--;

						return this->rollbackSavepoint(savepointName);
					}
				}
			}
		}

		// Reduce the transaction nesting level
		if transactionLevel > 0 {
			let this->transactionLevel--;
		}

		return false;
	}

	/**
	 * Commits the active transaction in the connection
	 *
	 * @param boolean nesting
	 * @return boolean
	 */
	public function commit(boolean nesting = true) -> boolean
	{
		//var eventsManager;
		var transactionLevel, savepointName;

		// Check the transaction nesting level
		let transactionLevel = this->transactionLevel;
		if !transactionLevel {
			throw new Exception("There is no active transaction");
		}

		if transactionLevel == 1 {
			// Notify the events manager about the commited transaction
			// let eventsManager = <\Pdm\Events\Manager> this->_eventsManager;
			// if typeof eventsManager == "object" {
			// 	eventsManager->fire("db:commitTransaction", this);
			// }

			// Reduce the transaction nesting level
			let this->transactionLevel--;

			return this->pdo->commit();
		} else {
			if transactionLevel {
				if nesting {
					// Check if the current database system supports nested transactions
					if this->isNestedTransactionsWithSavepoints() {
						let savepointName = this->getNestedTransactionSavepointName();

						// Notify the events manager about the committed savepoint
						// let eventsManager = <\Pdm\Events\Manager> this->_eventsManager;
						// if typeof eventsManager == "object" {
						// 	eventsManager->fire("db:releaseSavepoint", this, savepointName);
						// }

						// Reduce the transaction nesting level
						let this->transactionLevel--;

						return this->releaseSavepoint(savepointName);
					}
				}
			}
		}

		// Reduce the transaction nesting level
		if transactionLevel > 0 {
			let this->transactionLevel--;
		}

		return false;
	}

	/**
	 * Checks whether the connection is under a transaction
	 *
	 *<code>
	 *	$connection->begin();
	 *	var_dump($connection->isUnderTransaction()); //true
	 *</code>
	 *
	 * @return boolean
	 */
	public function isUnderTransaction() -> boolean
	{
		return this->pdo->inTransaction();
	}

	/**
	 * Return internal PDO handler
	 *
	 * @return \Pdo
	 */
	public function getInternalHandler() -> <\PDO>
	{
        if typeof this->pdo == "object" {
            return this->pdo;
        }
        throw new \Pdm\Db\Exception("Invalid PDO");
	}
}
