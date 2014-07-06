
extern zend_class_entry *pdm_db_adapter_pdo_pgsql_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Pgsql);

PHP_METHOD(Pdm_Db_Adapter_Pdo_Pgsql, getType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Pgsql, getDialectType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Pgsql, supportSequences);

ZEPHIR_INIT_FUNCS(pdm_db_adapter_pdo_pgsql_method_entry) {
	PHP_ME(Pdm_Db_Adapter_Pdo_Pgsql, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Pgsql, getDialectType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Pgsql, supportSequences, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
