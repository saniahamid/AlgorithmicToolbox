#include <iostream>

int get_change(int m) {
	//write your code here
	int x[3] = { 1, 5, 10 };
	int change_count = 0;
	int current_change = 0;
	while (m > 0)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (m >= x[i])
			{
				current_change = x[i];
			}
		}
		//std::cout << "Current change is: " << current_change << std::endl;
		m = m - current_change;
		++change_count;
	}
	return change_count;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
