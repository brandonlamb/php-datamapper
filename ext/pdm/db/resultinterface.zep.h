
extern zend_class_entry *pdm_db_resultinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_resultinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_INFO(0, pdoStatement)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_resultinterface_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, __construct, arginfo_pdm_db_resultinterface___construct)
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, execute, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, fetch, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, fetchArray, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, fetchAll, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, numRows, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, setFetchMode, arginfo_pdm_db_resultinterface_setfetchmode)
	PHP_ABSTRACT_ME(Pdm_Db_ResultInterface, getInternalResult, NULL)
  PHP_FE_END
};
