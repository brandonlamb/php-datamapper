
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
 * Pdm\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Dialect_MySQL) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Dialect, MySQL, pdm, db_dialect_mysql, pdm_db_abstractdialect_ce, NULL, 0);

	zend_declare_property_string(pdm_db_dialect_mysql_ce, SL("escapeChar"), "`", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_dialect_mysql_ce TSRMLS_CC, 1, pdm_db_dialectinterface_ce);
	return SUCCESS;

}

