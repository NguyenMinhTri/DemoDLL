#ifndef _DLL_TUTORIAL_H_
#define _DLL_TUTORIAL_H_
#include <iostream>
#include "CPolygon.h"
#include <vector>
#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

extern "C"
{
	DECLDIR int Add(std::vector<void*> &vectorInput, int b);
	DECLDIR void Draw(std::vector<void*> &vectorInput, HWND hWnd);

}

#endif