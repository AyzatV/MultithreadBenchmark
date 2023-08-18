#include "mt_comparer.h"
#include <Windows.h>

int main()
{
	// подключение кодовых страниц для ввода-вывода кириллицей
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	avhw26::MtComparer mtc;
	mtc.start();

	std::cout << std::endl << "Работа программы прекращена" << std::endl;
	std::cin.get();
	return 0;
}