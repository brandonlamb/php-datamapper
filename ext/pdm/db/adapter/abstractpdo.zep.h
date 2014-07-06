
extern zend_class_entry *pdm_db_adapter_abstractpdo_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_AbstractPdo);

PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, getAffectedRows);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, __construct);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, prepare);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, executePrepared);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, bindStatmentParameters);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, query);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, execute);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, affectedRows);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, close);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, escapeIdentifier);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, escapeString);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, lastInsertId);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, begin);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, rollback);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, commit);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, isUnderTransaction);
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, getInternalHandler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pdo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_executeprepared, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_bindstatmentparameters, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_begin, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapter_abstractpdo_commit, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_adapter_abstractpdo_method_entry) {
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, getAffectedRows, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, __construct, arginfo_pdm_db_adapter_abstractpdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, prepare, arginfo_pdm_db_adapter_abstractpdo_prepare, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, executePrepared, arginfo_pdm_db_adapter_abstractpdo_executeprepared, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, bindStatmentParameters, arginfo_pdm_db_adapter_abstractpdo_bindstatmentparameters, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, query, arginfo_pdm_db_adapter_abstractpdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, execute, arginfo_pdm_db_adapter_abstractpdo_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, affectedRows, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, escapeIdentifier, arginfo_pdm_db_adapter_abstractpdo_escapeidentifier, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, escapeString, arginfo_pdm_db_adapter_abstractpdo_escapestring, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, lastInsertId, arginfo_pdm_db_adapter_abstractpdo_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, begin, arginfo_pdm_db_adapter_abstractpdo_begin, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, rollback, arginfo_pdm_db_adapter_abstractpdo_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, commit, arginfo_pdm_db_adapter_abstractpdo_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, isUnderTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_Adapter_AbstractPdo, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
