#include <Windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;

int main()
{
	// ���������� DLL-����������
	HMODULE hDll;
	
	// ��������� �� �������
	void(*dllHelloWorld) (void);

	// ��������� ����������� ������������ ����������
	hDll = LoadLibrary(_T("Server.dll"));
	if (!hDll)
	{
		cout << _T("������������ ���������� �� ���������") << endl;
		return GetLastError();
	}
	// ����������� ����� �������
	dllHelloWorld = (void(*)(void))GetProcAddress(hDll, "HelloWorld");
	if (!dllHelloWorld)
	{
		cout << "hello" << endl;
		cout << _T("������ ��������� ������ �������") << endl;
		return GetLastError();
	}

	// �������� ������� �� ����������
	dllHelloWorld();

	// ��������� ����������
	if (!FreeLibrary(hDll))
	{
		cout << _T("������ �������� ���������� �� ������") << endl;
		return GetLastError();
	}

	// ������������� ����� ����� ����������� ���������
	system("pause");
	return 0;
}