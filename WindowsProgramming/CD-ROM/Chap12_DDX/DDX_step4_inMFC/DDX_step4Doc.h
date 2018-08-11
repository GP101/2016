// DDX_step4Doc.h : interface of the CDDX_step4Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDX_STEP4DOC_H__66F39CAB_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
#define AFX_DDX_STEP4DOC_H__66F39CAB_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDDX_step4Doc : public CDocument
{
protected: // create from serialization only
	CDDX_step4Doc();
	DECLARE_DYNCREATE(CDDX_step4Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDX_step4Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDDX_step4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDDX_step4Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDX_STEP4DOC_H__66F39CAB_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
