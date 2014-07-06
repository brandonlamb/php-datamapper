
/**
 * Pdm\Db\RawValue
 *
 * This class allows to insert/update raw data without quoting or formating.
 *
 *The next example shows how to use the MySQL now() function as a field value.
 *
 *<code>
 *	$subscriber = new Subscribers();
 *	$subscriber->email = 'andres@phalconphp.com';
 *	$subscriber->createdAt = new \Pdm\Db\RawValue('now()');
 *	$subscriber->save();
 *</code>
 */

namespace Pdm\Db;

class RawValue
{
	/**
	 * Raw value without quoting or formating
	 *
	 * @var string
	 */
	protected value { get, __toString };

	/**
	 * Pdm\Db\RawValue constructor
	 *
	 * @param string value
	 */
	public function __construct(string! value)
	{
		let this->value = value;
	}
}
