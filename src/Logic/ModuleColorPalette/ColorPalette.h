#ifndef OBJECT_PROCESSOR_H
#define OBJECT_PROCESSOR_H

#include <QtGui/QImage>
#include "../../Recognition/Square.h"
#include "../Image.h"

//---------------------------------------------------------------
// Represents logic implementation, such strange name because no concrete logic chosen yet
//---------------------------------------------------------------

class ColorPalette
{
 private:
	QImage *interface;
	QImage *ball;
	QImage *redbar;
	QImage *greenbar;
	QImage *bluebar;

 public:
	ColorPalette();
	~ColorPalette();

	void ProcessSquares (const Square **recognizedSquares, size_t size);

};

#endif
