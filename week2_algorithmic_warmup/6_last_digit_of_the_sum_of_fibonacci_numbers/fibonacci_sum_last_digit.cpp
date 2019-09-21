#include <iostream>

int fibonacci_sum_naive(long long n) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;
	long long sum = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		sum += current;
	}

	return sum % 10;
}

long long fibonacci_sum_fast(long long n)
{
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;
	long long sum = 1;

	//pissano period of 10 is 60.

	long long a;
	a = (n+2) % 60;
	//for (long long i = 0; i < n + 1 ; ++i) {
		//long long tmp_previous = previous;
		//previous = current;
		//current = (tmp_previous + current) % 10;
		
	//}

	for (long long i = 0; i < a - 1 ; ++i) {
		long long tmp_previous = previous % 10;
		previous = current % 10;
		current = (tmp_previous + current) % 10;
	}

	if ((current - 1) >= 0)
		return current - 1;
	else
		return 9 ;
	//return current - 1;
}

int main() {
	long long n = 0;
	std::cin >> n;
	//std::cout << fibonacci_sum_naive(n);
	std::cout << fibonacci_sum_fast(n);
}
