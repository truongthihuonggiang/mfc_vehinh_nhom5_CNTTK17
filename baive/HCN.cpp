#include "stdafx.h"
#include "HCN.h"

HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

HCN::HCN(CPoint p1, CPoint p2)
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

void HCN::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void HCN::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1, y1, x2, y2);
}

CPoint HCN::getA()
{
	return CPoint(x1, y1);
}

CPoint HCN::getC()
{
	return CPoint(x2, y2);
}

float HCN::dientich()
{
	float kq;
	kq = (x2 - x1)*(y2 - y1);
	return kq;
}

float HCN::chuvi()
{
	int kq;
	kq = (x2-x1+y2-y1)*2;
	return kq;
}

int HCN::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

int HCN::tenhinh()
{
	return 1;
}

HCN::HCN()
{
}


HCN::~HCN()
{
}
