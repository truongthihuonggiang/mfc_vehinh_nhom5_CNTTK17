#pragma once
class HINH
{
public:
	CPoint diem1, diem2;
	virtual void ve(CClientDC *pdc);
	virtual float dientich();
	virtual float chuvi();
	virtual int tronghinh(CPoint p1);
	virtual int tenhinh();
	HINH();
	~HINH();
};

