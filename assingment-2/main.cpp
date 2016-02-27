#include <iostream>
#include "buffer.h"
#include "constants.h"
#include "neighborhood.h"
#include "shape.h"
int main() {

	// animate  neighborhood
	  unsigned int size_x = TERM_SIZE_X/Shape::size_x;
	  unsigned int size_y = TERM_SIZE_Y/Shape::size_y;
	  Neighborhood(size_x, size_y).animate(1000);

	return 0;
