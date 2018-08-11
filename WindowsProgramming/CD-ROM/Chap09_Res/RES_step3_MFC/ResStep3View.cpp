// ResStep3View.cpp : implementation of the CResStep3View class
//

#include "stdafx.h"
#include "ResStep3.h"

#include "ResStep3Doc.h"
#include "ResStep3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResStep3View

IMPLEMENT_DYNCREATE(CResStep3View, CView)

BEGIN_MESSAGE_MAP(CResStep3View, CView)
	//{{AFX_MSG_MAP(CResStep3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResStep3View construction/destruction

CResStep3View::CResStep3View()
{
	// TODO: add construction code here

}

CResStep3View::~CResStep3View()
{
}

BOOL CResStep3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CResStep3View drawing

void CResStep3View::OnDraw(CDC* pDC)
{
	CResStep3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CResStep3View printing

BOOL CResStep3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CResStep3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CResStep3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CResStep3View diagnostics

#ifdef _DEBUG
void CResStep3View::AssertValid() const
{
	CView::AssertValid();
}

void CResStep3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CResStep3Doc* CResStep3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CResStep3Doc)));
	return (CResStep3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CResStep3View message handlers
