
extern zend_class_entry *pdm_db_dialect_db2_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Dialect_Db2);

PHP_METHOD(Pdm_Db_Dialect_Db2, limit);
PHP_METHOD(Pdm_Db_Dialect_Db2, offset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialect_db2_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialect_db2_offset, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_dialect_db2_method_entry) {
	PHP_ME(Pdm_Db_Dialect_Db2, limit, arginfo_pdm_db_dialect_db2_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Dialect_Db2, offset, arginfo_pdm_db_dialect_db2_offset, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
