
extern zend_class_entry *pdm_db_bindtracker_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_BindTracker);

PHP_METHOD(Pdm_Db_BindTracker, getNum);
PHP_METHOD(Pdm_Db_BindTracker, getCount);
PHP_METHOD(Pdm_Db_BindTracker, getValues);
PHP_METHOD(Pdm_Db_BindTracker, getFinalValues);
PHP_METHOD(Pdm_Db_BindTracker, __construct);
PHP_METHOD(Pdm_Db_BindTracker, __set);
PHP_METHOD(Pdm_Db_BindTracker, setNum);
PHP_METHOD(Pdm_Db_BindTracker, setCount);
PHP_METHOD(Pdm_Db_BindTracker, setValues);
PHP_METHOD(Pdm_Db_BindTracker, setFinalValues);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_bindtracker___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_bindtracker___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_bindtracker_setnum, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_bindtracker_setcount, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_bindtracker_setvalues, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_bindtracker_setfinalvalues, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_bindtracker_method_entry) {
	PHP_ME(Pdm_Db_BindTracker, getNum, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, getCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, getValues, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, getFinalValues, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, __construct, arginfo_pdm_db_bindtracker___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Db_BindTracker, __set, arginfo_pdm_db_bindtracker___set, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, setNum, arginfo_pdm_db_bindtracker_setnum, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, setCount, arginfo_pdm_db_bindtracker_setcount, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, setValues, arginfo_pdm_db_bindtracker_setvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_BindTracker, setFinalValues, arginfo_pdm_db_bindtracker_setfinalvalues, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
