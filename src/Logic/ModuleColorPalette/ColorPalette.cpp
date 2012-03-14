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

	const Square *blue = 0;
	const Square *red = 0;
	const Square *green = 0;



	for (int i=0;i<size;i++)
	{
		if (recognizedSquares[i]->GetId()==1) {
			blue = recognizedSquares[i];
		}
		if (recognizedSquares[i]->GetId()==2) {
			red = recognizedSquares[i];
		}
		if (recognizedSquares[i]->GetId()==3) {
			green = recognizedSquares[i];
		}

	}

	CvPoint bluepoint = blue->GetCenterCoordinates();

	printf("Blue coordinates are %d, %d", bluepoint.x, bluepoint.y);

}


//---------------------------------------------------------------
// Destructor.
// Releases used resources.
//---------------------------------------------------------------

ColorPalette::~ColorPalette ()
{

}

//void GetColor()
