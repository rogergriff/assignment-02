/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Roger Griffin <roger.griffin@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Implements `shape.h`.
 */

// TODO: `#include`s for system headers, if necessary
#include <iostream>
#include "shape.h"
#include "buffer.h"
#include "neighborhood.h"
#include "constants.h"
using std::string;
using std::cerr;

// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`

Shape::Shape(const string & type) : type_(type)
{
	setType(type);
}
/**
* The constructor.
*
* Must initialize `type_`, and `type_art_`.
*
* Notes:
* - I suggest calling `setType` in the body of the constructor, to
*   avoid duplicating code.
*/

Shape::~Shape(){}



string Shape::getType()
{
	return type_;
}
/**
* Return `type_`. done
*/

void Shape::setType(const string & type)
{
	type_ = type;
	if (type == "Square" || type == "Triangle" || type == "Empty")
	{
		if (type_ == "Square")
			type_art_ = ".---.\n|   |\n'---'\n";
		else if (type_ == "Triangle")
			type_art_ = "  ,  \n / \\ \n/___\\\n";
		else
			type_art_ = "     \n     \n     \n";
	}
	
	else{
		cerr << "ERROR:`Shape::setType`: invalid type\n";
		system("pause");
		exit(1);
	}
}
/**
* Set `type_` to `type`, and set `type_art_` to the appropriate value. done
*
* If the passed `type` is not valid, write                 done
* ```
* "ERROR: `Shape::setType`: invalid type\n"
* ```
* to `cerr` and `exit(1)`.
*/


void Shape::drawToBuffer(Buffer & b, unsigned int x, unsigned int y) const
{
	b.set(x, y, type_art_);
}
/**
* Draw `type_art_` onto the `Buffer` at position `x, y`. done
*
* Notes:
* - This (primarily) is what
*   ```
*   void Buffer::set(unsigned int, unsigned int, std::string);
*   ```
*   is for.
*/



bool Shape::isHappy(const Neighborhood & n, unsigned int pos_x,	unsigned int pos_y) const {

		if (n.get(pos_x, pos_y).getType() == "Empty")
			return true;

		unsigned int x_min = (pos_x == 0) ? pos_x : pos_x - 1;
		unsigned int y_min = (pos_y == 0) ? pos_y : pos_y - 1;

		unsigned int x_max = (pos_x == n.size_x - 1) ? pos_x : pos_x + 1;
		unsigned int y_max = (pos_y == n.size_y - 1) ? pos_y : pos_y + 1;

		double alike = 0;
		double different = 0;

		for (int x = x_min; x <= x_max; x++) {
			for (int y = y_min; y <= y_max; y++) {
				if (x == pos_x && y == pos_y)
					continue;
				else if (n.get(x, y).getType() == "Empty")
					continue;
				else if (n.get(x, y).getType() == n.get(pos_x, pos_y).getType())
					alike++;
				else
					different++;
			}
		}

		return    (different || alike)
			&& (different == 0 || alike / different >= RATIO_ALIKE_HAPPY)
			&& (alike == 0 || different / alike >= RATIO_DIFFERENT_HAPPY);
	}
/**
* Return `true` if the shape is happy (i.e. not willing to move), and
* `false` otherwise.
*
* - More specifically, return `true` if and only if the shape
*     - has more than 0 "triangle" or "square" neighbors
*     - and the ratio of like neighbors to unlike (different)
*       neighbors is greater than or equal to `RATIO_ALIKE_HAPPY`
*       (from `constants.h`)
*     - and the ratio of unlike (different) neighbors to like
*       neighbors is greater than or equal to `RATIO_DIFFERENT_HAPPY`
*       (from `constants.h`)
*
* Notes:
* - Use `n.get(...).getType() == "..."` to determine the type of the
*   `Shape` at a given position.
* - Be careful not to look for neighbors outside the bounds of the
*   `Neighborhood`.
* - Be careful not to have a shape count itself, when trying to count
*   its neighbors.
* - Be careful not to count "empty" shapes as unlike (different)
*   shapes ("empty" shapes should not count as either like or
*   unlike).
* - Be careful of possible division by 0 when testing the ratios of
*   like and unlike shapes.
*/
