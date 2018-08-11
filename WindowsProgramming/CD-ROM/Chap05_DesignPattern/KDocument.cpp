#include "KDocument.h"

KDocument::KDocument()
{
    m_pView = NULL;
}//KDocument::KDocument()

KDocument::~KDocument()
{
    m_kListBox.Clear();
}//KDocument::~KDocument()

void KDocument::Insert(int iData)
{
    m_kListBox.Insert( iData );
}//KDocument::Insert()

void KDocument::SetView(KView* pView)
{
    m_pView = pView;
}//KDocument::SetView()

KView* KDocument::GetView()
{
    return m_pView;
}//KDocument::GetView()

KListBox<int>* KDocument::GetListBox()
{
    return &m_kListBox;
}//KDocument::GetListBox()
