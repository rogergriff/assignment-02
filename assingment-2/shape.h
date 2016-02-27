/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */
#ifndef SHAPE_H
#define SHAPE_H
// ----------------------------------------------------------------------------

#include <string>

#include "buffer.h"
#include "neighborhood.h"

// ----------------------------------------------------------------------------

class Neighborhood;
/**
 * Forward declare `Neighborhood`, in case this file gets included first.
 *
 * This is definitely not the cleanest way to do things; but it seems to me
 * right now to be the simplest.
 */

// ----------------------------------------------------------------------------

class Shape {
    private:
        std::string type_;
        /**
         * A string representing the "type" of the `Shape` (either "empty",
         * "triangle", or "square").
         *
         * Notes:
         * - It would be more "object oriented" to have separate `Empty`,
         *   `Triangle`, and `Square` types derived from this class.  But I
         *   decided that the complexity that introduced to the design wasn't
         *   worth it for this project.  Also, it's nice to try this method
         *   out, since it is a completely valid way to do things, and
         *   sometimes it turns out to be the best.  And don't worry: we'll get
         *   plenty of practice with inheritance later on.
         */

        
        /**
         * The ASCII art representing the type in `type_`.
         *
         * This should be set along with `type_` by the `setType` member
         * function.
         *
         * You may make your own ASCII art for each type, or you may use
         * - empty
         *   ```
         *   "     \n"
         *   "     \n"
         *   "     \n"
         *   ```
         * - triangle
         *   ```
         *   "  ,  \n" 
         *   " / \\ \n"
         *   "/___\\\n"
         *   ```
         * - square
         *   ```
         *   ".---.\n"
         *   "|   |\n"
         *   "'---'\n"
         *   ```
         *
         * Make sure that the number of rows and columns is the same for each
         * shape, and that it matches `size_x` (for columns) and `size_y` (for
         * rows).
         */


    public:
		std::string type_art_;
        static const unsigned int size_x = 5;  // must match actual size
       

        static const unsigned int size_y = 3;  // must match actual size
       


        Shape(const std::string & type = "Empty");
       

		~Shape();
       


        std::string getType();
       
        void setType(const std::string & type);
       

        void drawToBuffer(Buffer & b, unsigned int x, unsigned int y) const;
     
        bool isHappy(const Neighborhood & n, unsigned int x, unsigned int y ) const;
       
};

// ----------------------------------------------------------------------------
#endif

