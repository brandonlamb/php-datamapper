
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
 * Oracle PDO Adapter
 *
 * Specific functions for the Oracle database system
 *
 * <code>
 *   $connection = new \Phalcon\Db\Adapter\Pdo\Oracle($config);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Oracle) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Adapter\\Pdo, Oracle, pdm, db_adapter_pdo_oracle, pdm_db_adapter_abstractpdo_ce, pdm_db_adapter_pdo_oracle_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_oracle_ce, SL("type"), "oci", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_oracle_ce, SL("dialectType"), "oracle", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_adapter_pdo_oracle_ce TSRMLS_CC, 1, pdm_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Oracle, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Oracle, getDialectType) {


	RETURN_MEMBER(this_ptr, "dialectType");

}

