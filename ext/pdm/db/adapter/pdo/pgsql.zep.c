
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


/**
 * PostgreSQL PDO Adapter
 *
 * Specific functions for the Postgresql database system
 *
 * <code>
 *   $connection = new \Pdm\Db\Adapter\Pdo\Pgsql($pdo);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Pgsql) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Adapter\\Pdo, Pgsql, pdm, db_adapter_pdo_pgsql, pdm_db_adapter_abstractpdo_ce, pdm_db_adapter_pdo_pgsql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_pgsql_ce, SL("type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_pgsql_ce, SL("dialectType"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_adapter_pdo_pgsql_ce TSRMLS_CC, 1, pdm_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Pgsql, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Pgsql, getDialectType) {


	RETURN_MEMBER(this_ptr, "dialectType");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Pgsql, supportSequences) {


	RETURN_BOOL(1);

}

