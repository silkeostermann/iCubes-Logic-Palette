#include <stdio.h>

#include "Recognition/Square.h"
#include "Logic/ModuleColorPalette/ColorPalette.h"

int main(int argc, char *argv[])
{
	ColorPalette *palette = new ColorPalette();
	CvPoint p = cvPoint(3, 4);
	Square *sq1 = new Square(1, p, 5, 6);
	Square *squares[1] = {sq1};
	palette->ProcessSquares((const Square **)squares, 1);

    return 0;
}
