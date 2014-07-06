
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Base DB class liberally borrowed from PhalconPHP
 *
 * @package \Pdm\Db
 * @author Andres Gutierrez <andres@phalconphp.com>
 * @author Eduar Carvajal <eduar@phalconphp.com>
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_AbstractDb) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db, AbstractDb, pdm, db_abstractdb, pdm_db_abstractdb_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Enables/disables options in the Database component
 *
 * @param array options
 */
PHP_METHOD(Pdm_Db_AbstractDb, setup) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options, *escapeIdentifiers, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Options must be an array", "pdm/db/abstractdb.zep", 27);
		return;
	}
	ZEPHIR_OBS_VAR(escapeIdentifiers);
	if (zephir_array_isset_string_fetch(&escapeIdentifiers, options, SS("escapeSqlIdentifiers"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "db.escape_identifiers", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "globals_set", NULL, _0, escapeIdentifiers);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adapter factory method
 *
 * @param string type
 * @param \PDO pdo
 * @return AdapterInterface
 */
PHP_METHOD(Pdm_Db_AbstractDb, createAdapter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *pdo, *adapter = NULL, *_0 = NULL, *_1, *_2;
	zval *type = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &pdo);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(type_param) == IS_STRING)) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	if (!(zephir_instance_of_ev(pdo, php_pdo_get_dbh_ce() TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'pdo' must be an instance of 'PDO'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, type);
	do {
		if (ZEPHIR_IS_STRING(_1, "db2")) {
			ZEPHIR_INIT_VAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_db2_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "ibm")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_db2_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "mysql")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_mysql_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "oci")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_oracle_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "oracle")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_oracle_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "pgsql")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_pgsql_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "postgres")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_pgsql_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "sqlite")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, pdm_db_adapter_pdo_sqlite_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, pdo);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, pdm_db_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "Unsupported database type '", type, "'");
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "pdm/db/abstractdb.zep", 80 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	RETURN_CCTOR(adapter);

}

