// ResStep3Doc.cpp : implementation of the CResStep3Doc class
//

#include "stdafx.h"
#include "ResStep3.h"

#include "ResStep3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResStep3Doc

IMPLEMENT_DYNCREATE(CResStep3Doc, CDocument)

BEGIN_MESSAGE_MAP(CResStep3Doc, CDocument)
	//{{AFX_MSG_MAP(CResStep3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResStep3Doc construction/destruction

CResStep3Doc::CResStep3Doc()
{
	// TODO: add one-time construction code here

}

CResStep3Doc::~CResStep3Doc()
{
}

BOOL CResStep3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CResStep3Doc serialization

void CResStep3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CResStep3Doc diagnostics

#ifdef _DEBUG
void CResStep3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CResStep3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CResStep3Doc commands
