// https://contest.yandex.ru/contest/22450/run-report/154352498/
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
            j = 0;
		}
		else
		{
			v[i] = j;
		}
	}

    bool is_inside = false;
    int j, k, l;

    while (memory.size() > 0)
    {
        l = 1;
        j = memory.back();
        memory.pop_back();
        if (memory.size() > 0)
        {
            k = j + (memory.back() - j) / 2;
            for (int i = j + 1; i <= k; ++i)
            {
                v[i] = l;
                ++l;
            }
        }
        else
        {
            for (int i = j + 1; i < size; ++i)
            {
                v[i] = l;
                ++l;
            }
        }
    }

	
	// Output
	bool is_first = true;

	for (int i = 0; i < size; ++i)
	{
		if (!is_first)
		{
			std::cout << ' ';
		}
		else
		{
			is_first = false;
		}

		std::cout << v[i];
	}

	std::cout << std::endl;

	return 0;
}