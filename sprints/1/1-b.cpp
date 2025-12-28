// https://contest.yandex.ru/contest/22450/run-report/154408945/
// https://contest.yandex.ru/contest/22450/problems/B/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
	// Input
	int k;
	std::cin >> k;

	std::string line;
	getline(std::cin, line);
	
	std::vector<int> v(10, 0);

	for (int i = 0; i < 4; ++i)
	{
		getline(std::cin, line);
		for (int j = 0; j < 4; ++j)
		{
			if (isdigit(line[j]))
			{
				++v[line[j] - '0'];
			}
		}
	}

	// Solution
	int sum = 0;
	for (int i = 1; i <= 9; ++i)
	{
		if (v[i] > 0 && v[i] <= k * 2)
		{
			++sum;
		}
	}

	// Output
	std::cout << sum << std::endl;

	return 0;
}