#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <objbase.h> // Определить интерфейс

using namespace std;

// Абстрактные интерфейсы
interface IUnknown__ {
	//virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) = 0;
	
	virtual HRESULT __stdcall QueryInterface__(int iid, void** ppv) = 0;
	virtual ULONG __stdcall AddRef() = 0;
	virtual ULONG __stdcall Release() = 0;

	
};
interface IX: IUnknown__ {
	virtual void __stdcall Fx1() = 0;
	virtual void __stdcall Fx2() = 0;
};
interface IY: IUnknown__ {
	virtual void __stdcall Fy1() = 0;
	virtual void __stdcall Fy2() = 0;
	
};
// Реализация интерфейса
class CA : public IX, public IY {
	public:
	// Реализация интерфейса IX
	virtual void __stdcall Fx1() { cout << "CA::Fx1" << endl; }
	virtual void __stdcall Fx2() { cout << "CA::Fx2" << endl; }
	// Реализация интерфейса IY
	virtual void __stdcall Fy1() { cout << "CA::Fy1" << endl; }
	virtual void __stdcall Fy2() { cout << "CA::Fy2" << endl; }

	HRESULT __stdcall QueryInterface__(/*const IID& iid*/ int iid, void** ppv) {
		cout << "CA::QueryInterface" << endl;

		if(iid == 0) {
			*ppv = (void *)((IX*)this);
		} else if(iid = 1) {
			*ppv = (void *)((IY*)this);
		}
		else {
			*ppv = (void *)((IX*)this);
			return 1;
		}
		return 0;
	}

	ULONG __stdcall AddRef() {
		cout << "CA::AddRef" << endl;
	}
	ULONG __stdcall Release()  {
		cout << "CA::Release" << endl;
	}
};


#endif
