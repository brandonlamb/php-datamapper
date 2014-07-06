
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"


/**
 * Dependency Injection container
 *
 * @package \Pdm\Di
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Di_Container) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Di, Container, pdm, di_container, pdm_di_container_method_entry, 0);

	/**
	 * @var \Pdm\Di
	 */
	zend_declare_property_null(pdm_di_container_ce, SL("defaultInstance"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(pdm_di_container_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Shared objects for classes that should get instantiated only once such as a database object
	 * @var array
	 */
	zend_declare_property_null(pdm_di_container_ce, SL("sharedContainer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array, hold parameters
	 */
	zend_declare_property_null(pdm_di_container_ce, SL("paramContainer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_di_container_ce TSRMLS_CC, 1, pdm_di_containerinterface_ce);
	return SUCCESS;

}

/**
 * Accept an array as a container to populate
 *
 * @param array $container
 * @param array $sharedContainer
 * @param array $paramContainer
 */
PHP_METHOD(Pdm_Di_Container, __construct) {

	zval *container = NULL, *sharedContainer = NULL, *paramContainer = NULL, *defaultInstance = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &container, &sharedContainer, &paramContainer);

	if (!container) {
		container = ZEPHIR_GLOBAL(global_null);
	}
	if (!sharedContainer) {
		sharedContainer = ZEPHIR_GLOBAL(global_null);
	}
	if (!paramContainer) {
		paramContainer = ZEPHIR_GLOBAL(global_null);
	}


	zephir_read_static_property_ce(&_0, pdm_di_container_ce, SL("defaultInstance") TSRMLS_CC);
	ZEPHIR_CPY_WRT(defaultInstance, _0);
	if (!(zephir_is_true(defaultInstance))) {
		zephir_update_static_property_ce(pdm_di_container_ce, SL("defaultInstance"), this_ptr TSRMLS_CC);
	}
	if (Z_TYPE_P(container) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("container"), container TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("container"), _1 TSRMLS_CC);
	}
	if (Z_TYPE_P(sharedContainer) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("sharedContainer"), sharedContainer TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("sharedContainer"), _1 TSRMLS_CC);
	}
	if (Z_TYPE_P(paramContainer) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("paramContainer"), paramContainer TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("paramContainer"), _1 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic getter to access container objects
 *
 * @param string offset
 * @return mixed
 */
PHP_METHOD(Pdm_Di_Container, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getshared", NULL, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic getter to set container objects
 *
 * @param string offset
 * @param mixed value
 */
PHP_METHOD(Pdm_Di_Container, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *value;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, offset, value, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set an object into the container
 *
 * @param string offset
 * @param mixed value
 * @throws \Pdm\Exception
 * @return \Pdm\Di\ContainerInterface
 */
PHP_METHOD(Pdm_Di_Container, set) {

	zend_bool shared, _0;
	zval *offset_param = NULL, *value, *shared_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &offset_param, &value, &shared_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	_0 = Z_TYPE_P(value) == IS_ARRAY;
	if (_0) {
		_0 = !zephir_array_isset_string(value, SS("className"));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_di_exception_ce, "Must contain a className key.", "pdm/di/container.zep", 103);
		return;
	}
	if (!(shared)) {
		zephir_update_property_array(this_ptr, SL("container"), offset, value TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("sharedContainer"), offset, value TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Set an object/value into the parameter container
 *
 * @param string offset
 * @param mixed value
 * @return \Pdm\Di\ContainerInterface
 */
PHP_METHOD(Pdm_Di_Container, setParam) {

	zval *offset_param = NULL, *value;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	zephir_update_property_array(this_ptr, SL("paramContainer"), offset, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get an object from the container
 *
 * @param string offset
 * @throws \Pdm\Di\Exception\ServiceNotFound
 * @return mixed
 */
PHP_METHOD(Pdm_Di_Container, get) {

	zend_class_entry *_3, *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *service, *className, *instance, *_0, *_1;
	zval *offset = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	ZEPHIR_OBS_VAR(service);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&service, _0, offset, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, pdm_di_exception_servicenotfound_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VS(_2, offset, " is not defined.");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "pdm/di/container.zep", 142 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(service) == IS_STRING) {
		_3 = zend_fetch_class(Z_STRVAL_P(service), Z_STRLEN_P(service), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(service) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(className);
		if (zephir_array_isset_string_fetch(&className, service, SS("className"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(instance);
			_4 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(instance, _4);
			if (zephir_has_constructor(instance TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL, service);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(instance) == IS_OBJECT) {
				if (zephir_instance_of_ev(instance, pdm_di_injectionawareinterface_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, instance, "setdi", NULL, this_ptr);
					zephir_check_call_status();
				}
			}
			RETURN_CCTOR(instance);
		}
	}
	if (Z_TYPE_P(service) == IS_OBJECT) {
		if (zephir_instance_of_ev(service, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(service, NULL);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_CCTOR(service);

}

/**
 * Get an object from the shared container
 *
 * @param string offset
 * @return mixed
 */
PHP_METHOD(Pdm_Di_Container, getShared) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *instance = NULL, *_0;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	ZEPHIR_OBS_VAR(instance);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sharedContainer"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&instance, _0, offset, 0 TSRMLS_CC)) {
		RETURN_CCTOR(instance);
	}
	ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, offset);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("sharedContainer"), offset, instance TSRMLS_CC);
	RETURN_CCTOR(instance);

}

/**
 * Get an object from the param container
 *
 * @param string offset
 * @throws \Pdm\Di\Exception\ParamterNotFound
 * @return mixed
 */
PHP_METHOD(Pdm_Di_Container, getParam) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *param, *_0, *_1;
	zval *offset = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	ZEPHIR_OBS_VAR(param);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("paramContainer"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&param, _0, offset, 0 TSRMLS_CC)) {
		RETURN_CCTOR(param);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, pdm_di_exception_parameternotfound_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "Parameter ", offset, " not set");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "pdm/di/container.zep", 214 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Remove an object from the container
 *
 * @param string offset
 * @throws Exception
 * @return DiInterface
 */
PHP_METHOD(Pdm_Di_Container, remove) {

	zval *offset_param = NULL, *_0, *_1, *_2;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	if (zephir_array_isset(_0, offset)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		zephir_array_unset(&_1, offset, PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("sharedContainer"), PH_NOISY_CC);
	if (zephir_array_isset(_1, offset)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("sharedContainer"), PH_NOISY_CC);
		zephir_array_unset(&_2, offset, PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("paramContainer"), PH_NOISY_CC);
	if (zephir_array_isset(_1, offset)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("paramContainer"), PH_NOISY_CC);
		zephir_array_unset(&_2, offset, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * Set the default Di container to return by getDefault()
 *
 * @param DiInterface $di
 * @return DiInterface
 */
PHP_METHOD(Pdm_Di_Container, setDefault) {

	zval *di;

	zephir_fetch_params(0, 1, 0, &di);



	if (!(zephir_instance_of_ev(di, pdm_di_containerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'di' must be an instance of 'Pdm\\Di\\ContainerInterface'", "", 0);
		return;
	}
	zephir_update_static_property_ce(pdm_di_container_ce, SL("defaultInstance"), di TSRMLS_CC);
	RETURN_CCTORW(di);

}

/**
 * Returns the default Di container instance, or if one was not created
 * then created a new instance and set the default
 *
 * @return DiInterface
 */
PHP_METHOD(Pdm_Di_Container, getDefault) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(pdm_di_container_ce, SL("defaultInstance") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Check if the container contains the index
 *
 * @param string offset
 * @return bool
 */
PHP_METHOD(Pdm_Di_Container, has) {

	zval *offset_param = NULL, *_0;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, offset));

}

/**
 * Check if the shared container contains the index
 *
 * @param string offset
 * @return bool
 */
PHP_METHOD(Pdm_Di_Container, hasShared) {

	zval *offset_param = NULL, *_0;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sharedContainer"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, offset));

}

/**
 * Check if the param container contains the index
 *
 * @param string offset
 * @return bool
 */
PHP_METHOD(Pdm_Di_Container, hasParam) {

	zval *offset_param = NULL, *_0;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(offset_param) == IS_STRING)) {
		offset = offset_param;
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("paramContainer"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, offset));

}

/**
 * Gets the list of shared services provided.
 *
 * @return array
 */
PHP_METHOD(Pdm_Di_Container, getSharedServices) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sharedContainer"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

/**
 * Gets the list of service definitions.
 *
 * @return array
 */
PHP_METHOD(Pdm_Di_Container, getServices) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

/**
 * Gets the list of parameters.
 *
 * @return array
 */
PHP_METHOD(Pdm_Di_Container, getParams) {


	RETURN_MEMBER(this_ptr, "paramContainer");

}

