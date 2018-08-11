// Single.h : main header file for the SINGLE application
//

#if !defined(AFX_SINGLE_H__AD584786_1023_4830_9ED7_3802C68585C1__INCLUDED_)
#define AFX_SINGLE_H__AD584786_1023_4830_9ED7_3802C68585C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSingleApp:
// See Single.cpp for the implementation of this class
//

class CSingleApp : public CWinApp
{
public:
    CSingleApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSingleApp)
    public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation
    //{{AFX_MSG(CSingleApp)
    afx_msg void OnAppAbout();
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLE_H__AD584786_1023_4830_9ED7_3802C68585C1__INCLUDED_)
