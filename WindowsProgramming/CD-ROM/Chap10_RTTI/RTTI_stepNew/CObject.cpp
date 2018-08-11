#include "CObject.h"

/*virtual*/ CRuntimeClass* CObject::GetRuntimeClass() const
{
    return NULL; // RUNTIME_CLASS(CObject);
}//CObject::GetRuntimeClass()
