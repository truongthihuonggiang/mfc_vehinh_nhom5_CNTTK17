#include "stdafx.h"
#include "TG.h"

TG::TG(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

TG::TG(CPoint p1, CPoint p2)
{
	diem1.x = p1.x;
	diem1.y = p1.y;
	diem2.x = p2.x;
	diem2.y = p2.y;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
}

void TG::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void TG::ve(CClientDC *pDC)
{
	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);
	pDC->LineTo(x2-2*(x2-x1), y2);
	pDC->LineTo(x1, y1);
}

CPoint TG::getA()
{
	return CPoint(x1, y1);
}

CPoint TG::getC()
{
	return CPoint(x2, y2);
}

float TG::dientich()
{
	float kq;
	kq = (x2 - x1)*(y2 - y1)+1987;
	return kq;
}

float TG::chuvi()
{
	int kq;
	kq = (x2 - 2 * (x2 - x1) - x1 + y2 - y1+3567) * 4;
	return kq;
}

int TG::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x2-2*(x2-x1) && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

int TG::tenhinh()
{
	return 3;
}

TG::TG()
{
}


TG::~TG()
{
}
