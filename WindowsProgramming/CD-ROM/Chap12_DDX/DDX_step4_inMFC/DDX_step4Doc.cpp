// DDX_step4Doc.cpp : implementation of the CDDX_step4Doc class
//

#include "stdafx.h"
#include "DDX_step4.h"

#include "DDX_step4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4Doc

IMPLEMENT_DYNCREATE(CDDX_step4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDDX_step4Doc, CDocument)
	//{{AFX_MSG_MAP(CDDX_step4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4Doc construction/destruction

CDDX_step4Doc::CDDX_step4Doc()
{
	// TODO: add one-time construction code here

}

CDDX_step4Doc::~CDDX_step4Doc()
{
}

BOOL CDDX_step4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDDX_step4Doc serialization

void CDDX_step4Doc::Serialize(CArchive& ar)
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
// CDDX_step4Doc diagnostics

#ifdef _DEBUG
void CDDX_step4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDDX_step4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4Doc commands
