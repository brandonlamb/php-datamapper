
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


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Di
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Generic package exception.
 *
 * @package Pdm\Di
 */
ZEPHIR_INIT_CLASS(Pdm_Di_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Di, Exception, pdm, di_exception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

