#include "Server.h"


IUnknown__ * CreateInstance() {
	IUnknown__ * pI = static_cast<IY*>(new CA);
	//pI->AddRef();
	return static_cast<IY*>(new CA);
}


