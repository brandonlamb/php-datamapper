
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Pdm\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RBDM
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Dialect_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Dialect, Sqlite, pdm, db_dialect_sqlite, pdm_db_abstractdialect_ce, NULL, 0);

	zend_declare_property_string(pdm_db_dialect_sqlite_ce, SL("escapeChar"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_dialect_sqlite_ce TSRMLS_CC, 1, pdm_db_dialectinterface_ce);
	return SUCCESS;

}

