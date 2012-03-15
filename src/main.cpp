#include <stdio.h>
#include <QtGui/QImage>
#include <QtGui/QColor>
#include <QtGui/QFont>
#include <QtGui/QPainter>
#include <QtGui/QApplication>

#include "Recognition/Square.h"
#include "Logic/ModuleColorPalette/ColorPalette.h"


int main(int argc, char *argv[])
{
	QApplication *app = new QApplication(argc, argv);

	ColorPalette *palette = new ColorPalette();

	CvPoint p1 = cvPoint(0, 4);
	Square *sq1 = new Square(1, p1, 100, 6);

	CvPoint p2 = cvPoint(50, 4);
	Square *sq2 = new Square(2, p2, 50, 6);

	CvPoint p3 = cvPoint(100, 4);
	Square *sq3 = new Square(3, p3, 100, 6);

	Square *squares[3] = {sq1, sq2, sq3};

	palette->ProcessSquares((const Square **)squares, 3);

	return 0;
}
