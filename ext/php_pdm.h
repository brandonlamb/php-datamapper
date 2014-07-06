
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PDM_H
#define PHP_PDM_H 1

#define ZEPHIR_RELEASE 1

#include "kernel/globals.h"

#define PHP_PDM_NAME        "pdm"
#define PHP_PDM_VERSION     "0.0.1"
#define PHP_PDM_EXTNAME     "pdm"
#define PHP_PDM_AUTHOR      ""
#define PHP_PDM_ZEPVERSION  "0.4.2a"
#define PHP_PDM_DESCRIPTION ""

typedef struct _zephir_struct_db { 
	zend_bool escape_identifiers;
} zephir_struct_db;

typedef struct _zephir_struct_orm { 
	zend_bool column_renaming;
	zend_bool events;
	int cache_level;
	zend_bool virtual_foreign_keys;
	zend_bool not_null_validations;
	zend_bool exception_on_failed_save;
	zend_bool enable_literals;
} zephir_struct_orm;



ZEND_BEGIN_MODULE_GLOBALS(pdm)

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
	zephir_struct_db db;

	zephir_struct_orm orm;


ZEND_END_MODULE_GLOBALS(pdm)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(pdm)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(pdm_globals_id, zend_pdm_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (pdm_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_pdm_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(pdm_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(pdm_globals)
#endif

#define zephir_globals_def pdm_globals
#define zend_zephir_globals_def zend_pdm_globals

extern zend_module_entry pdm_module_entry;
#define phpext_pdm_ptr &pdm_module_entry

#endif
