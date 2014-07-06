
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Pdm\Di\InjectionAwareInterface
 *
 * This interface must be implemented in those classes that uses internally the Pdm\Di that creates them
 */
ZEPHIR_INIT_CLASS(Pdm_Di_InjectionAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Di, InjectionAwareInterface, pdm, di_injectionawareinterface, pdm_di_injectionawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 *
 * @param Pdm\Di\ContainerInterface di
 */
ZEPHIR_DOC_METHOD(Pdm_Di_InjectionAwareInterface, setDi);

/**
 * Returns the internal dependency injector
 *
 * @return Pdm\Di\ContainerInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Di_InjectionAwareInterface, getDi);

