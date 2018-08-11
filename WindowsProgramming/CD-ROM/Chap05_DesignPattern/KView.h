// KView.h: interface for the KView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KVIEW_H__8B5AF7E6_D2D7_491B_B7A2_B635E4CCE892__INCLUDED_)
#define AFX_KVIEW_H__8B5AF7E6_D2D7_491B_B7A2_B635E4CCE892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class KDocument;
class KView
{
private:
    KDocument*  m_pDocument;
    int         m_iStart;
    int         m_iDisplayStart;
    int         m_iSelected;

public:
    KView(KDocument* pDoc);
    virtual ~KView();

    void SetDocument(KDocument* pDoc);
    KDocument* GetDocument();
    void SetDisplayStart(int iStart);
    void SetSelected(int iSelected);
    virtual void Draw();
};//class KView

#endif // !defined(AFX_KVIEW_H__8B5AF7E6_D2D7_491B_B7A2_B635E4CCE892__INCLUDED_)
