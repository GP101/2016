#include <windows.h>

#ifndef _stdafx_defined_
#define _stdafx_defined_

//{{MessageMap macros-----------------------------------------------------
#define DECLARE_MESSAGE_MAP() \
    static MessageMap messageMap[];\
    virtual const MessageMap* GetMessageMap() const;

#define BEGIN_MESSAGE_MAP(class_name) \
    const MessageMap* class_name::GetMessageMap() const \
    { return class_name::messageMap; } \
    MessageMap class_name::messageMap[] = {

#define END_MESSAGE_MAP()   {0, NULL} };

//{{RTTI macros-----------------------------------------------------------
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name;

#define IMPLEMENT_DYNAMIC(class_name) \
    CRuntimeClass class_name::class##class_name = { \
        (#class_name), \
        sizeof(class_name), \
        class_name::CreateObject };

#define DECLARE_DYNCREATE(class_name) \
    DECLARE_DYNAMIC(class_name) \
    static CObject* CreateObject();

#define IMPLEMENT_DYNCREATE(class_name) \
    IMPLEMENT_DYNAMIC(class_name) \
    CObject* class_name::CreateObject() \
    { return new class_name; }

//Forward declaration------------------------------------------------
class CObject;
class CCmdTarget;

//{{struct CRuntimeClass-------------------------------------------------
struct CRuntimeClass
{
    char        m_lpszClassName[21];
    int         m_nObjectSize;
    CObject* (*pfnCreateObject)();//function pointer

    CObject* CreateObject();
};//struct CRunTimeClass

//{{struct MessageMap------------------------------------------------
typedef void (CCmdTarget::*CCmdTargetFunPointer)(WPARAM, LPARAM);
typedef struct tagMessageMap
{
    UINT                    iMsg;
    CCmdTargetFunPointer    fp;
} MessageMap;

#endif // #ifndef _stdafx_defined_
