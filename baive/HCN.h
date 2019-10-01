#pragma once
#include "HINH.h"
class HCN :
	public HINH
{
private:
	
public:
	int x1, y1, x2, y2;
	HCN(CPoint p1, CPoint p2);
	HCN(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void ve(CClientDC *pdc);
	float dientich();
	float chuvi();
	int tenhinh();
	int tronghinh(CPoint p1);
	HCN();
	~HCN();
};

