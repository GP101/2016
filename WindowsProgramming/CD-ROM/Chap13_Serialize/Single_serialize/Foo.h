// Foo.h: interface for the CFoo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOO_H__82DB937E_E181_4422_A14A_1DA548CF7C76__INCLUDED_)
#define AFX_FOO_H__82DB937E_E181_4422_A14A_1DA548CF7C76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFoo
{
public:
	CFoo();
	virtual ~CFoo();

public:
    CString  m_strName;  // employee name
    int      m_nId;      // employee id

public:
    virtual void Serialize(CArchive& ar);    
};//class CFoo

#endif // !defined(AFX_FOO_H__82DB937E_E181_4422_A14A_1DA548CF7C76__INCLUDED_)
