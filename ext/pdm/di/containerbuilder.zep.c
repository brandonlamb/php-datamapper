
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Di
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Creates and configures a new DI container.
 *
 * @package Pdm\Di
 */
ZEPHIR_INIT_CLASS(Pdm_Di_ContainerBuilder) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Di, ContainerBuilder, pdm, di_containerbuilder, pdm_di_containerbuilder_method_entry, 0);

	return SUCCESS;

}

/**
 * Creates a new DI container, adds pre-existing service objects, applies
 * Config classes to define() services, locks the container, and applies
 * the Config instances to modify() services.
 *
 * @param array services Pre-existing service objects to set into the
 * container.
 * @return Container
 */
PHP_METHOD(Pdm_Di_ContainerBuilder, newInstance) {

	zephir_fcall_cache_entry *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *services = NULL, *di, *key = NULL, *val = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services);

	if (!services) {
		ZEPHIR_INIT_VAR(services);
		array_init(services);
	}


	ZEPHIR_INIT_VAR(di);
	object_init_ex(di, pdm_di_container_ce);
	ZEPHIR_CALL_METHOD(NULL, di, "__construct", NULL);
	zephir_check_call_status();
	zephir_is_iterable(services, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_METHOD(NULL, di, "set", &_3, key, val);
		zephir_check_call_status();
	}
	RETURN_CCTOR(di);

}

