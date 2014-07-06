
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
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Locator could not find a named connection.
 *
 * @package Pdm\Db
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Exception_ConnectionNotFound) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Exception, ConnectionNotFound, pdm, db_exception_connectionnotfound, pdm_db_exception_ce, NULL, 0);

	return SUCCESS;

}

