
extern zend_class_entry *pdm_db_rawvalue_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_RawValue);

PHP_METHOD(Pdm_Db_RawValue, getValue);
PHP_METHOD(Pdm_Db_RawValue, __toString);
PHP_METHOD(Pdm_Db_RawValue, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_rawvalue_method_entry) {
	PHP_ME(Pdm_Db_RawValue, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_RawValue, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_RawValue, __construct, arginfo_pdm_db_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
