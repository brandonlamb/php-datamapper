
extern zend_class_entry *pdm_db_pdo_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Pdo);

PHP_METHOD(Pdm_Db_Pdo, __construct);
PHP_METHOD(Pdm_Db_Pdo, beginTransaction);
PHP_METHOD(Pdm_Db_Pdo, commit);
PHP_METHOD(Pdm_Db_Pdo, connect);
PHP_METHOD(Pdm_Db_Pdo, errorCode);
PHP_METHOD(Pdm_Db_Pdo, errorInfo);
PHP_METHOD(Pdm_Db_Pdo, exec);
PHP_METHOD(Pdm_Db_Pdo, fetchAffected);
PHP_METHOD(Pdm_Db_Pdo, fetchAll);
PHP_METHOD(Pdm_Db_Pdo, fetchAllWithCallable);
PHP_METHOD(Pdm_Db_Pdo, applyCallableToFetchAll);
PHP_METHOD(Pdm_Db_Pdo, fetchAssoc);
PHP_METHOD(Pdm_Db_Pdo, fetchCol);
PHP_METHOD(Pdm_Db_Pdo, fetchObject);
PHP_METHOD(Pdm_Db_Pdo, fetchObjects);
PHP_METHOD(Pdm_Db_Pdo, fetchOne);
PHP_METHOD(Pdm_Db_Pdo, fetchPairs);
PHP_METHOD(Pdm_Db_Pdo, fetchValue);
PHP_METHOD(Pdm_Db_Pdo, getAttribute);
PHP_METHOD(Pdm_Db_Pdo, getDsn);
PHP_METHOD(Pdm_Db_Pdo, getPdo);
PHP_METHOD(Pdm_Db_Pdo, getProfiler);
PHP_METHOD(Pdm_Db_Pdo, inTransaction);
PHP_METHOD(Pdm_Db_Pdo, isConnected);
PHP_METHOD(Pdm_Db_Pdo, lastInsertId);
PHP_METHOD(Pdm_Db_Pdo, perform);
PHP_METHOD(Pdm_Db_Pdo, prepare);
PHP_METHOD(Pdm_Db_Pdo, query);
PHP_METHOD(Pdm_Db_Pdo, quote);
PHP_METHOD(Pdm_Db_Pdo, rollBack);
PHP_METHOD(Pdm_Db_Pdo, setAttribute);
PHP_METHOD(Pdm_Db_Pdo, setProfiler);
PHP_METHOD(Pdm_Db_Pdo, beginProfile);
PHP_METHOD(Pdm_Db_Pdo, endProfile);
PHP_METHOD(Pdm_Db_Pdo, prepareWithValues);
PHP_METHOD(Pdm_Db_Pdo, newBindTracker);
PHP_METHOD(Pdm_Db_Pdo, rebuild);
PHP_METHOD(Pdm_Db_Pdo, rebuildStatement);
PHP_METHOD(Pdm_Db_Pdo, rebuildParts);
PHP_METHOD(Pdm_Db_Pdo, rebuildPart);
PHP_METHOD(Pdm_Db_Pdo, prepareValuePlaceholders);
PHP_METHOD(Pdm_Db_Pdo, prepareNumberedPlaceholder);
PHP_METHOD(Pdm_Db_Pdo, prepareNamedPlaceholder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_exec, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchaffected, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchallwithcallable, 0, 0, 2)
	ZEND_ARG_INFO(0, fetchType)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_applycallabletofetchall, 0, 0, 2)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchassoc, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchcol, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchobject, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, ctor_args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchobjects, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, ctor_args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchpairs, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_fetchvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_perform, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_query, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, fetch_mode)
	ZEND_ARG_INFO(0, fetch_arg1)
	ZEND_ARG_INFO(0, fetch_arg2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, parameterType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_setprofiler, 0, 0, 1)
	ZEND_ARG_INFO(0, profiler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_beginprofile, 0, 0, 1)
	ZEND_ARG_INFO(0, functionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_endprofile, 0, 0, 0)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_preparewithvalues, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_newbindtracker, 0, 0, 1)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_rebuild, 0, 0, 2)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_rebuildstatement, 0, 0, 2)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, bind)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_rebuildparts, 0, 0, 2)
	ZEND_ARG_INFO(0, parts)
	ZEND_ARG_INFO(0, bind)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_rebuildpart, 0, 0, 2)
	ZEND_ARG_INFO(0, part)
	ZEND_ARG_INFO(0, bind)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_preparevalueplaceholders, 0, 0, 2)
	ZEND_ARG_INFO(0, subs)
	ZEND_ARG_INFO(0, bind)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_preparenumberedplaceholder, 0, 0, 2)
	ZEND_ARG_INFO(0, sub)
	ZEND_ARG_INFO(0, bind)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_pdo_preparenamedplaceholder, 0, 0, 2)
	ZEND_ARG_INFO(0, sub)
	ZEND_ARG_INFO(0, bind)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_pdo_method_entry) {
	PHP_ME(Pdm_Db_Pdo, __construct, arginfo_pdm_db_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Db_Pdo, beginTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, errorCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, errorInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, exec, arginfo_pdm_db_pdo_exec, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchAffected, arginfo_pdm_db_pdo_fetchaffected, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchAll, arginfo_pdm_db_pdo_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchAllWithCallable, arginfo_pdm_db_pdo_fetchallwithcallable, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, applyCallableToFetchAll, arginfo_pdm_db_pdo_applycallabletofetchall, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, fetchAssoc, arginfo_pdm_db_pdo_fetchassoc, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchCol, arginfo_pdm_db_pdo_fetchcol, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchObject, arginfo_pdm_db_pdo_fetchobject, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchObjects, arginfo_pdm_db_pdo_fetchobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchOne, arginfo_pdm_db_pdo_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchPairs, arginfo_pdm_db_pdo_fetchpairs, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, fetchValue, arginfo_pdm_db_pdo_fetchvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, getAttribute, arginfo_pdm_db_pdo_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, getDsn, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, getPdo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, getProfiler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, lastInsertId, arginfo_pdm_db_pdo_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, perform, arginfo_pdm_db_pdo_perform, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, prepare, arginfo_pdm_db_pdo_prepare, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, query, arginfo_pdm_db_pdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, quote, arginfo_pdm_db_pdo_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, rollBack, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, setAttribute, arginfo_pdm_db_pdo_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, setProfiler, arginfo_pdm_db_pdo_setprofiler, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, beginProfile, arginfo_pdm_db_pdo_beginprofile, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, endProfile, arginfo_pdm_db_pdo_endprofile, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, prepareWithValues, arginfo_pdm_db_pdo_preparewithvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Pdo, newBindTracker, arginfo_pdm_db_pdo_newbindtracker, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, rebuild, arginfo_pdm_db_pdo_rebuild, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, rebuildStatement, arginfo_pdm_db_pdo_rebuildstatement, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, rebuildParts, arginfo_pdm_db_pdo_rebuildparts, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, rebuildPart, arginfo_pdm_db_pdo_rebuildpart, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, prepareValuePlaceholders, arginfo_pdm_db_pdo_preparevalueplaceholders, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, prepareNumberedPlaceholder, arginfo_pdm_db_pdo_preparenumberedplaceholder, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Pdo, prepareNamedPlaceholder, arginfo_pdm_db_pdo_preparenamedplaceholder, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
