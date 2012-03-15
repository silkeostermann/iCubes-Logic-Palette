#include "ColorPalette.h"
#include <stdio.h>
#include <QtGui/QImage>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtGui/QImage>
#include <QtGui/QColor>
#include <QtCore/QRect>

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

	int redAmount		= 255 * ((float)redpoint.x/100);
	int greenAmount	= 255 * ((float)greenpoint.x/100);
	int blueAmount	= 255 * ((float)bluepoint.x/100);

	int redWidth = redAmount*492/255;
	int greenWidth = greenAmount*492/255;
	int blueWidth = blueAmount*492/255;

	// Prepare the UI images
	QImage *image = new QImage(QSize(640, 640), QImage::Format_RGB16);
	image->load("interface.jpg");
	QImage *ball = new QImage(QSize(52, 54), QImage::Format_RGB16);
	ball->load("ball.png");


	// Compose the color
	QColor *color = new QColor(redAmount, greenAmount, blueAmount, 255);
	printf("Composing the color: [%d, %d, %d] => %lu\n", redAmount, greenAmount, blueAmount, color->rgb());

	// Prepare the painter
	QPainter *painter = new QPainter(image);


	//Draw the section of a bar we need for each color
	QImage *redbar = new QImage(QSize(300, 20), QImage::Format_RGB16);
	redbar->load("Bar_Red.png");
	painter->drawImage(60, 185, (redbar->copy(0, 0, redWidth+10, 20)));

	QImage *greenbar = new QImage(QSize(300, 20), QImage::Format_RGB16);
	greenbar->load("Bar_Green.png");
	painter->drawImage(60, 267, (greenbar->copy(0, 0, greenWidth+10, 20)));

	QImage *bluebar = new QImage(QSize(300, 20), QImage::Format_RGB16);
	bluebar->load("Bar_Blue.png");
	painter->drawImage(60, 347, (bluebar->copy(0, 0, blueWidth+10, 20)));

	// Draw ball for each color
	painter->drawImage(redWidth+60, 180, *ball);
	painter->drawImage(greenWidth+60, 262, *ball);
	painter->drawImage(blueWidth+60, 342, *ball);

	// Draw the chosen color
	painter->fillRect(62, 445, 517, 106, color->rgb());

	// Save the image
	image->save("test.png");

}


//---------------------------------------------------------------
// Destructor.
// Releases used resources.
//---------------------------------------------------------------

ColorPalette::~ColorPalette ()
{

}

//void GetColor()
