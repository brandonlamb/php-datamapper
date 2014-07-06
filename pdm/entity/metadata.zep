
/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Entity
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Entity;

/**
 * Meta Data
 *
 * @package Pdm\Entity
 */
class MetaData
{
    const ATTRIBUTES        = 1;
    const PRIMARY_KEY       = 2;
    const NON_PRIMARY_KEY   = 3;
    const NOT_NULL          = 4;
    const DATA_TYPES        = 5;
    const DATA_TYPES_NUMERIC = 6;
    const DATA_TYPES_BIND   = 7;
    const IDENTITY_COLUMN   = 8;
    const IGNORE_INSERT     = 9;
    const IGNORE_UPDATE     = 10;
}
