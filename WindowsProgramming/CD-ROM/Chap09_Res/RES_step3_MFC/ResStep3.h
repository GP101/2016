// ResStep3.h : main header file for the RESSTEP3 application
//

#if !defined(AFX_RESSTEP3_H__802342C2_97D2_41E1_A9C3_4A9D5A5EB574__INCLUDED_)
#define AFX_RESSTEP3_H__802342C2_97D2_41E1_A9C3_4A9D5A5EB574__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CResStep3App:
// See ResStep3.cpp for the implementation of this class
//

class CResStep3App : public CWinApp
{
public:
	CResStep3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResStep3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CResStep3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESSTEP3_H__802342C2_97D2_41E1_A9C3_4A9D5A5EB574__INCLUDED_)
