
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


/**
 * Pdm\Db\Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *<code>
 *	use Pdm\Db\Column as Column;
 *
 * //column definition
 * $column = new Column("id", [
 *   "type" => Column::TYPE_INTEGER,
 *   "size" => 10,
 *   "unsigned" => true,
 *   "numeric" => true,
 *   "notNull" => true,
 *   "identity" => true,
 *   "primary" => true,
 *   "first" => true,
 *   "default" => 1,
 * ]);
 *
 * //add column to existing table
 * $connection->addColumn("robots", null, $column);
 *</code>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Column) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db, Column, pdm, db_column, pdm_db_column_method_entry, 0);

	/**
	 * @var string, Column's name
	 */
	zend_declare_property_null(pdm_db_column_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string, Column's alias
	 */
	zend_declare_property_null(pdm_db_column_ce, SL("alias"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int, Column data type
	 */
	zend_declare_property_long(pdm_db_column_ce, SL("type"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int, Bind Type
	 */
	zend_declare_property_long(pdm_db_column_ce, SL("bindType"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string, Column Position
	 */
	zend_declare_property_null(pdm_db_column_ce, SL("afterPosition"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int, Integer column size
	 */
	zend_declare_property_long(pdm_db_column_ce, SL("size"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int, Integer column number scale
	 */
	zend_declare_property_long(pdm_db_column_ce, SL("scale"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var mixed, Default value for column
	 */
	zend_declare_property_null(pdm_db_column_ce, SL("defaultValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean, The column have some numeric type?
	 */
	zend_declare_property_bool(pdm_db_column_ce, SL("isNumeric"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean, Integer column unsigned?
	 */
	zend_declare_property_bool(pdm_db_column_ce, SL("isUnsigned"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean, Column not nullable?
	 */
	zend_declare_property_bool(pdm_db_column_ce, SL("isNotNull"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean, Column is part of the primary key?
	 */
	zend_declare_property_bool(pdm_db_column_ce, SL("isPrimary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean, Column is identity?
	 */
	zend_declare_property_bool(pdm_db_column_ce, SL("isIdentity"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean, Column is sequence?
	 */
	zend_declare_property_bool(pdm_db_column_ce, SL("isSequence"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean, Position is first
	 */
	zend_declare_property_bool(pdm_db_column_ce, SL("isFirst"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int, Integer abstract type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_INTEGER"), 0 TSRMLS_CC);

	/**
	 * @var int, Date abstract type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_DATE"), 1 TSRMLS_CC);

	/**
	 * @var int, Varchar abstract type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_VARCHAR"), 2 TSRMLS_CC);

	/**
	 * @var int, Decimal abstract type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_DECIMAL"), 3 TSRMLS_CC);

	/**
	 * @var int, Datetime abstract type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_DATETIME"), 4 TSRMLS_CC);

	/**
	 * @var int, Char abstract type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_CHAR"), 5 TSRMLS_CC);

	/**
	 * @var int, Text abstract data type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_TEXT"), 6 TSRMLS_CC);

	/**
	 * @var int, Float abstract data type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_FLOAT"), 7 TSRMLS_CC);

	/**
	 * @var int, Boolean abstract data type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_BOOLEAN"), 8 TSRMLS_CC);

	/**
	 * @var int, Time abstract type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("TYPE_TIME"), 9 TSRMLS_CC);

	/**
	 * @var int, Bind Type Null
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("BIND_PARAM_NULL"), 0 TSRMLS_CC);

	/**
	 * @var int, Bind Type Integer
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("BIND_PARAM_INT"), 1 TSRMLS_CC);

	/**
	 * @var int, Bind Type String
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("BIND_PARAM_STR"), 2 TSRMLS_CC);

	/**
	 * @var int, Bind Type Bool
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("BIND_PARAM_BOOL"), 5 TSRMLS_CC);

	/**
	 * @var int, Bind Type Decimal
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("BIND_PARAM_DECIMAL"), 32 TSRMLS_CC);

	/**
	 * @var int, Skip binding by type
	 */
	zend_declare_class_constant_long(pdm_db_column_ce, SL("BIND_SKIP"), 1024 TSRMLS_CC);

	zend_class_implements(pdm_db_column_ce TSRMLS_CC, 1, pdm_db_columninterface_ce);
	return SUCCESS;

}

/**
 * @var string, Column's name
 */
PHP_METHOD(Pdm_Db_Column, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * @var string, Column's alias
 */
PHP_METHOD(Pdm_Db_Column, getAlias) {


	RETURN_MEMBER(this_ptr, "alias");

}

/**
 * @var int, Column data type
 */
PHP_METHOD(Pdm_Db_Column, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * @var int, Bind Type
 */
PHP_METHOD(Pdm_Db_Column, getBindType) {


	RETURN_MEMBER(this_ptr, "bindType");

}

/**
 * @var string, Column Position
 */
PHP_METHOD(Pdm_Db_Column, getAfterPosition) {


	RETURN_MEMBER(this_ptr, "afterPosition");

}

/**
 * @var int, Integer column size
 */
PHP_METHOD(Pdm_Db_Column, getSize) {


	RETURN_MEMBER(this_ptr, "size");

}

/**
 * @var int, Integer column number scale
 */
PHP_METHOD(Pdm_Db_Column, getScale) {


	RETURN_MEMBER(this_ptr, "scale");

}

/**
 * @var mixed, Default value for column
 */
PHP_METHOD(Pdm_Db_Column, getDefaultValue) {


	RETURN_MEMBER(this_ptr, "defaultValue");

}

/**
 * Pdm\Db\Column constructor
 *
 * @param string name
 * @param array definition
 */
PHP_METHOD(Pdm_Db_Column, __construct) {

	zend_bool _2, _3;
	zval *definition = NULL;
	zval *name_param = NULL, *definition_param = NULL, *type, *alias, *bindType, *size, *scale, *afterPosition, *defaultValue, *isNotNull, *isPrimary, *isUnsigned, *isFirst, *isNumeric, *isIdentity, *isSequence, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	zephir_get_arrval(definition, definition_param);


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	ZEPHIR_OBS_VAR(type);
	if (zephir_array_isset_string_fetch(&type, definition, SS("type"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, zephir_get_intval(type));
		zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Column type is required", "pdm/db/column.zep", 206);
		return;
	}
	ZEPHIR_OBS_VAR(alias);
	if (zephir_array_isset_string_fetch(&alias, definition, SS("alias"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_trim(_1, alias, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("alias"), _1 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(bindType);
	if (zephir_array_isset_string_fetch(&bindType, definition, SS("bindType"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, zephir_get_intval(bindType));
		zephir_update_property_this(this_ptr, SL("bindType"), _0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(size);
	if (zephir_array_isset_string_fetch(&size, definition, SS("size"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, zephir_get_intval(size));
		zephir_update_property_this(this_ptr, SL("size"), _0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(scale);
	if (zephir_array_isset_string_fetch(&scale, definition, SS("scale"), 0 TSRMLS_CC)) {
		_2 = !ZEPHIR_IS_LONG(type, 0);
		if (_2) {
			_2 = !ZEPHIR_IS_LONG(type, 7);
		}
		_3 = _2;
		if (_3) {
			_3 = !ZEPHIR_IS_LONG(type, 3);
		}
		if (unlikely(_3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Column type does not support scale parameter", "pdm/db/column.zep", 227);
			return;
		}
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, zephir_get_intval(scale));
		zephir_update_property_this(this_ptr, SL("scale"), _0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(afterPosition);
	if (zephir_array_isset_string_fetch(&afterPosition, definition, SS("after"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("afterPosition"), afterPosition TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(defaultValue);
	if (zephir_array_isset_string_fetch(&defaultValue, definition, SS("default"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("defaultValue"), defaultValue TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(isNotNull);
	if (zephir_array_isset_string_fetch(&isNotNull, definition, SS("notNull"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("isNotNull"), (zephir_get_boolval(isNotNull)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(isPrimary);
	if (zephir_array_isset_string_fetch(&isPrimary, definition, SS("primary"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("isPrimary"), (zephir_get_boolval(isPrimary)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(isUnsigned);
	if (zephir_array_isset_string_fetch(&isUnsigned, definition, SS("unsigned"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("isUnsigned"), (zephir_get_boolval(isUnsigned)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(isNumeric);
	if (zephir_array_isset_string_fetch(&isNumeric, definition, SS("isNumeric"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("isNumeric"), (zephir_get_boolval(isNumeric)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(isIdentity);
	if (zephir_array_isset_string_fetch(&isIdentity, definition, SS("identity"), 0 TSRMLS_CC)) {
		if (unlikely(!ZEPHIR_IS_LONG(type, 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Column type cannot be auto-increment", "pdm/db/column.zep", 265);
			return;
		}
		zephir_update_property_this(this_ptr, SL("isIdentity"), (zephir_get_boolval(isIdentity)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(isSequence);
	if (zephir_array_isset_string_fetch(&isSequence, definition, SS("sequence"), 0 TSRMLS_CC)) {
		if (unlikely(!ZEPHIR_IS_LONG(type, 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Column type cannot be sequence", "pdm/db/column.zep", 273);
			return;
		}
		zephir_update_property_this(this_ptr, SL("isSequence"), (zephir_get_boolval(isSequence)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&isFirst, definition, SS("first"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("isFirst"), (zephir_get_boolval(isFirst)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Column, isNumeric) {


	RETURN_MEMBER(this_ptr, "isNumeric");

}

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Column, isUnsigned) {


	RETURN_MEMBER(this_ptr, "isUnsigned");

}

/**
 * Not null
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Column, isNotNull) {


	RETURN_MEMBER(this_ptr, "isNotNull");

}

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Column, isPrimary) {


	RETURN_MEMBER(this_ptr, "isPrimary");

}

/**
 * Auto-Increment
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Column, isIdentity) {


	RETURN_MEMBER(this_ptr, "isIdentity");

}

/**
 * Sequence
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Column, isSequence) {


	RETURN_MEMBER(this_ptr, "isSequence");

}

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Column, isFirst) {


	RETURN_MEMBER(this_ptr, "isFirst");

}

/**
 * Restores the internal state of a Pdm\Db\Column object
 *
 * @param array data
 * @return \Pdm\Db\Column
 */
PHP_METHOD(Pdm_Db_Column, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *definition, *alias, *columnType, *bindType, *size, *afterPosition, *isNotNull, *isUnsigned, *isNumeric, *isFirst, *isPrimary, *isIdentity, *isSequence, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Column state must be an array", "pdm/db/column.zep", 366);
		return;
	}
	if (!(zephir_array_isset_string(data, SS("name")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Column name is required", "pdm/db/column.zep", 370);
		return;
	}
	ZEPHIR_INIT_VAR(definition);
	array_init(definition);
	if (zephir_array_isset_string_fetch(&columnType, data, SS("type"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("type"), &columnType, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&alias, data, SS("alias"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("alias"), &alias, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&bindType, data, SS("bindType"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("bindType"), &bindType, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&size, data, SS("size"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("size"), &size, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&afterPosition, data, SS("after"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("after"), &afterPosition, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isNumeric, data, SS("isNumeric"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("isNumeric"), &isNumeric, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isUnsigned, data, SS("unsigned"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("unsigned"), &isUnsigned, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isNotNull, data, SS("notNull"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("notNull"), &isNotNull, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isPrimary, data, SS("primary"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("primary"), &isPrimary, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isIdentity, data, SS("identity"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("identity"), &isIdentity, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isSequence, data, SS("sequence"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("sequence"), &isSequence, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isFirst, data, SS("first"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("first"), &isFirst, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, pdm_db_column_ce);
	zephir_array_fetch_string(&_0, data, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0, definition);
	zephir_check_call_status();
	RETURN_MM();

}

