// KDocument.h: interface for the KDocument class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KDOCUMENT_H__EF938298_FD9B_4030_874B_B7F1E85EC4CC__INCLUDED_)
#define AFX_KDOCUMENT_H__EF938298_FD9B_4030_874B_B7F1E85EC4CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KListBox.h"
#include "KView.h"

class KDocument
{
public:
    typedef KListBox<int>::VITOR    KDITOR;

private:
    KListBox<int>   m_kListBox;
    KView*          m_pView;

public:
    KDocument();
    virtual ~KDocument();

    void Insert(int iData);
    void SetView(KView* pView);
    KView* GetView();
    KListBox<int>* GetListBox();
};//class KDocument

#endif // !defined(AFX_KDOCUMENT_H__EF938298_FD9B_4030_874B_B7F1E85EC4CC__INCLUDED_)
