// Foo.cpp: implementation of the CFoo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Single.h"
#include "Foo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFoo::CFoo()
{

}

CFoo::~CFoo()
{

}


void CFoo::Serialize(CArchive& ar)
{
    if ( ar.IsStoring() )
    {
        AfxTrace( L"Storing...\n" );
    }
    else
    {
        AfxTrace( L"Loading...\n" );
    }//if.. else..
}//CFoo::Serialize()
