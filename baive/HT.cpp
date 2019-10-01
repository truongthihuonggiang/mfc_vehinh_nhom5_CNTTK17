#include "stdafx.h"
#include "HT.h"

HT::HT(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

HT::HT(CPoint p1, CPoint p2)
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

void HT::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void HT::ve(CClientDC *pDC)
{
	pDC->Ellipse(x1, y1, x2, y2);
}

CPoint HT::getA()
{
	return CPoint(x1, y1);
}

CPoint HT::getC()
{
	return CPoint(x2, y2);
}

float HT::dientich()
{
	float kq;
	kq = (x2 - x1)*(y2 - y1);
	return kq;
}

float HT::chuvi()
{
	int kq;
	kq = (x2 - x1 + y2 - y1) * 2;
	return kq;
}

int HT::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

int HT::tenhinh()
{
	return 2;
}

HT::HT()
{
}


HT::~HT()
{
}
