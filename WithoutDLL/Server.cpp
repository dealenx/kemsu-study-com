#include "Server.h"

/*
IUnknown__ * CreateInstance() {
	IUnknown__ * pI = static_cast<IY*>(new CA);
	//pI->AddRef();
	return static_cast<IY*>(new CA);
}*/


HRESULT __stdcall  CreateInstance__(int iid, void** ppv) { //Второй фабричный метод
	int res;

	if(iid == 0) {
		IX * PX = NULL;
		IUnknown__ * PI = static_cast<IX*>(new CA);
		
		res = PI -> QueryInterface__(0,  (void **)&PX);
		*ppv = (void *)((IX*)PX);
	} else if(iid = 1) {
		IY * PY = NULL;
		IUnknown__ * PI = static_cast<IY*>(new CA);
		
		res = PI -> QueryInterface__(1,  (void **)&PY);
		*ppv = (void *)((IY*)PY);
	}
	else {
		IX * PX = NULL;
		IUnknown__ * PI = static_cast<IX*>(new CA);
		
		res = PI -> QueryInterface__(0,  (void **)&PX);
		*ppv = (void *)((IX*)PX);
        
		return 1;
	}
	return 0;

}

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

/*
extern "C" __declspec(dllexport) IUnknown__ *allocate_IX() {
    return new IX;
}
extern "C" __declspec(dllexport) IUnknown__ *allocate_IY() {
    return new IY;
}
*/
