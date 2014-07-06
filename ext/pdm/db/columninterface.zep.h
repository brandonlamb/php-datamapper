
extern zend_class_entry *pdm_db_columninterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_ColumnInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_columninterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, columnName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_columninterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_columninterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, __construct, arginfo_pdm_db_columninterface___construct)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, getName, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, getType, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, getScale, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, getAfterPosition, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, getBindType, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, isNumeric, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, isUnsigned, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, isNotNull, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, isPrimary, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, isIdentity, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, isSequence, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ColumnInterface, isFirst, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_pdm_db_columninterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
