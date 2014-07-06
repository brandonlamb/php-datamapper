
extern zend_class_entry *pdm_db_abstractdb_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_AbstractDb);

PHP_METHOD(Pdm_Db_AbstractDb, setup);
PHP_METHOD(Pdm_Db_AbstractDb, createAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdb_setup, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdb_createadapter, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, pdo)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_abstractdb_method_entry) {
	PHP_ME(Pdm_Db_AbstractDb, setup, arginfo_pdm_db_abstractdb_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pdm_Db_AbstractDb, createAdapter, arginfo_pdm_db_abstractdb_createadapter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
