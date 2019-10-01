
// baiveView.h : interface of the CbaiveView class
//

#pragma once
#include "HINH.h"
#include "HCN.h"
#include"HT.h"
#include"TG.h"


class CbaiveView : public CView
{
protected: // create from serialization only
	CbaiveView() noexcept;
	DECLARE_DYNCREATE(CbaiveView)

// Attributes
public:
	CbaiveDoc* GetDocument() const;

// Operations
public:
	HCN khung1, khung2, button1, button4,button5;
	HT button2;
	TG button3;
	CPoint p1, p2;
	CClientDC *pdc;
	int n;
	int chon;
	int mau;
	HINH *hinh[30];

	

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CbaiveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in baiveView.cpp
inline CbaiveDoc* CbaiveView::GetDocument() const
   { return reinterpret_cast<CbaiveDoc*>(m_pDocument); }
#endif

