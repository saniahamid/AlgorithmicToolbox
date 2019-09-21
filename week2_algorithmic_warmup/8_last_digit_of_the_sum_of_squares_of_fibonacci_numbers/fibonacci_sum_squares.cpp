#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;
	long long sum = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		sum += current * current;
	}

	return sum % 10;
}

int fibonacci_sum_squares_fast(long long n)
{
	if ((n <= 1))
		return n;

	long long length, breadth, a, b;
	length = n + 1;
	breadth = n;

	long long previous = 0;
	long long current = 1;

	//pissano period of 10 is 60
	a = length % 60;
	b = breadth % 60;

	for (long long i = 0; i < a - 1; ++i) {
		long long tmp_previous = previous % 10;
		previous = current % 10;
		current = (tmp_previous + current) % 10;
	}

	long long length_last_digit;
	if (a == 0)
	{
		length_last_digit = 0;
	} 
	else {
		length_last_digit = current;
	} 

	previous = 0;
	current = 1;

	for (long long i = 0; i < b - 1; ++i) {
		long long tmp_previous = previous % 10;
		previous = current % 10;
		current = (tmp_previous + current) % 10;
	}

	long long breadth_last_digit;
	if (b == 0)
	{
		breadth_last_digit = 0;
	}
	else {
		breadth_last_digit = current;
	}
	//std::cout << a <<" "<< b;
	//std::cout << "breadth is: " << breadth_last_digit << std::endl << "length is: " << length_last_digit << std::endl;
	return ((length_last_digit * breadth_last_digit) % 10);

}

int main() {
	long long n = 0;
	std::cin >> n;
	//std::cout << fibonacci_sum_squares_naive(n);
	std::cout << fibonacci_sum_squares_fast(n);
}