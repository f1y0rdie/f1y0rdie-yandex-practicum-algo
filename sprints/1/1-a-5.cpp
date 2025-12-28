// https://contest.yandex.ru/contest/22450/run-report/154493237/
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

	enum class State
	{
		Init,
		Before,
		Between,
		After,
		Exit
	};

	State state = State::Init, next_state = State::Exit;

	int zero_1 = 0, zero_2 = 0;

	while (state != State::Exit)
	{
		switch (state)
		{
			case State::Init:
				if (memory.size() > 0)
				{
					zero_1 = memory.back();
					next_state = State::Before;
				}
				else
				{
					next_state = State::Exit;
				}
				break;
			case State::Before:
				for (int i = 0, j = zero_1; i < zero_1; ++i, --j)
				{
					v[i] = j;
				}

				memory.pop_back();

				if (memory.size() > 0)
				{
					zero_2 = memory.back();
					next_state = State::Between;
				}
				else
				{
					next_state = State::After;
				}
				break;
			case State::Between:
				for (int i = zero_1 + 1, j = 1, k = zero_2 - 1; i <= k; ++i, ++j, --k)
				{
					v[i] = j;
					v[k] = j;
				}

				memory.pop_back();

				if (memory.size() > 0)
				{
					zero_1 = zero_2;
					zero_2 = memory.back();

					next_state = State::Between;
				}
				else
				{
					zero_1 = zero_2;
					next_state = State::After;
				}			
				break;
			case State::After:
				for (int i = zero_1 + 1, j = 1; i < size; ++i, ++j)
				{
					v[i] = j;
				}
				next_state = State::Exit;
				break;
			default:
				next_state = State::Exit;
				break;
			}
        state = next_state;
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