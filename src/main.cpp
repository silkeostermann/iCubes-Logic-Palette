#include <stdio.h>

#include "Recognition/Square.h"
#include "Logic/ModuleColorPalette/ColorPalette.h"

int main(int argc, char *argv[])
{
	ColorPalette *palette = new ColorPalette();

	CvPoint p1 = cvPoint(3, 4);
	Square *sq1 = new Square(1, p1, 5, 6);

	CvPoint p2 = cvPoint(3, 4);
	Square *sq2 = new Square(2, p2, 5, 6);

	CvPoint p3 = cvPoint(3, 4);
	Square *sq3 = new Square(3, p3, 5, 6);

	Square *squares[3] = {sq1, sq2, sq3};
	palette->ProcessSquares((const Square **)squares, 3);

    return 0;
}
