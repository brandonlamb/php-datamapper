
extern zend_class_entry *pdm_db_column_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Column);

PHP_METHOD(Pdm_Db_Column, getName);
PHP_METHOD(Pdm_Db_Column, getAlias);
PHP_METHOD(Pdm_Db_Column, getType);
PHP_METHOD(Pdm_Db_Column, getBindType);
PHP_METHOD(Pdm_Db_Column, getAfterPosition);
PHP_METHOD(Pdm_Db_Column, getSize);
PHP_METHOD(Pdm_Db_Column, getScale);
PHP_METHOD(Pdm_Db_Column, getDefaultValue);
PHP_METHOD(Pdm_Db_Column, __construct);
PHP_METHOD(Pdm_Db_Column, isNumeric);
PHP_METHOD(Pdm_Db_Column, isUnsigned);
PHP_METHOD(Pdm_Db_Column, isNotNull);
PHP_METHOD(Pdm_Db_Column, isPrimary);
PHP_METHOD(Pdm_Db_Column, isIdentity);
PHP_METHOD(Pdm_Db_Column, isSequence);
PHP_METHOD(Pdm_Db_Column, isFirst);
PHP_METHOD(Pdm_Db_Column, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_column___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_column___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_column_method_entry) {
	PHP_ME(Pdm_Db_Column, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, getAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, getBindType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, getAfterPosition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, getScale, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, getDefaultValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, __construct, arginfo_pdm_db_column___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Db_Column, isNumeric, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, isUnsigned, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, isNotNull, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, isPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, isIdentity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, isSequence, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, isFirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Column, __set_state, arginfo_pdm_db_column___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
