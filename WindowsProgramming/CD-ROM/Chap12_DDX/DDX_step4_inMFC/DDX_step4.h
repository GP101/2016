// DDX_step4.h : main header file for the DDX_STEP4 application
//

#if !defined(AFX_DDX_STEP4_H__66F39CA5_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
#define AFX_DDX_STEP4_H__66F39CA5_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDDX_step4App:
// See DDX_step4.cpp for the implementation of this class
//

class CDDX_step4App : public CWinApp
{
public:
	CDDX_step4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDX_step4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDDX_step4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDX_STEP4_H__66F39CA5_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
