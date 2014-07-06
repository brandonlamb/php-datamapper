
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * DB2 PDO Adapter
 *
 * Specific functions for the DB2 database system
 *
 * <code>
 *   $connection = new \Pdm\Db\Adapter\Pdo\Db2($pdo);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Db2) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Adapter\\Pdo, Db2, pdm, db_adapter_pdo_db2, pdm_db_adapter_abstractpdo_ce, pdm_db_adapter_pdo_db2_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_db2_ce, SL("type"), "db2", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(pdm_db_adapter_pdo_db2_ce, SL("dialectType"), "db2", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_adapter_pdo_db2_ce TSRMLS_CC, 1, pdm_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, getDialectType) {


	RETURN_MEMBER(this_ptr, "dialectType");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, lastInsertId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequence_param = NULL, *statement = NULL, *row = NULL, *pdo = NULL, *_0, *_1, *_2 = NULL, *_4, *_5 = NULL, *_6;
	zval *sequence = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sequence_param);

	if (!sequence_param) {
		ZEPHIR_INIT_VAR(sequence);
		ZVAL_EMPTY_STRING(sequence);
	} else {
	if (unlikely(Z_TYPE_P(sequence_param) != IS_STRING && Z_TYPE_P(sequence_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sequence' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sequence_param) == IS_STRING)) {
		sequence = sequence_param;
	} else {
		ZEPHIR_INIT_VAR(sequence);
		ZVAL_EMPTY_STRING(sequence);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(pdo, _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_gettype(_1, sequence TSRMLS_CC);
	ZEPHIR_INIT_VAR(statement);
	if (!ZEPHIR_IS_STRING(_1, "null")) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SV(_3, "VALUES PREVIOUS VALUE FOR ", sequence);
		ZEPHIR_CALL_METHOD(&_2, _0, "query", NULL, _3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(statement, _2);
	} else {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "VALUES IDENTITY_VAL_LOCAL()", 0);
		ZEPHIR_CALL_METHOD(&_2, _4, "query", NULL, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(statement, _2);
	}
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 3);
	ZEPHIR_CALL_METHOD(&row, statement, "fetch", NULL, _5);
	zephir_check_call_status();
	if (zephir_array_isset_long(row, 0)) {
		zephir_array_fetch_long(&_6, row, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_6);
	} else {
		RETURN_MM_LONG(0);
	}

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, supportSequences) {


	RETURN_BOOL(1);

}

