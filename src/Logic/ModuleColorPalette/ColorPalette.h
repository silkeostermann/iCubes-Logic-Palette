#ifndef OBJECT_PROCESSOR_H
#define OBJECT_PROCESSOR_H

#include "../../Recognition/Square.h"
#include "../Image.h"
//---------------------------------------------------------------
// Represents logic implementation, such strange name because no concrete logic chosen yet
//---------------------------------------------------------------

class ColorPalette
{
	public:
		~ColorPalette ();

		void ProcessSquares (const Square **recognizedSquares, size_t size);

};

#endif
