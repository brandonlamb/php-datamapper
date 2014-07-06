
extern zend_class_entry *pdm_db_adapter_pdo_db2_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Db2);

PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, getType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, getDialectType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, lastInsertId);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Db2, supportSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_pdo_db2_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_adapter_pdo_db2_method_entry) {
	PHP_ME(Pdm_Db_Adapter_Pdo_Db2, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Db2, getDialectType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Db2, lastInsertId, arginfo_pdm_db_adapter_pdo_db2_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Db2, supportSequences, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
