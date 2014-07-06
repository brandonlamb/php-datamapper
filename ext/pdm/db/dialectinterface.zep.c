
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Pdm\Db\DialectInterface
 *
 * Interface for Pdm\Db dialects
 */
ZEPHIR_INIT_CLASS(Pdm_Db_DialectInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Db, DialectInterface, pdm, db_dialectinterface, pdm_db_dialectinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets escape character
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, getEscapeChar);

/**
 * Generates the SQL for LIMIT
 *
 * @param string sqlQuery
 * @param int number
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, limit);

/**
 * Generates the SQL for OFFSET
 *
 * @param string sqlQuery
 * @param int number
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, offset);

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string sqlQuery
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, forUpdate);

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string sqlQuery
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, sharedLock);

/**
 * Builds a SELECT statement
 *
 * @param array definition
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, select);

/**
 * Gets a list of columns
 *
 * @param array columnList
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, getColumnList);

/**
 * Checks whether the platform supports savepoints
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, supportsSavepoints);

/**
 * Checks whether the platform supports releasing savepoints.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, supportsReleaseSavepoints);

/**
 * Generate SQL to create a new savepoint
 *
 * @param string name
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, createSavepoint);

/**
 * Generate SQL to release a savepoint
 *
 * @param string name
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, releaseSavepoint);

/**
 * Generate SQL to rollback a savepoint
 *
 * @param string name
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_DialectInterface, rollbackSavepoint);

