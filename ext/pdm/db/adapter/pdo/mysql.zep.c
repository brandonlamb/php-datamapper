
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * Mysql PDO Adapter
 *
 * Specific functions for the Mysql database system
 *
 * <code>
 *   $connection = new \Pdm\Db\Adapter\Pdo\Mysql($pdo);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Adapter\\Pdo, Mysql, pdm, db_adapter_pdo_mysql, pdm_db_adapter_abstractpdo_ce, pdm_db_adapter_pdo_mysql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_mysql_ce, SL("type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_mysql_ce, SL("dialectType"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_adapter_pdo_mysql_ce TSRMLS_CC, 1, pdm_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Mysql, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Mysql, getDialectType) {


	RETURN_MEMBER(this_ptr, "dialectType");

}

/**
 * Escapes a column/table/schema name
 *
 * @param string|array identifier
 * @return string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Mysql, escapeIdentifier) {

	zval *identifier, *domain, *name;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(domain);
		zephir_array_fetch_long(&domain, identifier, 0, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_long(&name, identifier, 1, PH_NOISY TSRMLS_CC);
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_CONCAT_SVSVS(return_value, "`", domain, "`.`", name, "`");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_VSV(return_value, domain, ".", name);
		RETURN_MM();
	}
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CONCAT_SVS(return_value, "`", identifier, "`");
		RETURN_MM();
	}
	RETURN_CCTOR(identifier);

}

