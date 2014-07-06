
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
 * Db Adapter Exception class
 *
 * @package \Pdm\Db\Adapter
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Adapter, Exception, pdm, db_adapter_exception, pdm_db_exception_ce, NULL, 0);

	return SUCCESS;

}

