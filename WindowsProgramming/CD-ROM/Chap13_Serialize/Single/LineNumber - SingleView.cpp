001: // SingleView.cpp : implementation of the CSingleView class
002: //
003: 
004: #include "stdafx.h"
005: #include "Single.h"
006: 
007: #include "SingleDoc.h"
008: #include "SingleView.h"
009: 
010: #ifdef _DEBUG
011: #define new DEBUG_NEW
012: #undef THIS_FILE
013: static char THIS_FILE[] = __FILE__;
014: #endif
015: 
016: /////////////////////////////////////////////////////////////////////////////
017: // CSingleView
018: 
019: IMPLEMENT_DYNCREATE(CSingleView, CView)
020: 
021: BEGIN_MESSAGE_MAP(CSingleView, CView)
022:     //{{AFX_MSG_MAP(CSingleView)
023:         // NOTE - the ClassWizard will add and remove mapping macros here.
024:         //    DO NOT EDIT what you see in these blocks of generated code!
025:     //}}AFX_MSG_MAP
026:     // Standard printing commands
027:     ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
028:     ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
029:     ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
030: END_MESSAGE_MAP()
031: 
032: /////////////////////////////////////////////////////////////////////////////
033: // CSingleView construction/destruction
034: 
035: CSingleView::CSingleView()
036: {
037:     // TODO: add construction code here
038: 
039: }
040: 
041: CSingleView::~CSingleView()
042: {
043: }
044: 
045: BOOL CSingleView::PreCreateWindow(CREATESTRUCT& cs)
046: {
047:     // TODO: Modify the Window class or styles here by modifying
048:     //  the CREATESTRUCT cs
049: 
050:     return CView::PreCreateWindow(cs);
051: }
052: 
053: /////////////////////////////////////////////////////////////////////////////
054: // CSingleView drawing
055: 
056: void CSingleView::OnDraw(CDC* pDC)
057: {
058:     CSingleDoc* pDoc = GetDocument();
059:     ASSERT_VALID(pDoc);
060:     // TODO: add draw code for native data here
061: }
062: 
063: /////////////////////////////////////////////////////////////////////////////
064: // CSingleView printing
065: 
066: BOOL CSingleView::OnPreparePrinting(CPrintInfo* pInfo)
067: {
068:     // default preparation
069:     return DoPreparePrinting(pInfo);
070: }
071: 
072: void CSingleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
073: {
074:     // TODO: add extra initialization before printing
075: }
076: 
077: void CSingleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
078: {
079:     // TODO: add cleanup after printing
080: }
081: 
082: /////////////////////////////////////////////////////////////////////////////
083: // CSingleView diagnostics
084: 
085: #ifdef _DEBUG
086: void CSingleView::AssertValid() const
087: {
088:     CView::AssertValid();
089: }
090: 
091: void CSingleView::Dump(CDumpContext& dc) const
092: {
093:     CView::Dump(dc);
094: }
095: 
096: CSingleDoc* CSingleView::GetDocument() // non-debug version is inline
097: {
098:     ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDoc)));
099:     return (CSingleDoc*)m_pDocument;
100: }
101: #endif //_DEBUG
102: 
103: /////////////////////////////////////////////////////////////////////////////
104: // CSingleView message handlers
