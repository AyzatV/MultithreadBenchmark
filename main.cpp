#include "mt_comparer.h"
#include <Windows.h>

int main()
{
	// ����������� ������� ������� ��� �����-������ ����������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	avhw26::MtComparer mtc;
	mtc.start();

	std::cout << std::endl << "������ ��������� ����������" << std::endl;
	std::cin.get();
	return 0;
}