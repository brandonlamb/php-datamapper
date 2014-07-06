
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Pdm\Db\ResultInterface
 *
 * Interface for Pdm\Db\Result objects
 *
 * @package \Pdm\Db
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_ResultInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Db, ResultInterface, pdm, db_resultinterface, pdm_db_resultinterface_method_entry);

	return SUCCESS;

}

/**
 * Pdm\Db\Result\Pdo constructor
 *
 * @param Pdm\Db\AdapterInterface connection
 * @param \PDOStatement pdoStatement
 * @param string sqlStatement
 * @param array bindParams
 * @param array bindTypes
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, __construct);

/**
 * Allows to executes the statement again. Some database systems don't support scrollable cursors,
 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, execute);

/**
 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, fetch);

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
 *
 * @return array | boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, fetchArray);

/**
 * Returns an array of arrays containing all the records in the result
 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, fetchAll);

/**
 * Gets number of rows returned by a resulset
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, numRows);

/**
 * Changes the fetching mode affecting Pdm\Db\Result\Pdo::fetch()
 *
 * @param int fetchMode
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, setFetchMode);

/**
 * Gets the internal PDO result object
 *
 * @return \PDOStatement
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ResultInterface, getInternalResult);

