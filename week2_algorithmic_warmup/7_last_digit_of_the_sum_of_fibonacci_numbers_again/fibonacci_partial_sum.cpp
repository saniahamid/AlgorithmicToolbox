#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	long long sum = 0;

	long long current = 0;
	long long next = 1;

	for (long long i = 0; i <= to; ++i) {
		if (i >= from) {
			sum += current;
		}

		long long new_current = next;
		next = next + current;
		current = new_current;
	}

	return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to)
{
	if ((from <= 1) && (to <= 1))
		return to;

	long long previous = 0;
	long long current = 1;
	long long sum_from, sum_to;

	long long a, b;
	a = (from + 1) % 60;
	b = (to + 2) % 60;

	for (long long i = 0; i < a - 1; ++i) {
		long long tmp_previous = previous % 10;
		previous = current % 10;
		current = (tmp_previous + current) % 10;
	}

	long long current_from = current;
	if ((current_from - 1) >= 0)
		sum_from = current_from - 1;
	else
		sum_from = 9;

	previous = 0;
	current = 1;

	for (long long i = 0; i < b - 1; ++i) {
		long long tmp_previous = previous % 10;
		previous = current % 10;
		current = (tmp_previous + current) % 10;
	}

	long long current_to = current;

	if ((current_to - 1) >= 0)
		sum_to = current_to - 1;
	else
		sum_to = 9;

	//std::cout << "sum_to is: " << sum_to;
	//std::cout << "sum_from is: " << sum_from << std::endl;

	if (sum_to <= sum_from)
		return ((10 + sum_to) - sum_from) % 10;
	else
		return (sum_to - sum_from);
}

int main() {
	long long from, to;
	std::cin >> from >> to;
	//std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
	std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}