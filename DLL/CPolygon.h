#pragma once
#include <Windows.h>

class CPolygon
{

public:
	int nLeftRect;
	int nTopRect;
	int nRightRect;
	int nBottomRect;
	HDC hdc;
	virtual BOOL draw(HWND hWnd) = 0;

};

