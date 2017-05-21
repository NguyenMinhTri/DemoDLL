// Access to std::cout and std::endl
#include <iostream>
#include "CRectangle.h"
// DECLDIR will perform an export for us
#define DLL_EXPORT

// Include our header, must come after #define DLL_EXPORT
#include "DLLTutorial.h"

// Get rid of name mangeling
extern "C"
{
	// Define our 2 functions
	// Add will return the sum of two numbers
	DECLDIR int Add(std::vector<void*> &vectorInput, int b)
	{
		CRectangle * demo = new CRectangle();
		demo->nBottomRect = 10;
		demo->nRightRect = 10;
		vectorInput.push_back(static_cast<CRectangle *>(demo));
		return( b);
	}

	// Function will print out a text string
	DECLDIR void Draw(std::vector<void*> &vectorInput, HWND hWnd)
	{
		for each (void* attack in vectorInput) // Problem part
		{
			attack = static_cast<CPolygon*>(attack);

		}
	}
}