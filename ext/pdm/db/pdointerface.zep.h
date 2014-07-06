
extern zend_class_entry *pdm_db_pdointerface_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_PdoInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_exec, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, fetch_mode)
	ZEND_ARG_INFO(0, fetch_arg1)
	ZEND_ARG_INFO(0, fetch_arg2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, parameter_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchaffected, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchassoc, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchcol, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchobject, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, ctor_args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchobjects, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, ctor_args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchpairs, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_fetchvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_perform, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdointerface_setprofiler, 0, 0, 1)
	ZEND_ARG_INFO(0, profiler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_pdointerface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, beginTransaction, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, commit, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, errorCode, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, errorInfo, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, exec, arginfo_pdm_db_pdointerface_exec)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, getAttribute, arginfo_pdm_db_pdointerface_getattribute)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, inTransaction, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, lastInsertId, arginfo_pdm_db_pdointerface_lastinsertid)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, prepare, arginfo_pdm_db_pdointerface_prepare)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, query, arginfo_pdm_db_pdointerface_query)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, quote, arginfo_pdm_db_pdointerface_quote)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, rollBack, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, setAttribute, arginfo_pdm_db_pdointerface_setattribute)
	ZEND_FENTRY(getAvailableDrivers, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, connect, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchAffected, arginfo_pdm_db_pdointerface_fetchaffected)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchAll, arginfo_pdm_db_pdointerface_fetchall)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchAssoc, arginfo_pdm_db_pdointerface_fetchassoc)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchCol, arginfo_pdm_db_pdointerface_fetchcol)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchObject, arginfo_pdm_db_pdointerface_fetchobject)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchObjects, arginfo_pdm_db_pdointerface_fetchobjects)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchOne, arginfo_pdm_db_pdointerface_fetchone)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchPairs, arginfo_pdm_db_pdointerface_fetchpairs)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, fetchValue, arginfo_pdm_db_pdointerface_fetchvalue)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, getDsn, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, getPdo, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, getProfiler, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, isConnected, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, perform, arginfo_pdm_db_pdointerface_perform)
	PHP_ABSTRACT_ME(Pdm_Db_PdoInterface, setProfiler, arginfo_pdm_db_pdointerface_setprofiler)
  PHP_FE_END
};
