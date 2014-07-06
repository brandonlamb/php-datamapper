
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
 * Interface for query profilers.
 *
 * @package Pdm\Db
 */
ZEPHIR_INIT_CLASS(Pdm_Db_ProfilerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Db, ProfilerInterface, pdm, db_profilerinterface, pdm_db_profilerinterface_method_entry);

	return SUCCESS;

}

/**
 * Turns the profiler on and off.
 *
 * @param bool $active True to turn on, false to turn off.
 * @return void
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ProfilerInterface, setActive);

/**
 * Is the profiler active?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ProfilerInterface, isActive);

/**
 * Adds a profile entry.
 *
 * @param float $duration The query duration.
 * @param string $functionName The PDO method that made the entry.
 * @param string $statement The SQL query statement.
 * @param array $bind_values The values bound to the statement.
 * @return void
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ProfilerInterface, addProfile);

/**
 * Returns all the profiles.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Db_ProfilerInterface, getProfiles);

