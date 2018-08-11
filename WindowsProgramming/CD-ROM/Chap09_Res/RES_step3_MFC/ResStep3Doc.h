// ResStep3Doc.h : interface of the CResStep3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESSTEP3DOC_H__FE7DF0AB_545C_4533_BBA5_88910C126012__INCLUDED_)
#define AFX_RESSTEP3DOC_H__FE7DF0AB_545C_4533_BBA5_88910C126012__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CResStep3Doc : public CDocument
{
protected: // create from serialization only
	CResStep3Doc();
	DECLARE_DYNCREATE(CResStep3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResStep3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CResStep3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CResStep3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESSTEP3DOC_H__FE7DF0AB_545C_4533_BBA5_88910C126012__INCLUDED_)
