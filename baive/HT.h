#pragma once
#include "HINH.h"
class HT :
	public HINH
{
private:
	int x1, y1, x2, y2;
public:
	HT(CPoint p1, CPoint p2);
	HT(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void ve(CClientDC *pdc);
	float dientich();
	float chuvi();
	int tronghinh(CPoint p1);	
	int tenhinh();
	HT();
	~HT();
};

