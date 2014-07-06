PHP_ARG_ENABLE(pdm, whether to enable pdm, [ --enable-pdm   Enable Pdm])

if test "$PHP_PDM" = "yes"; then
	AC_DEFINE(HAVE_PDM, 1, [Whether you have Pdm])
	pdm_sources="pdm.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c pdm/autoload/loader.zep.c
	pdm/db/abstractadapter.zep.c
	pdm/db/abstractdb.zep.c
	pdm/db/abstractdialect.zep.c
	pdm/db/adapter/abstractpdo.zep.c
	pdm/db/adapter/exception.zep.c
	pdm/db/adapter/pdo/db2.zep.c
	pdm/db/adapter/pdo/mysql.zep.c
	pdm/db/adapter/pdo/oracle.zep.c
	pdm/db/adapter/pdo/pgsql.zep.c
	pdm/db/adapter/pdo/sqlite.zep.c
	pdm/db/adapterinterface.zep.c
	pdm/db/bindtracker.zep.c
	pdm/db/column.zep.c
	pdm/db/columninterface.zep.c
	pdm/db/connectionlocator.zep.c
	pdm/db/connectionlocatorinterface.zep.c
	pdm/db/dialect/db2.zep.c
	pdm/db/dialect/mysql.zep.c
	pdm/db/dialect/oracle.zep.c
	pdm/db/dialect/pgsql.zep.c
	pdm/db/dialect/sqlite.zep.c
	pdm/db/dialectinterface.zep.c
	pdm/db/exception.zep.c
	pdm/db/exception/connectionnotfound.zep.c
	pdm/db/pdo.zep.c
	pdm/db/pdointerface.zep.c
	pdm/db/profiler.zep.c
	pdm/db/profilerinterface.zep.c
	pdm/db/rawvalue.zep.c
	pdm/db/result/pdo.zep.c
	pdm/db/resultinterface.zep.c
	pdm/di/container.zep.c
	pdm/di/containerbuilder.zep.c
	pdm/di/containerinterface.zep.c
	pdm/di/exception.zep.c
	pdm/di/exception/parameternotfound.zep.c
	pdm/di/exception/servicenotfound.zep.c
	pdm/di/exception/servicenotobject.zep.c
	pdm/di/injectionawareinterface.zep.c
	pdm/entity/abstractentity.zep.c
	pdm/entity/entityinterface.zep.c
	pdm/entity/metadata.zep.c "
	PHP_NEW_EXTENSION(pdm, $pdm_sources, $ext_shared)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([pdm], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([pdm], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS
fi
