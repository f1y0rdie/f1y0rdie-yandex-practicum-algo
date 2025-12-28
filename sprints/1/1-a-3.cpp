// https://contest.yandex.ru/contest/22450/run-report/154409154/
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
	for (int i = size - 1, j = 1; i >= 0; --i, ++j)
	{
		if (v[i] == 0)
		{
			j = 0;
		}
		else
		{
			v[i] = j;
		}
	}

	bool is_inside = false;
	int j, k;

	for (int i = 0; i < size; ++i)
	{
		if (v[i] == 0)
		{
			is_inside = true;
			if (i < size - 1)
			{
				j = 1;
				if (v[i + 1] == size - i - 1)
				{
					k = v[i + 1];
				}
				else
				{
					k = v[i + 1] / 2;
				}
			}
		}
		else if (is_inside)
		{
			if (j <= k)
			{
				v[i] = j;
				++j;
			}
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