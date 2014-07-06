
extern zend_class_entry *pdm_db_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_AbstractAdapter);

PHP_METHOD(Pdm_Db_AbstractAdapter, getType);
PHP_METHOD(Pdm_Db_AbstractAdapter, getDialectType);
PHP_METHOD(Pdm_Db_AbstractAdapter, getConnectionId);
PHP_METHOD(Pdm_Db_AbstractAdapter, getSqlStatement);
PHP_METHOD(Pdm_Db_AbstractAdapter, getSqlVariables);
PHP_METHOD(Pdm_Db_AbstractAdapter, getTransactionLevel);
PHP_METHOD(Pdm_Db_AbstractAdapter, getTransactionsWithSavepoints);
PHP_METHOD(Pdm_Db_AbstractAdapter, __construct);
PHP_METHOD(Pdm_Db_AbstractAdapter, setEventsManager);
PHP_METHOD(Pdm_Db_AbstractAdapter, getEventsManager);
PHP_METHOD(Pdm_Db_AbstractAdapter, setDialect);
PHP_METHOD(Pdm_Db_AbstractAdapter, getDialect);
PHP_METHOD(Pdm_Db_AbstractAdapter, fetchOne);
PHP_METHOD(Pdm_Db_AbstractAdapter, fetchAll);
PHP_METHOD(Pdm_Db_AbstractAdapter, insert);
PHP_METHOD(Pdm_Db_AbstractAdapter, update);
PHP_METHOD(Pdm_Db_AbstractAdapter, delete);
PHP_METHOD(Pdm_Db_AbstractAdapter, getColumnList);
PHP_METHOD(Pdm_Db_AbstractAdapter, forUpdate);
PHP_METHOD(Pdm_Db_AbstractAdapter, sharedLock);
PHP_METHOD(Pdm_Db_AbstractAdapter, getColumnDefinition);
PHP_METHOD(Pdm_Db_AbstractAdapter, createSavepoint);
PHP_METHOD(Pdm_Db_AbstractAdapter, releaseSavepoint);
PHP_METHOD(Pdm_Db_AbstractAdapter, rollbackSavepoint);
PHP_METHOD(Pdm_Db_AbstractAdapter, setNestedTransactionsWithSavepoints);
PHP_METHOD(Pdm_Db_AbstractAdapter, isNestedTransactionsWithSavepoints);
PHP_METHOD(Pdm_Db_AbstractAdapter, getNestedTransactionSavepointName);
PHP_METHOD(Pdm_Db_AbstractAdapter, getDefaultIdValue);
PHP_METHOD(Pdm_Db_AbstractAdapter, supportSequences);
PHP_METHOD(Pdm_Db_AbstractAdapter, useExplicitIdValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_setdialect, 0, 0, 1)
	ZEND_ARG_INFO(0, dialect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, fetchType)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, fetchType)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractadapter_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_abstractadapter_method_entry) {
	PHP_ME(Pdm_Db_AbstractAdapter, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getDialectType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getConnectionId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getSqlStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getSqlVariables, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getTransactionLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getTransactionsWithSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Db_AbstractAdapter, setEventsManager, arginfo_pdm_db_abstractadapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, setDialect, arginfo_pdm_db_abstractadapter_setdialect, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getDialect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, fetchOne, arginfo_pdm_db_abstractadapter_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, fetchAll, arginfo_pdm_db_abstractadapter_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, insert, arginfo_pdm_db_abstractadapter_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, update, arginfo_pdm_db_abstractadapter_update, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, delete, arginfo_pdm_db_abstractadapter_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getColumnList, arginfo_pdm_db_abstractadapter_getcolumnlist, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, forUpdate, arginfo_pdm_db_abstractadapter_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, sharedLock, arginfo_pdm_db_abstractadapter_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getColumnDefinition, arginfo_pdm_db_abstractadapter_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, createSavepoint, arginfo_pdm_db_abstractadapter_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, releaseSavepoint, arginfo_pdm_db_abstractadapter_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, rollbackSavepoint, arginfo_pdm_db_abstractadapter_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, setNestedTransactionsWithSavepoints, arginfo_pdm_db_abstractadapter_setnestedtransactionswithsavepoints, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, isNestedTransactionsWithSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getNestedTransactionSavepointName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, supportSequences, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractAdapter, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
