
extern zend_class_entry *pdm_db_profilerinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_ProfilerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_profilerinterface_setactive, 0, 0, 1)
	ZEND_ARG_INFO(0, active)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_profilerinterface_addprofile, 0, 0, 4)
	ZEND_ARG_INFO(0, duration)
	ZEND_ARG_INFO(0, functionName)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, bindValues)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_profilerinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Db_ProfilerInterface, setActive, arginfo_pdm_db_profilerinterface_setactive)
	PHP_ABSTRACT_ME(Pdm_Db_ProfilerInterface, isActive, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ProfilerInterface, addProfile, arginfo_pdm_db_profilerinterface_addprofile)
	PHP_ABSTRACT_ME(Pdm_Db_ProfilerInterface, getProfiles, NULL)
  PHP_FE_END
};
