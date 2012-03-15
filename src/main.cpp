#include <stdio.h>
#include <QtGui/QImage>
#include <QtGui/QColor>

#include "Recognition/Square.h"
#include "Logic/ModuleColorPalette/ColorPalette.h"


int main(int argc, char *argv[])
{
	ColorPalette *palette = new ColorPalette();

	CvPoint p1 = cvPoint(0, 4);
	Square *sq1 = new Square(1, p1, 100, 6);

	CvPoint p2 = cvPoint(50, 4);
	Square *sq2 = new Square(2, p2, 50, 6);

	CvPoint p3 = cvPoint(100, 4);
	Square *sq3 = new Square(3, p3, 100, 6);

	Square *squares[3] = {sq1, sq2, sq3};

	palette->ProcessSquares((const Square **)squares, 3);

	int color1=0;
	int color2=128;
	int color3=255;

	QImage *image = new QImage(QSize(640, 640), QImage::Format_RGB16);
	QColor *color = new QColor(color1,color2,color3, 255);


	image->load("interface.png");

	//Draws a cube in the red slider
	for (int i=1; i<50; i++)
	{
		for (int j=1; j<50; j++)
		{
			image->setPixel(i+(color1*(640/255)),j+135,qRgb(0,0,0));
		}
	}
	//Draws a cube in the green slider
	for (int i=1; i<50; i++)
	{
		for (int j=1; j<50; j++)
		{
				image->setPixel(i+(color2*(640/255)),j+245,qRgb(0,0,0));
		}
	}

	//Draws a cube in the blue slider
	for (int i=1; i<50; i++)
	{
		for (int j=1; j<50; j++)
		{
			image->setPixel(i+(color3*(640/255)),j+357,qRgb(0,0,0));
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


	image->save("test.png");



    return 0;
}
