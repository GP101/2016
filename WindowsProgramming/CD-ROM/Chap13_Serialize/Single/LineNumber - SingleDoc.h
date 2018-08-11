001: // SingleDoc.h : interface of the CSingleDoc class
002: //
003: /////////////////////////////////////////////////////////////////////////////
004: 
005: #if !defined(AFX_SINGLEDOC_H__D322E434_F245_49FD_AF25_D518668521F3__INCLUDED_)
006: #define AFX_SINGLEDOC_H__D322E434_F245_49FD_AF25_D518668521F3__INCLUDED_
007: 
008: #if _MSC_VER > 1000
009: #pragma once
010: #endif // _MSC_VER > 1000
011: 
012: 
013: class CSingleDoc : public CDocument
014: {
015: protected: // create from serialization only
016:     CSingleDoc();
017:     DECLARE_DYNCREATE(CSingleDoc)
018: 
019: // Attributes
020: public:
021: 
022: // Operations
023: public:
024: 
025: // Overrides
026:     // ClassWizard generated virtual function overrides
027:     //{{AFX_VIRTUAL(CSingleDoc)
028:     public:
029:     virtual BOOL OnNewDocument();
030:     virtual void Serialize(CArchive& ar);
031:     //}}AFX_VIRTUAL
032: 
033: // Implementation
034: public:
035:     virtual ~CSingleDoc();
036: #ifdef _DEBUG
037:     virtual void AssertValid() const;
038:     virtual void Dump(CDumpContext& dc) const;
039: #endif
040: 
041: protected:
042: 
043: // Generated message map functions
044: protected:
045:     //{{AFX_MSG(CSingleDoc)
046:         // NOTE - the ClassWizard will add and remove member functions here.
047:         //    DO NOT EDIT what you see in these blocks of generated code !
048:     //}}AFX_MSG
049:     DECLARE_MESSAGE_MAP()
050: };
051: 
052: /////////////////////////////////////////////////////////////////////////////
053: 
054: //{{AFX_INSERT_LOCATION}}
055: // Microsoft Visual C++ will insert additional declarations immediately before the previous line.
056: 
057: #endif // !defined(AFX_SINGLEDOC_H__D322E434_F245_49FD_AF25_D518668521F3__INCLUDED_)
