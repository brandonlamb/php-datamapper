
extern zend_class_entry *pdm_db_adapter_pdo_oracle_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Oracle);

PHP_METHOD(Pdm_Db_Adapter_Pdo_Oracle, getType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Oracle, getDialectType);

ZEPHIR_INIT_FUNCS(pdm_db_adapter_pdo_oracle_method_entry) {
	PHP_ME(Pdm_Db_Adapter_Pdo_Oracle, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Oracle, getDialectType, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
