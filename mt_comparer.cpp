#include "mt_comparer.h"

namespace avhw26
{
	MtComparer::MtComparer() {}

	MtComparer::~MtComparer() {}

	void MtComparer::start()
	{
		const int amount = 14745600;		// ������������ 2 � 4 � 6 � 8 � 10
		const int t_num = 10;				// ��������� �������� 1, 2, 4, 6, 8, 10
		const int size = amount / t_num;	// ������ ������� � ����� ������

		// ��������� ��� ������������� ��������� �����
		float rand_max = 32767;				// ������������ ����� ������������ rand()
		srand(time(nullptr));				// ������� ��������� ����� ������������� �������
		int range = 100;					// ������������ �������� � �������
		
		// �������� ��������
		std::vector<int*> arrays;
		for (int n = 0; n < t_num; n++)
		{
			int* a = new int[size];
			for (int i = 0; i < size; i++)
			{
				float k = rand() / rand_max;    // k � ��������� �� 0 �� 1
				a[i] = (int)(k * range);
			}
			arrays.push_back(a);
		}
		
		// �������� ������� ������ ��������
		auto start = std::chrono::high_resolution_clock::now();

		int results[t_num];
		std::vector<std::thread> threads;
		for (int n = 0; n < t_num; n++)
		{
			threads.push_back(std::thread(sum, std::move(arrays[n]), size, std::ref(results[n])));
		}
		int result = 0;
		for (int n = 0; n < t_num; n++)
		{
			threads[n].join();
			result += results[n];
			delete[] arrays[n];
		}

		// �������� ������� ���������� ��������
		auto stop = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> d = stop - start;
		std::cout << "���������: " << result << std::endl << "������� ���������: " << d.count() << " �" << std::endl;
	}

	void MtComparer::sum(int* arr, int size, int& result)
	{
		result = 0;
		for (int i = 0; i < size; i++) result += arr[i];
	}


}