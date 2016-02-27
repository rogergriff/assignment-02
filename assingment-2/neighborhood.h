/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H
// ----------------------------------------------------------------------------

#include "shape.h"

// ----------------------------------------------------------------------------

class Shape;
/**
 * Forward declare `Shape`, in case this file gets included first.
 *
 * This is definitely not the cleanest way to do things; but it seems to me
 * right now to be the simplest.
 */

// ----------------------------------------------------------------------------

class Neighborhood {
    private:
        Shape * neighborhood_;
        /**
         * The place where we'll store our 2D array of `Shape`s.
         *
         * Since we don't know how big the array will be, we can't use a
         * regular (stack allocated) array.  In the constructor, this will be
         * initialized to a 1D array large enough to hold all the values, and
         * we will emulate using it as a 2D array by taking the index as
         * ```
         * neighborhood_[ y * size_x + x ];
         * ```
         * (where, if it were a real 2D array, we could have said
         * `neighborhood_[y][x]`).
         */

    public:
        const unsigned int size_x;   //The number of "columns" (x values) in `neighborhood_`.

		const unsigned int size_y;  //The number of "rows" (y values) in `neighborhood_`
       

        Neighborhood(unsigned int size_x, unsigned int size_y);

        ~Neighborhood();      

		Shape get(unsigned int x, unsigned int y) const;

        void set(unsigned int x, unsigned int y, const Shape & s);

        void move(unsigned int old_x, unsigned int old_y);

        void animate(unsigned int frames);
     
};

// ----------------------------------------------------------------------------
#endif
