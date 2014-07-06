
extern zend_class_entry *pdm_db_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, fetchType)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, fetchType)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_begin, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_commit, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_adapterinterface_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, __construct, arginfo_pdm_db_adapterinterface___construct)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, fetchOne, arginfo_pdm_db_adapterinterface_fetchone)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, fetchAll, arginfo_pdm_db_adapterinterface_fetchall)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, insert, arginfo_pdm_db_adapterinterface_insert)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, update, arginfo_pdm_db_adapterinterface_update)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, delete, arginfo_pdm_db_adapterinterface_delete)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getColumnList, arginfo_pdm_db_adapterinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, forUpdate, arginfo_pdm_db_adapterinterface_forupdate)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, sharedLock, arginfo_pdm_db_adapterinterface_sharedlock)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getConnectionId, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getSQLVariables, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getType, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getDialectType, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getDialect, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, query, arginfo_pdm_db_adapterinterface_query)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, execute, arginfo_pdm_db_adapterinterface_execute)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, affectedRows, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, escapeIdentifier, arginfo_pdm_db_adapterinterface_escapeidentifier)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, escapeString, arginfo_pdm_db_adapterinterface_escapestring)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, lastInsertId, arginfo_pdm_db_adapterinterface_lastinsertid)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, begin, arginfo_pdm_db_adapterinterface_begin)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, rollback, arginfo_pdm_db_adapterinterface_rollback)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, commit, arginfo_pdm_db_adapterinterface_commit)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, isUnderTransaction, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getInternalHandler, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, useExplicitIdValue, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getDefaultIdValue, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, supportSequences, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, createSavepoint, arginfo_pdm_db_adapterinterface_createsavepoint)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, releaseSavepoint, arginfo_pdm_db_adapterinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, rollbackSavepoint, arginfo_pdm_db_adapterinterface_rollbacksavepoint)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, setNestedTransactionsWithSavepoints, arginfo_pdm_db_adapterinterface_setnestedtransactionswithsavepoints)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, isNestedTransactionsWithSavepoints, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_AdapterInterface, getNestedTransactionSavepointName, NULL)
  PHP_FE_END
};
