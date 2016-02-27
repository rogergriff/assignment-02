/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */
#ifndef BUFFER_H
#define BUFFER_H
// ----------------------------------------------------------------------------

#include <string>

// ----------------------------------------------------------------------------

class Buffer {
    private:
		char * data_;
		/**
		* Our character data.
		*
		* Since we don't know how big the array will be, we can't use a
		* regular (stack allocated) array.  In the constructor, this will be
		* initialized to a 1D array large enough to hold all the values, and
		* we will emulate using it as a 2D array by taking the index as
		* ```
		* data_[ y * size_x + x ];
		* ```
		* (where, if it were a real 2D array, we could have said
		* `data_[y][x]`).
		*/
        

    public:
        const unsigned int size_x;
        
        const unsigned int size_y;
        

        Buffer(unsigned int size_x, unsigned int size_y);
        ~Buffer();
        
        char get(unsigned int x, unsigned int y) const;
      
        void set(unsigned int x, unsigned int y, char c);
     
        void set(unsigned int pos_x, unsigned int pos_y, std::string s);

        void draw() const;
        
        void clear();
       
};

// ----------------------------------------------------------------------------
#endif
