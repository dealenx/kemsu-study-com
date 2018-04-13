
#define MY_COMPILE_DLL
#include "Server.h"


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

void HelloWorld(void) {
	cout << "Hello world" << endl;
}

TestInterface::TestInterface()
{
}

TestInterface::~TestInterface()
{
}

class MY_DECLSPEC Test : public TestInterface
{
public:
	Test(const bool, const int);
	virtual ~Test();
	virtual bool Get(bool &flag, int &num);
private:
	bool f_flag;
	int f_num;
	char f_text80[80];
};

Test::Test(const bool flag, const int num)
	: TestInterface(), f_flag(flag), f_num(num)
{
}

Test::~Test()
{
}

bool Test::Get(bool &flag, int &num)
{
	flag = f_flag;
	num = f_num;
	return true;
}

TestInterface* newtestdll(const bool flag, const int num)
{
	return new Test(flag, num);
}

void deletetestdll(TestInterface *f)
{
	delete f;
}