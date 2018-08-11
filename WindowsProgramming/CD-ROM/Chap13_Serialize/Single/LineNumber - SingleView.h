001: // SingleView.h : interface of the CSingleView class
002: //
003: /////////////////////////////////////////////////////////////////////////////
004: 
005: #if !defined(AFX_SINGLEVIEW_H__5B7D9117_2B92_4840_A5D3_F5741792729E__INCLUDED_)
006: #define AFX_SINGLEVIEW_H__5B7D9117_2B92_4840_A5D3_F5741792729E__INCLUDED_
007: 
008: #if _MSC_VER > 1000
009: #pragma once
010: #endif // _MSC_VER > 1000
011: 
012: 
013: class CSingleView : public CView
014: {
015: protected: // create from serialization only
016:     CSingleView();
017:     DECLARE_DYNCREATE(CSingleView)
018: 
019: // Attributes
020: public:
021:     CSingleDoc* GetDocument();
022: 
023: // Operations
024: public:
025: 
026: // Overrides
027:     // ClassWizard generated virtual function overrides
028:     //{{AFX_VIRTUAL(CSingleView)
029:     public:
030:     virtual void OnDraw(CDC* pDC);  // overridden to draw this view
031:     virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
032:     protected:
033:     virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
034:     virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
035:     virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
036:     //}}AFX_VIRTUAL
037: 
038: // Implementation
039: public:
040:     virtual ~CSingleView();
041: #ifdef _DEBUG
042:     virtual void AssertValid() const;
043:     virtual void Dump(CDumpContext& dc) const;
044: #endif
045: 
046: protected:
047: 
048: // Generated message map functions
049: protected:
050:     //{{AFX_MSG(CSingleView)
051:         // NOTE - the ClassWizard will add and remove member functions here.
052:         //    DO NOT EDIT what you see in these blocks of generated code !
053:     //}}AFX_MSG
054:     DECLARE_MESSAGE_MAP()
055: };
056: 
057: #ifndef _DEBUG  // debug version in SingleView.cpp
058: inline CSingleDoc* CSingleView::GetDocument()
059:    { return (CSingleDoc*)m_pDocument; }
060: #endif
061: 
062: /////////////////////////////////////////////////////////////////////////////
063: 
064: //{{AFX_INSERT_LOCATION}}
065: // Microsoft Visual C++ will insert additional declarations immediately before the previous line.
066: 
067: #endif // !defined(AFX_SINGLEVIEW_H__5B7D9117_2B92_4840_A5D3_F5741792729E__INCLUDED_)
