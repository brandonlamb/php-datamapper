
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Pdm_Query_QueryFactory) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Query, QueryFactory, pdm, query_queryfactory, pdm_query_queryfactory_method_entry, 0);

	/**
	 * What database are we building for?
	 *
	 * @param string
	 */
	zend_declare_property_null(pdm_query_queryfactory_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * A map of `table.col` names to last-insert-id names.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_query_queryfactory_ce, SL("lastInsertIdNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param string $db The database type.
 * @param string $common Pass the constant self::COMMON to force common
 * query objects instead of db-specific ones.
 * @param array $lastInsertIdNames A map of `table.col` names to
 * last-insert-id names.
 */
PHP_METHOD(Pdm_Query_QueryFactory, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *db_param = NULL, *_0, *_1 = NULL, *_3;
	zval *db = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &db_param);

	if (unlikely(Z_TYPE_P(db_param) != IS_STRING && Z_TYPE_P(db_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'db' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(db_param) == IS_STRING)) {
		db = db_param;
	} else {
		ZEPHIR_INIT_VAR(db);
		ZVAL_EMPTY_STRING(db);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, db);
	ZEPHIR_CALL_FUNCTION(&_1, "ucfirst", &_2, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("db"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("lastInsertIdNames"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the last-insert-id names to be used for Insert queries..
 *
 * @param array $lastInsertIdNames A map of `table.col` names to
 * last-insert-id names.
 *
 * @return void
 */
PHP_METHOD(Pdm_Query_QueryFactory, setLastInsertIdNames) {

	zval *lastInsertIdNames;

	zephir_fetch_params(0, 1, 0, &lastInsertIdNames);



	if (Z_TYPE_P(lastInsertIdNames) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "lastInsertIdNames must be array.", "pdm/query/queryfactory.zep", 56);
		return;
	}
	zephir_update_property_this(this_ptr, SL("lastInsertIdNames"), lastInsertIdNames TSRMLS_CC);

}

/**
 * Returns a new SELECT object.
 *
 * @return Common\SelectInterface
 */
PHP_METHOD(Pdm_Query_QueryFactory, newSelect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Select", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a new INSERT object.
 *
 * @return Common\InsertInterface
 */
PHP_METHOD(Pdm_Query_QueryFactory, newInsert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *insert = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Insert", 0);
	ZEPHIR_CALL_METHOD(&insert, this_ptr, "newinstance", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("lastInsertIdNames"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, insert, "setlastinsertidnames", NULL, _1);
	zephir_check_call_status();
	RETURN_CCTOR(insert);

}

/**
 * Returns a new UPDATE object.
 *
 * @return Common\UpdateInterface
 */
PHP_METHOD(Pdm_Query_QueryFactory, newUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Update", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a new DELETE object.
 *
 * @return Common\DeleteInterface
 */
PHP_METHOD(Pdm_Query_QueryFactory, newDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Delete", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a new query object.
 *
 * @param string $query The query object type.
 * @return AbstractQuery
 */
PHP_METHOD(Pdm_Query_QueryFactory, newInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zval *query_param = NULL, *_0, *_1;
	zval *query = NULL, *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	if (unlikely(Z_TYPE_P(query_param) != IS_STRING && Z_TYPE_P(query_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'query' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(query_param) == IS_STRING)) {
		query = query_param;
	} else {
		ZEPHIR_INIT_VAR(query);
		ZVAL_EMPTY_STRING(query);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVSV(_1, "\\Pdm\\Query\\", _0, "\\", query);
	zephir_get_strval(className, _1);
	_2 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
		zephir_check_call_status();
	}
	RETURN_MM();

}

