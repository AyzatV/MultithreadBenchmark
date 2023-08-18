#pragma once
#include <iostream>
#include <vector>
#include <thread>

namespace avhw26
{
	class MtComparer
	{
	public:
		MtComparer();
		~MtComparer();
		void start();

	private:
		static void sum(int*, int, int&);
	};

}