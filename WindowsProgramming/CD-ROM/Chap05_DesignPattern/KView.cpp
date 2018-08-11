#include "KView.h"
#include "KDocument.h"
#include <iostream>

using std::cout;
using std::endl;

KView::KView(KDocument* pDoc)
{
    m_pDocument     = pDoc;
    m_iStart        = 0;
    m_iDisplayStart = 0;
    m_iSelected     = 0;
}//KView::KView()

KView::~KView()
{
}//KView::~KView()

void KView::SetDocument(KDocument* pDoc)
{
    m_pDocument = pDoc;
}//KView::SetDocument()

KDocument* KView::GetDocument()
{
    return m_pDocument;
}//KView::GetDocument()

void KView::SetDisplayStart(int iDisplayStart)
{
    m_iDisplayStart = iDisplayStart;
    m_iStart = GetDocument()->GetListBox()->SetDisplayStart( m_iDisplayStart );
}//KView::SetDisplayStart()

void KView::SetSelected(int iSelected)
{
    m_iSelected = iSelected;
    GetDocument()->GetListBox()->SetSelected( m_iSelected );
}//KView::SetSelected()

/*virtual*/ void KView::Draw()
{
    int iStart = m_iStart;

    for( KDocument::KDITOR itor = GetDocument()->GetListBox()->BeginDisplay();
         itor != GetDocument()->GetListBox()->EndDisplay();
         ++itor )
    {
        if ( GetDocument()->GetListBox()->IsSelected( iStart ) )
            cout << "* ";
        else
            cout << "  ";
		cout << "element value = " << (*itor) << endl;
        ++iStart;
    }//for
}//KView::Draw()
