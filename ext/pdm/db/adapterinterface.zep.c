
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"

#include <ext/pdo/php_pdo_driver.h>



/**
 * Interface for PDO Adapter
 *
 * @package Pdm\Db
 */
/**
 * Pdm\Db\Adapter\Pdo\Mysql
 *
 * Interface for Pdm\Db adapters
 */
ZEPHIR_INIT_CLASS(Pdm_Db_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Db, AdapterInterface, pdm, db_adapterinterface, pdm_db_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Constructor for Pdm\Db\Adapter
 *
 * @param array descriptor
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, __construct);

/**
 * Returns the first row in a SQL query result
 *
 * @param string sqlStatement
 * @param int fetchType
 * @param array bindParams
 * @param array bindTypes
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, fetchOne);

/**
 * Dumps the complete result of a query into an array
 *
 * @param string sqlStatement
 * @param int fetchType
 * @param array bindParams
 * @param array bindTypes
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, fetchAll);

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * @param string table
 * @param array values
 * @param array fields
 * @param array dataTypes
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, insert);

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
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, update);

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * @param string table
 * @param string whereCondition
 * @param array placeholders
 * @param array dataTypes
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, delete);

/**
 * Gets a list of columns
 *
 * @param array columnList
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getColumnList);

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string sqlQuery
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, forUpdate);

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string sqlQuery
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, sharedLock);

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getConnectionId);

/**
 * Active SQL statement in the object
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getSQLVariables);

/**
 * Returns type of database system the adapter is used for
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getType);

/**
 * Returns the name of the dialect used
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getDialectType);

/**
 * Returns internal dialect instance
 *
 * @return Pdm\Db\DialectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getDialect);

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
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, query);

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server don't return any row
 *
 * @param string sqlStatement
 * @param array placeholders
 * @param array dataTypes
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, execute);

/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, affectedRows);

/**
 * Closes active connection returning success. Pdm automatically closes and destroys active connections within Pdm\Db\Pool
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, close);

/**
 * Escapes a column/table/schema name
 *
 * @param string identifier
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, escapeIdentifier);

/**
 * Escapes a value to avoid SQL injections
 *
 * @param string str
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, escapeString);

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string sequenceName
 * @return int
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, lastInsertId);

/**
 * Starts a transaction in the connection
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, begin);

/**
 * Rollbacks the active transaction in the connection
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, rollback);

/**
 * Commits the active transaction in the connection
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, commit);

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, isUnderTransaction);

/**
 * Return internal PDO handler
 *
 * @return \PDO
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getInternalHandler);

/**
 * Check whether the database system requires an explicit value for identity columns
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, useExplicitIdValue);

/**
 * Return the default identity value to insert in an identity column
 *
 * @return Pdm\Db\RawValue
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getDefaultIdValue);

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, supportSequences);

/**
 * Creates a new savepoint
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, createSavepoint);

/**
 * Releases given savepoint
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, releaseSavepoint);

/**
 * Rollbacks given savepoint
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, rollbackSavepoint);

/**
 * Set if nested transactions should use savepoints
 *
 * @param boolean nestedTransactionsWithSavepoints
 * @return Pdm\Db\AdapterInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, setNestedTransactionsWithSavepoints);

/**
 * Returns if nested transactions should use savepoints
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, isNestedTransactionsWithSavepoints);

/**
 * Returns the savepoint name to use for nested transactions
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_AdapterInterface, getNestedTransactionSavepointName);

