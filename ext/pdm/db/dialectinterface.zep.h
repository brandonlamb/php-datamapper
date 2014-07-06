
extern zend_class_entry *pdm_db_dialectinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_DialectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_offset, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_select, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_dialectinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_dialectinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, getEscapeChar, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, limit, arginfo_pdm_db_dialectinterface_limit)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, offset, arginfo_pdm_db_dialectinterface_offset)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, forUpdate, arginfo_pdm_db_dialectinterface_forupdate)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, sharedLock, arginfo_pdm_db_dialectinterface_sharedlock)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, select, arginfo_pdm_db_dialectinterface_select)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, getColumnList, arginfo_pdm_db_dialectinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, supportsSavepoints, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, supportsReleaseSavepoints, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, createSavepoint, arginfo_pdm_db_dialectinterface_createsavepoint)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, releaseSavepoint, arginfo_pdm_db_dialectinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Pdm_Db_DialectInterface, rollbackSavepoint, arginfo_pdm_db_dialectinterface_rollbacksavepoint)
  PHP_FE_END
};
