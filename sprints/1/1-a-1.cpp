// https://contest.yandex.ru/contest/22450/run-report/154409416/
// https://contest.yandex.ru/contest/22450/problems/A/

#include <iostream>
#include <stdlib.h>

int main()
{
	unsigned int size;
	std::cin >> size;

	int* v = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i)
	{
		std::cin >> v[i];
	}

	int left = -1, right = 0, pos;

	do
	{
		pos = -1;

		for (int i = right; i < size; ++i)
		{
			if (v[i] == 0)
			{
				pos = i;
				break;
			}
		}


		right = pos;

		if ((left == -1) && (right == -1))
		{
			break;
		}
		else if ((left == -1) && (v[right] == 0))
		{
			for (int i = 0, j = right; i < right; ++i, --j)
			{
				v[i] = j;
			}

			left = right;
			++right;
		}
		else if ((v[left] == 0) && (right == -1))
		{
			for (int i = left, j = 0; i < size; ++i, ++j)
			{
				v[i] = j;
			}

			break;
		}
		else if ((v[left] == 0) && (v[right] == 0))
		{
			for (int i = left, j = right, k = 0; i <= j; ++i, --j, k++)
			{
				v[i] = k;
				v[j] = k;
			}

			left = right;
			++right;
		}
		else
		{
			std::cout << "Something wrong" << std::endl;
			break;
		}
	} while (right < size);


	for (int i = 0; i < size; ++i)
	{
		if (i != 0)
		{
			std::cout << ' ';
		}

		std::cout << v[i];
	}

	std::cout << std::endl;
	
	free(v);

	return 0;
}