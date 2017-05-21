#pragma once
#include "CPolygon.h"

class CRectangle : public CPolygon
{
public:
	BOOL draw(HWND hWnd) {
		BOOL result;
		hdc = GetDC(hWnd);
		result = ::Rectangle(hdc, this->nLeftRect, this->nTopRect, this->nRightRect, this->nBottomRect);
		ReleaseDC(hWnd, hdc);
		return result;
	}

};

