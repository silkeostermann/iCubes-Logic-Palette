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
			red = recognizedSquares[i];
		}
		if (recognizedSquares[i]->GetId()==2) {
			green = recognizedSquares[i];
		}
		if (recognizedSquares[i]->GetId()==3) {
			blue = recognizedSquares[i];
		}

	}

	CvPoint bluepoint	= blue->GetCenterCoordinates();
	CvPoint redpoint	= red->GetCenterCoordinates();
	CvPoint greenpoint	= green->GetCenterCoordinates();

	printf("xs of rgb: %d %d %d\n", redpoint.x, greenpoint.x, bluepoint.x);

	float redAmount		= (float)256 * ((float)redpoint.x/(float)100);
	float greenAmount	= (float)256 * ((float)greenpoint.x/(float)100);
	float blueAmount	= (float)256 * ((float)bluepoint.x/(float)100);

	printf("Result: %f - %f - %f\n", redAmount, greenAmount, blueAmount);

}


//---------------------------------------------------------------
// Destructor.
// Releases used resources.
//---------------------------------------------------------------

ColorPalette::~ColorPalette ()
{

}

//void GetColor()
