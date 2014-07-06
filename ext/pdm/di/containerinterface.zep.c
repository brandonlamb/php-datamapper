
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Di
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Interface for dependency injection containers.
 *
 * @package Pdm\Di
 */
ZEPHIR_INIT_CLASS(Pdm_Di_ContainerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Di, ContainerInterface, pdm, di_containerinterface, pdm_di_containerinterface_method_entry);

	return SUCCESS;

}

/**
 * Registers a service in the services container
 *
 * @param string offset
 * @param mixed definition
 * @param boolean shared
 * @return Pdm\Di\ContainerInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, set);

/**
 * Removes a service in the services container
 *
 * @param string offset
 * @return \Pdm\Di\ContainerInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, remove);

/**
 * Resolves the service based on its configuration
 *
 * @param string offset
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, get);

/**
 * Returns a shared service based on their configuration
 *
 * @param string offset
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, getShared);

/**
 * Check whether the DI contains a service by a name
 *
 * @param string offset The service key to look up.
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, has);

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Pdm\Di\ContainerInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, setDefault);

/**
 * Return the last DI created
 *
 * @return Pdm\Di\ContainerInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, getDefault);

/**
 * Gets the list of shared services provided.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, getSharedServices);

/**
 * Gets the list of service definitions.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, getServices);

/**
 * Gets the list of parameters.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Di_ContainerInterface, getParams);

