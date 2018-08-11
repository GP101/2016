#include "stdafx.h"
#include "DataExchange.h"

// it's simple. On surprisingly MFC also be.
CDataExchange::CDataExchange(int bSave /*= 1*/)
{
    m_bSaveAndValidate = bSave;
}//CDataExchange::CDataExchange()
