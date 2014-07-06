
extern zend_class_entry *pdm_db_result_pdo_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Result_Pdo);

PHP_METHOD(Pdm_Db_Result_Pdo, getFetchMode);
PHP_METHOD(Pdm_Db_Result_Pdo, getSqlStatement);
PHP_METHOD(Pdm_Db_Result_Pdo, __construct);
PHP_METHOD(Pdm_Db_Result_Pdo, execute);
PHP_METHOD(Pdm_Db_Result_Pdo, fetch);
PHP_METHOD(Pdm_Db_Result_Pdo, fetchArray);
PHP_METHOD(Pdm_Db_Result_Pdo, fetchAll);
PHP_METHOD(Pdm_Db_Result_Pdo, numRows);
PHP_METHOD(Pdm_Db_Result_Pdo, setFetchMode);
PHP_METHOD(Pdm_Db_Result_Pdo, getInternalResult);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_result_pdo___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_INFO(0, pdoStatement)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_result_pdo_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_result_pdo_method_entry) {
	PHP_ME(Pdm_Db_Result_Pdo, getFetchMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, getSqlStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, __construct, arginfo_pdm_db_result_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Db_Result_Pdo, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, fetch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, fetchArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, fetchAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, numRows, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, setFetchMode, arginfo_pdm_db_result_pdo_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Result_Pdo, getInternalResult, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
