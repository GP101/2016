// DDX_step4View.cpp : implementation of the CDDX_step4View class
//

#include "stdafx.h"
#include "DDX_step4.h"

#include "DDX_step4Doc.h"
#include "DDX_step4View.h"
#include <string.h>
#include "Step4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4View

IMPLEMENT_DYNCREATE(CDDX_step4View, CView)

BEGIN_MESSAGE_MAP(CDDX_step4View, CView)
    //{{AFX_MSG_MAP(CDDX_step4View)
    ON_WM_LBUTTONDOWN()
    //}}AFX_MSG_MAP
    // Standard printing commands
    ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4View construction/destruction

CDDX_step4View::CDDX_step4View()
{
    // TODO: add construction code here
    //{{seojt
    wcscpy(m_str, L"hello");
    //}}seojt
}

CDDX_step4View::~CDDX_step4View()
{
}

BOOL CDDX_step4View::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4View drawing

void CDDX_step4View::OnDraw(CDC* pDC)
{
    CDDX_step4Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    // TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4View printing

BOOL CDDX_step4View::OnPreparePrinting(CPrintInfo* pInfo)
{
    // default preparation
    return DoPreparePrinting(pInfo);
}

void CDDX_step4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add extra initialization before printing
}

void CDDX_step4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4View diagnostics

#ifdef _DEBUG
void CDDX_step4View::AssertValid() const
{
    CView::AssertValid();
}

void CDDX_step4View::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CDDX_step4Doc* CDDX_step4View::GetDocument() // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDDX_step4Doc)));
    return (CDDX_step4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4View message handlers

void CDDX_step4View::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    int       iRet;
    CStep4Dlg dlg;

    dlg.m_strEdit1 = m_str;
    iRet = dlg.DoModal();
    if (iRet == IDOK) {
        wcscpy(m_str, dlg.m_strEdit1);
    }//if
    
    CView::OnLButtonDown(nFlags, point);
}
