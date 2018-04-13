#include <Windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;

int main()
{
	// Дескриптор DLL-библиотеки
	HMODULE hDll;
	
	// Указатель на функцию
	void(*dllHelloWorld) (void);

	// Загружаем динамически подключаемую библиотеку
	hDll = LoadLibrary(_T("Server.dll"));
	if (!hDll)
	{
		cout << _T("Динамическая библиотека не загружена") << endl;
		return GetLastError();
	}
	// Настраиваем адрес функции
	dllHelloWorld = (void(*)(void))GetProcAddress(hDll, "HelloWorld");
	if (!dllHelloWorld)
	{
		cout << "hello" << endl;
		cout << _T("Ошибка получения адреса функции") << endl;
		return GetLastError();
	}

	// Вызываем функцию из библиотеки
	dllHelloWorld();

	// Отключаем библиотеку
	if (!FreeLibrary(hDll))
	{
		cout << _T("Ошибка выгрузки библиотеки из памяти") << endl;
		return GetLastError();
	}

	// Устанавливаем паузу перед завершением программы
	system("pause");
	return 0;
}