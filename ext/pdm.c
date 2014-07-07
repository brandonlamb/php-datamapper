
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "pdm.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"

zend_class_entry *pdm_query_common_limitinterface_ce;
zend_class_entry *pdm_db_adapterinterface_ce;
zend_class_entry *pdm_db_columninterface_ce;
zend_class_entry *pdm_db_connectionlocatorinterface_ce;
zend_class_entry *pdm_db_dialectinterface_ce;
zend_class_entry *pdm_db_pdointerface_ce;
zend_class_entry *pdm_db_profilerinterface_ce;
zend_class_entry *pdm_db_resultinterface_ce;
zend_class_entry *pdm_di_containerinterface_ce;
zend_class_entry *pdm_di_injectionawareinterface_ce;
zend_class_entry *pdm_entity_entityinterface_ce;
zend_class_entry *pdm_query_common_limitoffsetinterface_ce;
zend_class_entry *pdm_query_common_orderbyinterface_ce;
zend_class_entry *pdm_query_common_selectinterface_ce;
zend_class_entry *pdm_query_queryinterface_ce;
zend_class_entry *pdm_db_abstractadapter_ce;
zend_class_entry *pdm_db_abstractdialect_ce;
zend_class_entry *pdm_db_adapter_abstractpdo_ce;
zend_class_entry *pdm_di_exception_ce;
zend_class_entry *pdm_db_exception_ce;
zend_class_entry *pdm_query_abstractquery_ce;
zend_class_entry *pdm_autoload_loader_ce;
zend_class_entry *pdm_db_abstractdb_ce;
zend_class_entry *pdm_db_adapter_exception_ce;
zend_class_entry *pdm_db_adapter_pdo_db2_ce;
zend_class_entry *pdm_db_adapter_pdo_mysql_ce;
zend_class_entry *pdm_db_adapter_pdo_oracle_ce;
zend_class_entry *pdm_db_adapter_pdo_pgsql_ce;
zend_class_entry *pdm_db_adapter_pdo_sqlite_ce;
zend_class_entry *pdm_db_bindtracker_ce;
zend_class_entry *pdm_db_column_ce;
zend_class_entry *pdm_db_connectionlocator_ce;
zend_class_entry *pdm_db_dialect_db2_ce;
zend_class_entry *pdm_db_dialect_mysql_ce;
zend_class_entry *pdm_db_dialect_oracle_ce;
zend_class_entry *pdm_db_dialect_pgsql_ce;
zend_class_entry *pdm_db_dialect_sqlite_ce;
zend_class_entry *pdm_db_exception_connectionnotfound_ce;
zend_class_entry *pdm_db_pdo_ce;
zend_class_entry *pdm_db_profiler_ce;
zend_class_entry *pdm_db_rawvalue_ce;
zend_class_entry *pdm_db_result_pdo_ce;
zend_class_entry *pdm_di_container_ce;
zend_class_entry *pdm_di_containerbuilder_ce;
zend_class_entry *pdm_di_exception_parameternotfound_ce;
zend_class_entry *pdm_di_exception_servicenotfound_ce;
zend_class_entry *pdm_di_exception_servicenotobject_ce;
zend_class_entry *pdm_entity_abstractentity_ce;
zend_class_entry *pdm_entity_metadata_ce;
zend_class_entry *pdm_query_common_select_ce;
zend_class_entry *pdm_query_exception_ce;
zend_class_entry *pdm_query_queryfactory_ce;

ZEND_DECLARE_MODULE_GLOBALS(pdm)

#define ZEPHIR_NUM_PREALLOCATED_FRAMES 25

