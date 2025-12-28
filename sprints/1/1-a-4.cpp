// https://contest.yandex.ru/contest/22450/run-report/154459232/
// https://contest.yandex.ru/contest/22450/problems/A/

#include <iostream>
#include <vector>

int main()
{
	// Input
	size_t size;
	std::cin >> size;

	std::vector<int> v(size, 0);

	for (int i = 0; i < size; ++i)
	{
		std::cin >> v[i];
	}

	// Solution
	std::vector<int> memory;

	for (int i = size - 1, j = 1; i >= 0; --i, ++j)
	{
		if (v[i] == 0)
		{
			memory.push_back(i);
		}
	}

	if (memory.back() > 0)
	{
		for (int i = 0, j = memory.back(); i < memory.back(); ++i, --j)
		{
			v[i] = j;
		}
	}

	if (memory[0] < size - 1)
	{
		for (int i = memory[0] + 1, j = 1; i < size; ++i, ++j)
		{
			v[i] = j;
		}
	}

	while (memory.size() > 0)
	{
		int zero_1 = memory.back();
		memory.pop_back();
		int zero_2 = memory.back();
		for (int i = zero_1 + 1, j = 1, k = zero_2 - 1; i <= k; ++i, ++j, --k)
		{
			v[i] = j;
			v[k] = j;
		}
	}

	// Output
	for (int i = 0; i < size; ++i)
	{
		if (i != 0)
		{
			std::cout << ' ';
		}

		std::cout << v[i];
	}

	std::cout << std::endl;

	return 0;
}