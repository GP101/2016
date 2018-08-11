// ResStep3View.h : interface of the CResStep3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESSTEP3VIEW_H__00D75BD7_49CD_4991_AE5E_C35A4F111B7B__INCLUDED_)
#define AFX_RESSTEP3VIEW_H__00D75BD7_49CD_4991_AE5E_C35A4F111B7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CResStep3View : public CView
{
protected: // create from serialization only
	CResStep3View();
	DECLARE_DYNCREATE(CResStep3View)

// Attributes
public:
	CResStep3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResStep3View)
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
	virtual ~CResStep3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CResStep3View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ResStep3View.cpp
inline CResStep3Doc* CResStep3View::GetDocument()
   { return (CResStep3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESSTEP3VIEW_H__00D75BD7_49CD_4991_AE5E_C35A4F111B7B__INCLUDED_)