void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr TSRMLS_DC)
{
	zephir_memory_entry *start;
	size_t i;

	start = (zephir_memory_entry *) pecalloc(ZEPHIR_NUM_PREALLOCATED_FRAMES, sizeof(zephir_memory_entry), 1);
/* pecalloc() will take care of these members for every frame
	start->pointer      = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		start[i].addresses       = pecalloc(24, sizeof(zval*), 1);
		start[i].capacity        = 24;
		start[i].hash_addresses  = pecalloc(8, sizeof(zval*), 1);
		start[i].hash_capacity   = 8;

#ifndef ZEPHIR_RELEASE
		start[i].permanent = 1;
#endif
	}

	start[0].next = &start[1];
	start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 1].prev = &start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 2];

	for (i = 1; i < ZEPHIR_NUM_PREALLOCATED_FRAMES - 1; ++i) {
		start[i].next = &start[i + 1];
		start[i].prev = &start[i - 1];
	}

	zephir_globals_ptr->start_memory = start;
	zephir_globals_ptr->end_memory   = start + ZEPHIR_NUM_PREALLOCATED_FRAMES;

	zephir_globals_ptr->fcache = pemalloc(sizeof(HashTable), 1);
	zend_hash_init(zephir_globals_ptr->fcache, 128, NULL, NULL, 1); // zephir_fcall_cache_dtor

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_null);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_null, 2);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_false);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_false, 2);
	ZVAL_FALSE(zephir_globals_ptr->global_false);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_true);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_true, 2);
	ZVAL_TRUE(zephir_globals_ptr->global_true);

	//zephir_globals_ptr->initialized = 1;
}

int zephir_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**)pDest;
	zend_class_entry *scope;
	uint len = hash_key->nKeyLength;

	assert(hash_key->arKey != NULL);
	assert(hash_key->nKeyLength > 2 * sizeof(zend_class_entry**));

	memcpy(&scope, &hash_key->arKey[len - 2 * sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

/*
#ifndef ZEPHIR_RELEASE
	{
		zend_class_entry *cls;
		memcpy(&cls, &hash_key->arKey[len - sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

		fprintf(stderr, "func: %s, cls: %s, scope: %s [%u]\n", (*entry)->f->common.function_name, (cls ? cls->name : "N/A"), (scope ? scope->name : "N/A"), (uint)(*entry)->times);
	}
#endif
*/

#ifndef ZEPHIR_RELEASE
	if ((*entry)->f->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

#if PHP_VERSION_ID >= 50400
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

	return ZEND_HASH_APPLY_KEEP;
}

void zephir_deinitialize_memory(TSRMLS_D)
{
	size_t i;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	//if (zephir_globals_ptr->initialized != 1) {
	//	zephir_globals_ptr->initialized = 0;
	//	return;
	//}

	if (zephir_globals_ptr->start_memory != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	//zephir_orm_destroy_cache(TSRMLS_C);

	zend_hash_apply_with_arguments(zephir_globals_ptr->fcache TSRMLS_CC, zephir_cleanup_fcache, 0);

#ifndef ZEPHIR_RELEASE
	assert(zephir_globals_ptr->start_memory != NULL);
#endif

	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		pefree(zephir_globals_ptr->start_memory[i].hash_addresses, 1);
		pefree(zephir_globals_ptr->start_memory[i].addresses, 1);
	}

	pefree(zephir_globals_ptr->start_memory, 1);
	zephir_globals_ptr->start_memory = NULL;

	zend_hash_destroy(zephir_globals_ptr->fcache);
	pefree(zephir_globals_ptr->fcache, 1);
	zephir_globals_ptr->fcache = NULL;

	for (i = 0; i < 2; i++) {
		zval_ptr_dtor(&zephir_globals_ptr->global_null);
		zval_ptr_dtor(&zephir_globals_ptr->global_false);
		zval_ptr_dtor(&zephir_globals_ptr->global_true);
	}

	//zephir_globals_ptr->initialized = 0;
}

static PHP_MINIT_FUNCTION(pdm)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Pdm_Query_Common_LimitInterface);
	ZEPHIR_INIT(Pdm_Db_AdapterInterface);
	ZEPHIR_INIT(Pdm_Db_ColumnInterface);
	ZEPHIR_INIT(Pdm_Db_ConnectionLocatorInterface);
	ZEPHIR_INIT(Pdm_Db_DialectInterface);
	ZEPHIR_INIT(Pdm_Db_PdoInterface);
	ZEPHIR_INIT(Pdm_Db_ProfilerInterface);
	ZEPHIR_INIT(Pdm_Db_ResultInterface);
	ZEPHIR_INIT(Pdm_Di_ContainerInterface);
	ZEPHIR_INIT(Pdm_Di_InjectionAwareInterface);
	ZEPHIR_INIT(Pdm_Entity_EntityInterface);
	ZEPHIR_INIT(Pdm_Query_Common_LimitOffsetInterface);
	ZEPHIR_INIT(Pdm_Query_Common_OrderByInterface);
	ZEPHIR_INIT(Pdm_Query_Common_SelectInterface);
	ZEPHIR_INIT(Pdm_Query_QueryInterface);
	ZEPHIR_INIT(Pdm_Db_AbstractAdapter);
	ZEPHIR_INIT(Pdm_Db_AbstractDialect);
	ZEPHIR_INIT(Pdm_Db_Adapter_AbstractPdo);
	ZEPHIR_INIT(Pdm_Di_Exception);
	ZEPHIR_INIT(Pdm_Db_Exception);
	ZEPHIR_INIT(Pdm_Query_AbstractQuery);
	ZEPHIR_INIT(Pdm_Autoload_Loader);
	ZEPHIR_INIT(Pdm_Db_AbstractDb);
	ZEPHIR_INIT(Pdm_Db_Adapter_Exception);
	ZEPHIR_INIT(Pdm_Db_Adapter_Pdo_Db2);
	ZEPHIR_INIT(Pdm_Db_Adapter_Pdo_Mysql);
	ZEPHIR_INIT(Pdm_Db_Adapter_Pdo_Oracle);
	ZEPHIR_INIT(Pdm_Db_Adapter_Pdo_Pgsql);
	ZEPHIR_INIT(Pdm_Db_Adapter_Pdo_Sqlite);
	ZEPHIR_INIT(Pdm_Db_BindTracker);
	ZEPHIR_INIT(Pdm_Db_Column);
	ZEPHIR_INIT(Pdm_Db_ConnectionLocator);
	ZEPHIR_INIT(Pdm_Db_Dialect_Db2);
	ZEPHIR_INIT(Pdm_Db_Dialect_MySQL);
	ZEPHIR_INIT(Pdm_Db_Dialect_Oracle);
	ZEPHIR_INIT(Pdm_Db_Dialect_Pgsql);
	ZEPHIR_INIT(Pdm_Db_Dialect_Sqlite);
	ZEPHIR_INIT(Pdm_Db_Exception_ConnectionNotFound);
	ZEPHIR_INIT(Pdm_Db_Pdo);
	ZEPHIR_INIT(Pdm_Db_Profiler);
	ZEPHIR_INIT(Pdm_Db_RawValue);
	ZEPHIR_INIT(Pdm_Db_Result_Pdo);
	ZEPHIR_INIT(Pdm_Di_Container);
	ZEPHIR_INIT(Pdm_Di_ContainerBuilder);
	ZEPHIR_INIT(Pdm_Di_Exception_ParameterNotFound);
	ZEPHIR_INIT(Pdm_Di_Exception_ServiceNotFound);
	ZEPHIR_INIT(Pdm_Di_Exception_ServiceNotObject);
	ZEPHIR_INIT(Pdm_Entity_AbstractEntity);
	ZEPHIR_INIT(Pdm_Entity_MetaData);
	ZEPHIR_INIT(Pdm_Query_Common_Select);
	ZEPHIR_INIT(Pdm_Query_Exception);
	ZEPHIR_INIT(Pdm_Query_QueryFactory);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(pdm)
{

	zephir_deinitialize_memory(TSRMLS_C);

	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_pdm_globals *zephir_globals TSRMLS_DC)
{

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;

	zephir_globals->db.escape_identifiers = 1;
	zephir_globals->orm.column_renaming = 1;
	zephir_globals->orm.events = 1;
	zephir_globals->orm.cache_level = 3;
	zephir_globals->orm.virtual_foreign_keys = 1;
	zephir_globals->orm.not_null_validations = 1;
	zephir_globals->orm.exception_on_failed_save = 0;
	zephir_globals->orm.enable_literals = 1;

}

static PHP_RINIT_FUNCTION(pdm)
{

	zend_pdm_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(pdm)
{

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(pdm)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PDM_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PDM_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PDM_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PDM_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PDM_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(pdm)
{
	php_zephir_init_globals(pdm_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(pdm)
{

}

zend_module_entry pdm_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PDM_EXTNAME,
	NULL,
	PHP_MINIT(pdm),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(pdm),
#else
	NULL,
#endif
	PHP_RINIT(pdm),
	PHP_RSHUTDOWN(pdm),
	PHP_MINFO(pdm),
	PHP_PDM_VERSION,
	ZEND_MODULE_GLOBALS(pdm),
	PHP_GINIT(pdm),
	PHP_GSHUTDOWN(pdm),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PDM
ZEND_GET_MODULE(pdm)
#endif
