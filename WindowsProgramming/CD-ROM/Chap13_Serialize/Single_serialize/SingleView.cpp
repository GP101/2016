// SingleView.cpp : implementation of the CSingleView class
//

#include "stdafx.h"
#include "Single.h"

#include "SingleDoc.h"
#include "SingleView.h"
#include "Foo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleView

IMPLEMENT_DYNCREATE(CSingleView, CView)

BEGIN_MESSAGE_MAP(CSingleView, CView)
	//{{AFX_MSG_MAP(CSingleView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleView construction/destruction

CSingleView::CSingleView()
{
	// TODO: add construction code here

}

CSingleView::~CSingleView()
{
}

BOOL CSingleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSingleView drawing

void CSingleView::OnDraw(CDC* pDC)
{
	CSingleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSingleView printing

BOOL CSingleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSingleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSingleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSingleView diagnostics

#ifdef _DEBUG
void CSingleView::AssertValid() const
{
	CView::AssertValid();
}

void CSingleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingleDoc* CSingleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDoc)));
	return (CSingleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSingleView message handlers

void CSingleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // step 1: Open data file "foo.dat"
    CFile* pFile = new CFile();
    ASSERT (pFile != NULL);
    if ( !pFile->Open(L"foo.dat", CFile::modeWrite|CFile::modeCreate) )
    {
        // Handle error
        return;
    }//if
	
    // step 2: Create archive ...
    bool bReading = false;  // ... for writing
    CArchive* pArchive = NULL;
    try
    {
        pFile->SeekToBegin();
        UINT uMode = (bReading ? CArchive::load : CArchive::store);
        pArchive = new CArchive(pFile, uMode);
        ASSERT (pArchive != NULL);
    }//try
    catch (CException* pException)
    {
        // Handle error
        return;
    }//catch

    // step 3: call Serialize()
    CFoo*   pFoo = new CFoo();
    pFoo->Serialize( *pArchive );
    delete pFoo;

    // step 4: clean up
    pArchive->Close();
    delete pArchive;
    pFile->Close();
    delete pFile;

	CView::OnLButtonDown(nFlags, point);
}

int CSingleView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CSingleView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
    CClientDC dc(this);

    dc.LineTo(100,100);
	
}

void CSingleView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages
}
