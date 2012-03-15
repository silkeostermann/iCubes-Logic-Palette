#include "ColorPalette.h"
#include <stdio.h>
#include <QtGui/QImage>
#include <QtGui/QColor>

#include <QtGui/QImage>
#include <QtGui/QColor>

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
//careful here: control repeated cubes, control not present cubes (defaulting?)


	CvPoint bluepoint	= blue->GetCenterCoordinates();
	CvPoint redpoint	= red->GetCenterCoordinates();
	CvPoint greenpoint	= green->GetCenterCoordinates();

	printf("xs of rgb: %d %d %d\n", redpoint.x, greenpoint.x, bluepoint.x);

	float redAmount		= 256 * ((float)redpoint.x/100);
	float greenAmount	= 256 * ((float)greenpoint.x/100);
	float blueAmount	= 256 * ((float)bluepoint.x/100);

	printf("Result: %f - %f - %f\n", redAmount, greenAmount, blueAmount);


	//new code from here



	QImage *image = new QImage(QSize(640, 640), QImage::Format_RGB16);
	QColor *color = new QColor(redAmount,greenAmount,blueAmount, 255);


	image->load("interface.png");

	//Draws a cube in the red slider
	for (int i=1; i<50; i++)
	{
		for (int j=1; j<50; j++)
		{
			image->setPixel(i+(redAmount*(640/255)),j+135,qRgb(0,0,0));
		}
	}
	//Draws a cube in the green slider
	for (int i=1; i<50; i++)
	{
		for (int j=1; j<50; j++)
		{
				image->setPixel(i+(greenAmount*(640/255)),j+245,qRgb(0,0,0));
		}
	}

	//Draws a cube in the blue slider
	for (int i=1; i<50; i++)
	{
		for (int j=1; j<50; j++)
		{
			image->setPixel(i+(blueAmount*(640/255)),j+357,qRgb(0,0,0));
		}
	}
	//Draws the chosen color
	for (int i=1; i<120; i++)
	{	for (int j=1; j<70; j++)
		{
			image->setPixel((i+250),j+500,color->rgb());
		}

	}

	//image->fill(color->rgb());


	image->save("secondtest.png");


}


//---------------------------------------------------------------
// Destructor.
// Releases used resources.
//---------------------------------------------------------------

ColorPalette::~ColorPalette ()
{

}

//void GetColor()
