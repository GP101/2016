#include <iostream>
#include <assert.h>
#include "KDocument.h"
#include "KView.h"
//#include <conio.h>

class CWinApp
{
private:
    KDocument*  m_pDoc;
    KView*      m_pView;

public:
    CWinApp()
    {
        m_pDoc  = new KDocument();
        m_pView = new KView( m_pDoc );
        m_pDoc->SetView( m_pView );
    }//CWinApp()

    CWinApp(const CWinApp& right)
    {
        assert( !"fail" );
    }//CWinApp()

    ~CWinApp()
    {
        delete m_pDoc;
        delete m_pView;
    }//CWinApp()

    void InitInstance()
    {
        for (int i=0; i<20; ++i)
        {
	        m_pDoc->Insert( i );
        }//for
    }//InitInstance()

    void OnDraw()
    {
        m_pView->SetDisplayStart( 15 );
        m_pView->SetSelected( 17 );
	    m_pView->Draw();
    }//OnDraw()
};//class CWinApp

CWinApp theApp;

void main()
{
    theApp.InitInstance();
    theApp.OnDraw();
    //getch();
}//main()
