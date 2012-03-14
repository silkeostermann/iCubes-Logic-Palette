#include "ColorPalette.h"
#include <stdio.h>

// Here goes member definition


//---------------------------------------------------------------
// Slot to subscribe for event.
// Expects to receive array of pointers on quadrilaterals instances which were recognized
//---------------------------------------------------------------

void ColorPalette::ProcessSquares (const Square **recognizedSquares, size_t size)
{
	printf("Processing %d squares.\n", (int)size);

	Square *blue = 0;
	Square *red = 0;
	Square *green = 0;


}


//---------------------------------------------------------------
// Destructor.
// Releases used resources.
//---------------------------------------------------------------

ColorPalette::~ColorPalette ()
{

}

//void GetColor()
