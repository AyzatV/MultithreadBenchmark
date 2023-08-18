#include "mt_comparer.h"

namespace avhw26
{
	MtComparer::MtComparer() {}

	MtComparer::~MtComparer() {}

	void MtComparer::start()
	{
		const int amount = 14745600;		// произведение 2 х 4 х 6 х 8 х 10
		const int t_num = 10;				// принимает значения 1, 2, 4, 6, 8, 10
		const int size = amount / t_num;	// размер массива в одном потоке

		// параметры для генерирования случайных чисел
		float rand_max = 32767;				// максимальное число генерируемое rand()
		srand(time(nullptr));				// задание начальной точки генерирования массива
		int range = 100;					// максимальное значение в массиве
		
		// создание массивов
		std::vector<int*> arrays;
		for (int n = 0; n < t_num; n++)
		{
			int* a = new int[size];
			for (int i = 0; i < size; i++)
			{
				float k = rand() / rand_max;    // k в диапазоне от 0 до 1
				a[i] = (int)(k * range);
			}
			arrays.push_back(a);
		}
		
		// фиксация времени старта процесса
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

		// фиксация времени завершения процесса
		auto stop = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> d = stop - start;
		std::cout << "Результат: " << result << std::endl << "Времени затрачено: " << d.count() << " с" << std::endl;
	}

	void MtComparer::sum(int* arr, int size, int& result)
	{
		result = 0;
		for (int i = 0; i < size; i++) result += arr[i];
	}


}