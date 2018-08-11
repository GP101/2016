#include "stdafx.h"
#include "DataExchange.h"

// it's simple. On surprisingly MFC also be.
CDataExchange::CDataExchange(CWnd* pDlgWnd, BOOL bSaveAndValidate)
{
    m_pDlgWnd          = pDlgWnd;
    m_bSaveAndValidate = bSaveAndValidate;
}//CDataExchange::CDataExchange()
