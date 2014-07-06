
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface for Db Column
 *
 * @package \Pdm\Db
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
/**
 * Pdm\Db\ColumnInterface
 *
 * Interface for Pdm\Db\Column
 */
ZEPHIR_INIT_CLASS(Pdm_Db_ColumnInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Db, ColumnInterface, pdm, db_columninterface, pdm_db_columninterface_method_entry);

	return SUCCESS;

}

/**
 * Pdm\Db\ColumnInterface constructor
 *
 * @param string columnName
 * @param array definition
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, __construct);

/**
 * Returns column name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, getName);

/**
 * Returns column type
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, getType);

/**
 * Returns column size
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, getSize);

/**
 * Returns column scale
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, getScale);

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, getAfterPosition);

/**
 * Returns the type of bind handling
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, getBindType);

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, isNumeric);

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, isUnsigned);

/**
 * Not null
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, isNotNull);

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, isPrimary);

/**
 * Identity/Auto-Increment
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, isIdentity);

/**
 * Sequence
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, isSequence);

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, isFirst);

/**
 * Restores the internal state of a Pdm\Db\Column object
 *
 * @param array data
 * @return \Pdm\Db\ColumnInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ColumnInterface, __set_state);

