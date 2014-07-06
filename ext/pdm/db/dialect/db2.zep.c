
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Pdm\Db\Dialect\Db2
 *
 * Generates database specific SQL for the PostgreSQL RBDM
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Dialect_Db2) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Dialect, Db2, pdm, db_dialect_db2, pdm_db_abstractdialect_ce, pdm_db_dialect_db2_method_entry, 0);

	zend_declare_property_string(pdm_db_dialect_db2_ce, SL("escapeChar"), "\'", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_dialect_db2_ce TSRMLS_CC, 1, pdm_db_dialectinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_Dialect_Db2, limit) {

	int number;
	zval *sqlQuery_param = NULL, *number_param = NULL, _0, _1;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		sqlQuery = sqlQuery_param;
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}
	number = zephir_get_intval(number_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, number);
	if (zephir_is_numeric(&_0)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, number);
		ZEPHIR_CONCAT_VSVS(return_value, sqlQuery, " FETCH FIRST ", &_1, " ROWS ONLY");
		RETURN_MM();
	}
	RETURN_CTOR(sqlQuery);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_Dialect_Db2, offset) {

	int number;
	zval *sqlQuery_param = NULL, *number_param = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		sqlQuery = sqlQuery_param;
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}
	number = zephir_get_intval(number_param);


	RETURN_CTOR(sqlQuery);

}

