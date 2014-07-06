
extern zend_class_entry *pdm_db_adapter_pdo_mysql_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Pdo_Mysql);

PHP_METHOD(Pdm_Db_Adapter_Pdo_Mysql, getType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Mysql, getDialectType);
PHP_METHOD(Pdm_Db_Adapter_Pdo_Mysql, escapeIdentifier);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_pdo_mysql_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_adapter_pdo_mysql_method_entry) {
	PHP_ME(Pdm_Db_Adapter_Pdo_Mysql, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Mysql, getDialectType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_Pdo_Mysql, escapeIdentifier, arginfo_pdm_db_adapter_pdo_mysql_escapeidentifier, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
