
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Di
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * The service definition is not valid.
 *
 * @package Pdm\Di
 */
ZEPHIR_INIT_CLASS(Pdm_Di_Exception_ServiceNotObject) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Di\\Exception, ServiceNotObject, pdm, di_exception_servicenotobject, pdm_di_exception_ce, NULL, 0);

	return SUCCESS;

}

