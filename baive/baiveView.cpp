
// baiveView.cpp : implementation of the CbaiveView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "baive.h"
#endif

#include "baiveDoc.h"
#include "baiveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbaiveView

IMPLEMENT_DYNCREATE(CbaiveView, CView)

BEGIN_MESSAGE_MAP(CbaiveView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CbaiveView construction/destruction

CbaiveView::CbaiveView() noexcept
{
	// TODO: add construction code here
	khung1.thietlap(0, 0, 2000, 100);
	khung2.thietlap(150, 100, 2000, 1000);
	button1.thietlap(45, 35, 85, 65);
	button2.thietlap(100, 35, 140, 65);
	button3.thietlap(170, 35, 190, 65);
	button4.thietlap(300, 35, 320, 65);
	button5.thietlap(340, 35, 360, 65);
	n = 0;
	mau = 0;
}



CbaiveView::~CbaiveView()
{
}

BOOL CbaiveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CbaiveView drawing

void CbaiveView::OnDraw(CDC* /*pDC*/)
{
	CbaiveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pdc = new CClientDC(this);

	khung1.ve(pdc);
	khung2.ve(pdc);
	
	CPen *pen;
	CPen *pen1;
	CBrush *nen;
	CBrush *nen1;
	CBrush *nen2;
	CPen *pen2;
	CPen *pen3;
	CBrush *nen3;
	
	pen1 = new CPen(PS_SOLID, 2, RGB(0, 0, 0));

	pen2 = new CPen(PS_SOLID, 2, RGB(255, 0, 0));

	pen3 = new CPen(PS_SOLID, 2, RGB(0, 255, 0));

	nen1 = new CBrush(RGB(255,255,255));

	nen2 = new CBrush(RGB(255, 0, 0));

	nen3 = new CBrush(RGB(0, 255, 0));

	pen = pdc->SelectObject(pen1);

	button1.ve(pdc);
	button2.ve(pdc);
	button3.ve(pdc);

	pen = pdc->SelectObject(pen2);
	nen = pdc->SelectObject(nen2);
	button4.ve(pdc);

	pen = pdc->SelectObject(pen3);
	nen = pdc->SelectObject(nen3);
	button5.ve(pdc);

	

	CString chuthich;
	chuthich = "Nhay dup chuot de xem thong tin hinh..";
	pdc->TextOutW(400, 25, chuthich);
	CString chuthich2;
	chuthich2 = "Nhap chuot phai de xoa hinh..";
	pdc->TextOutW(400,65, chuthich2);


	nen = pdc->SelectObject(nen1);

	// TODO: add draw code for native data here
}


// CbaiveView printing

BOOL CbaiveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CbaiveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CbaiveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CbaiveView diagnostics

#ifdef _DEBUG
void CbaiveView::AssertValid() const
{
	CView::AssertValid();
}

void CbaiveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CbaiveDoc* CbaiveView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbaiveDoc)));
	return (CbaiveDoc*)m_pDocument;
}
#endif //_DEBUG


// CbaiveView message handlers


void CbaiveView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x<2000 && point.x>100 && point.y<1000 && point.y>100)
	{
		p1.x = point.x;
		p1.y = point.y;
	}
	
	CView::OnLButtonDown(nFlags, point);
}


void CbaiveView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.y > 100 && point.x > 100)
	{
		p2.x = point.x;
		p2.y = point.y;
	}
	


	CPen *pen;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen *pen2;
	pen2 = new CPen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen *pen3;
	pen3 = new CPen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen *pen4;
	pen4 = new CPen(PS_SOLID, 2, RGB(0, 255, 0));

	if (button1.tronghinh(point) == 1)
	{
		chon = 1;

		pen = pdc->SelectObject(pen2);
		button1.ve(pdc);

		pen = pdc->SelectObject(pen1);
		button2.ve(pdc);
		button3.ve(pdc);
	}
	else
		if (button2.tronghinh(point) == 1)
		{
			chon = 2;
			pen = pdc->SelectObject(pen2);
			button2.ve(pdc);

			pen = pdc->SelectObject(pen1);
			button1.ve(pdc);
			button3.ve(pdc);
		}
		else
			if (button3.tronghinh(point) == 1)
			{
				chon = 3;

				pen = pdc->SelectObject(pen2);
				button3.ve(pdc);

				pen = pdc->SelectObject(pen1);
				button1.ve(pdc);
				button2.ve(pdc);
			}
			else
				if (button4.tronghinh(point) == 1)
				{
					pen = pdc->SelectObject(pen3);
				}
					
				else
					if (button5.tronghinh(point) == 1)
					{
						pen = pdc->SelectObject(pen4);
					}
			else
				if (chon == 1)
				{
					hinh[n] = new HCN(p1, p2);
					hinh[n]->ve(pdc);
					n++;
				}
				else
					if (chon == 2)
					{
						hinh[n] = new HT(p1, p2);
						hinh[n]->ve(pdc);
						n++;
					}
					else
						if (chon == 3)
						{
							hinh[n] = new TG(p1, p2);
							hinh[n]->ve(pdc);
							n++;
						}

	CView::OnLButtonUp(nFlags, point);
}


void CbaiveView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	int i;
	CString str,str1,sttenhinh;
	CString sts;
	sts = "Dien tich:";
	CString stc;
	stc = "Chu vi:";
	for (i = 0; i < n; i++)
	{
		if (hinh[i]->tronghinh(point) == 1)
		{
			if (hinh[i]->tenhinh() == 1)
				sttenhinh = "Hinh chu nhat";
			if (hinh[i]->tenhinh() == 2)
				sttenhinh = "Hinh  ellipse    ";
			if (hinh[i]->tenhinh() == 3)
				sttenhinh = "Hinh tam giac";
			pdc->TextOutW(10, 120, sttenhinh);
			str.Format(_T("%f"), hinh[i]->dientich());
			str1.Format(_T("%f"), hinh[i]->chuvi());
			pdc->TextOutW(10, 150, sts);
			pdc->TextOutW(10, 170, str);
			pdc->TextOutW(10, 200, stc);
			pdc->TextOutW(10, 220, str1);
			break;
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CbaiveView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	int i;
	CPen *pen;
	CBrush *nen;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 2, RGB(255, 255, 255));
	for (i = 0; i < n; i++)
	{
		if (hinh[i]->tronghinh(point) == 1)
		{
			
			pen = pdc->SelectObject(pen1);
			hinh[i]->ve(pdc);
			break;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}
