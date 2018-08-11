// DDX_step4View.h : interface of the CDDX_step4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDX_STEP4VIEW_H__66F39CAD_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
#define AFX_DDX_STEP4VIEW_H__66F39CAD_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDDX_step4View : public CView
{
protected: // create from serialization only
	CDDX_step4View();
	DECLARE_DYNCREATE(CDDX_step4View)

// Attributes
public:
    //{{seojt
    WCHAR m_str[20];
    //}}seojt

	CDDX_step4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDX_step4View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDDX_step4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDDX_step4View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DDX_step4View.cpp
inline CDDX_step4Doc* CDDX_step4View::GetDocument()
   { return (CDDX_step4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDX_STEP4VIEW_H__66F39CAD_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
