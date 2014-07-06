
extern zend_class_entry *pdm_db_abstractdialect_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_AbstractDialect);

PHP_METHOD(Pdm_Db_AbstractDialect, getEscapeChar);
PHP_METHOD(Pdm_Db_AbstractDialect, limit);
PHP_METHOD(Pdm_Db_AbstractDialect, offset);
PHP_METHOD(Pdm_Db_AbstractDialect, forUpdate);
PHP_METHOD(Pdm_Db_AbstractDialect, sharedLock);
PHP_METHOD(Pdm_Db_AbstractDialect, supportsSavepoints);
PHP_METHOD(Pdm_Db_AbstractDialect, supportsReleaseSavepoints);
PHP_METHOD(Pdm_Db_AbstractDialect, createSavepoint);
PHP_METHOD(Pdm_Db_AbstractDialect, releaseSavepoint);
PHP_METHOD(Pdm_Db_AbstractDialect, rollbackSavepoint);
PHP_METHOD(Pdm_Db_AbstractDialect, getColumnList);
PHP_METHOD(Pdm_Db_AbstractDialect, getSqlExpression);
PHP_METHOD(Pdm_Db_AbstractDialect, getSqlTable);
PHP_METHOD(Pdm_Db_AbstractDialect, select);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_offset, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_getsqlexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_getsqltable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_abstractdialect_select, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_abstractdialect_method_entry) {
	PHP_ME(Pdm_Db_AbstractDialect, getEscapeChar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, limit, arginfo_pdm_db_abstractdialect_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, offset, arginfo_pdm_db_abstractdialect_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, forUpdate, arginfo_pdm_db_abstractdialect_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, sharedLock, arginfo_pdm_db_abstractdialect_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, supportsSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, createSavepoint, arginfo_pdm_db_abstractdialect_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, releaseSavepoint, arginfo_pdm_db_abstractdialect_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, rollbackSavepoint, arginfo_pdm_db_abstractdialect_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, getColumnList, arginfo_pdm_db_abstractdialect_getcolumnlist, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, getSqlExpression, arginfo_pdm_db_abstractdialect_getsqlexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, getSqlTable, arginfo_pdm_db_abstractdialect_getsqltable, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_AbstractDialect, select, arginfo_pdm_db_abstractdialect_select, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
