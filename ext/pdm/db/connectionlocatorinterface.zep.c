
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
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Locates PDO connections for default, read, and write databases.
 *
 * @package Pdm\Db
 */
ZEPHIR_INIT_CLASS(Pdm_Db_ConnectionLocatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Db, ConnectionLocatorInterface, pdm, db_connectionlocatorinterface, pdm_db_connectionlocatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the default connection registry entry.
 *
 * @param callable $callback The registry entry.
 * @return void
 *
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ConnectionLocatorInterface, setDefault);

/**
 * Returns the default connection object.
 *
 * @return PdoInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ConnectionLocatorInterface, getDefault);

/**
 * Sets a read connection registry entry by name.
 *
 * @param string $name The name of the registry entry.
 * @param callable $callback The registry entry.
 * @return void
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ConnectionLocatorInterface, setRead);

/**
 * Returns a read connection by name; if no name is given, picks a
 * random connection; if no read connections are present, returns the
 * default connection.
 *
 * @param string $name The read connection name to return.
 * @return PdoInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ConnectionLocatorInterface, getRead);

/**
 * Sets a write connection registry entry by name.
 *
 * @param string $name The name of the registry entry.
 * @param callable $callback The registry entry.
 * @return void
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ConnectionLocatorInterface, setWrite);

/**
 * Returns a write connection by name; if no name is given, picks a
 * random connection; if no write connections are present, returns the
 * default connection.
 *
 * @param string $name The write connection name to return.
 * @return PdoInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ConnectionLocatorInterface, getWrite);

