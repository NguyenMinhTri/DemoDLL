#pragma once
#include "CPolygon.h"
class Ellipse :
	public CPolygon
{
public:
	BOOL draw(HWND hWnd) {
		BOOL result;
		hdc = GetDC(hWnd);
		result = ::Ellipse(hdc, this->nLeftRect, this->nTopRect, this->nRightRect, this->nBottomRect);
		ReleaseDC(hWnd, hdc);
		return result;
	}
};

