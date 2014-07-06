
extern zend_class_entry *pdm_db_adapter_pdo_sqlite_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Sqlite);

PHP_METHOD(Pdm_Db_Adapter_Pdo_Sqlite, getType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Sqlite, getDialectType);

ZEPHIR_INIT_FUNCS(pdm_db_adapter_pdo_sqlite_method_entry) {
	PHP_ME(Pdm_Db_Adapter_Pdo_Sqlite, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Sqlite, getDialectType, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
