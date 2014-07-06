
extern zend_class_entry *pdm_autoload_loader_ce;

ZEPHIR_INIT_CLASS(Pdm_Autoload_Loader);

PHP_METHOD(Pdm_Autoload_Loader, register);
PHP_METHOD(Pdm_Autoload_Loader, unregister);
PHP_METHOD(Pdm_Autoload_Loader, getDebug);
PHP_METHOD(Pdm_Autoload_Loader, addPrefix);
PHP_METHOD(Pdm_Autoload_Loader, setPrefixes);
PHP_METHOD(Pdm_Autoload_Loader, getPrefixes);
PHP_METHOD(Pdm_Autoload_Loader, setClassFile);
PHP_METHOD(Pdm_Autoload_Loader, setClassFiles);
PHP_METHOD(Pdm_Autoload_Loader, addClassFiles);
PHP_METHOD(Pdm_Autoload_Loader, getClassFiles);
PHP_METHOD(Pdm_Autoload_Loader, getLoadedClasses);
PHP_METHOD(Pdm_Autoload_Loader, loadClass);
PHP_METHOD(Pdm_Autoload_Loader, loadFile);
PHP_METHOD(Pdm_Autoload_Loader, requireFile);
PHP_METHOD(Pdm_Autoload_Loader, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_register, 0, 0, 0)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_addprefix, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, baseDirs)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_setprefixes, 0, 0, 1)
	ZEND_ARG_INFO(0, prefixes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_setclassfile, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_setclassfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, classFiles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_addclassfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, classFiles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_loadclass, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_loadfile, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, relativeClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_autoload_loader_requirefile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_autoload_loader_method_entry) {
	PHP_ME(Pdm_Autoload_Loader, register, arginfo_pdm_autoload_loader_register, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, getDebug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, addPrefix, arginfo_pdm_autoload_loader_addprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, setPrefixes, arginfo_pdm_autoload_loader_setprefixes, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, getPrefixes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, setClassFile, arginfo_pdm_autoload_loader_setclassfile, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, setClassFiles, arginfo_pdm_autoload_loader_setclassfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, addClassFiles, arginfo_pdm_autoload_loader_addclassfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, getClassFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, getLoadedClasses, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, loadClass, arginfo_pdm_autoload_loader_loadclass, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Autoload_Loader, loadFile, arginfo_pdm_autoload_loader_loadfile, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Autoload_Loader, requireFile, arginfo_pdm_autoload_loader_requirefile, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Autoload_Loader, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
