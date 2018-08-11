001: // SingleDoc.cpp : implementation of the CSingleDoc class
002: //
003: 
004: #include "stdafx.h"
005: #include "Single.h"
006: 
007: #include "SingleDoc.h"
008: 
009: #ifdef _DEBUG
010: #define new DEBUG_NEW
011: #undef THIS_FILE
012: static char THIS_FILE[] = __FILE__;
013: #endif
014: 
015: /////////////////////////////////////////////////////////////////////////////
016: // CSingleDoc
017: 
018: IMPLEMENT_DYNCREATE(CSingleDoc, CDocument)
019: 
020: BEGIN_MESSAGE_MAP(CSingleDoc, CDocument)
021:     //{{AFX_MSG_MAP(CSingleDoc)
022:         // NOTE - the ClassWizard will add and remove mapping macros here.
023:         //    DO NOT EDIT what you see in these blocks of generated code!
024:     //}}AFX_MSG_MAP
025: END_MESSAGE_MAP()
026: 
027: /////////////////////////////////////////////////////////////////////////////
028: // CSingleDoc construction/destruction
029: 
030: CSingleDoc::CSingleDoc()
031: {
032:     // TODO: add one-time construction code here
033: 
034: }
035: 
036: CSingleDoc::~CSingleDoc()
037: {
038: }
039: 
040: BOOL CSingleDoc::OnNewDocument()
041: {
042:     if (!CDocument::OnNewDocument())
043:         return FALSE;
044: 
045:     // TODO: add reinitialization code here
046:     // (SDI documents will reuse this document)
047: 
048:     return TRUE;
049: }
050: 
051: 
052: 
053: /////////////////////////////////////////////////////////////////////////////
054: // CSingleDoc serialization
055: 
056: void CSingleDoc::Serialize(CArchive& ar)
057: {
058:     if (ar.IsStoring())
059:     {
060:         // TODO: add storing code here
061:     }
062:     else
063:     {
064:         // TODO: add loading code here
065:     }
066: }
067: 
068: /////////////////////////////////////////////////////////////////////////////
069: // CSingleDoc diagnostics
070: 
071: #ifdef _DEBUG
072: void CSingleDoc::AssertValid() const
073: {
074:     CDocument::AssertValid();
075: }
076: 
077: void CSingleDoc::Dump(CDumpContext& dc) const
078: {
079:     CDocument::Dump(dc);
080: }
081: #endif //_DEBUG
082: 
083: /////////////////////////////////////////////////////////////////////////////
084: // CSingleDoc commands
