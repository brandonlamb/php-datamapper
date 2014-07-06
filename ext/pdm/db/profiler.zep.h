
extern zend_class_entry *pdm_db_profiler_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Profiler);

PHP_METHOD(Pdm_Db_Profiler, setActive);
PHP_METHOD(Pdm_Db_Profiler, isActive);
PHP_METHOD(Pdm_Db_Profiler, addProfile);
PHP_METHOD(Pdm_Db_Profiler, getProfiles);
PHP_METHOD(Pdm_Db_Profiler, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_profiler_setactive, 0, 0, 1)
	ZEND_ARG_INFO(0, active)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_profiler_addprofile, 0, 0, 3)
	ZEND_ARG_INFO(0, duration)
	ZEND_ARG_INFO(0, functionName)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, bindValues)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_profiler_method_entry) {
	PHP_ME(Pdm_Db_Profiler, setActive, arginfo_pdm_db_profiler_setactive, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Profiler, isActive, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Profiler, addProfile, arginfo_pdm_db_profiler_addprofile, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Profiler, getProfiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Profiler, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
