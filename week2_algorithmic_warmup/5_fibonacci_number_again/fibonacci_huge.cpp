#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
	if (n <= 1)
		return n;
	int a = 0; 
	int b = 1;
	int c;
	long long temp;
	long long period = 0;
	long long previous = 0;
	long long current = 1;
	do
	{		temp = previous % m;
			previous = current % m;
			current = (temp + current) % m;
			a = previous;
			b = current;
			period++;
		
	} while(!((a == 0) && (b == 1)));
	//std::cout << previous << " " << current<<std::endl;
	//std::cout << a << " " << b << std::endl;
	//std::cout << "The period is: " << period<<std::endl;
	long long d;
	d = n % period; 
	previous = 0;
	current = 1;
	//std::cout << "d is: " << d<<std::endl;
	for (int i = 0; i < d - 1 ; ++i) {
		long long tmp_previous = previous % m;
		previous = current % m;
		current = (tmp_previous + current) % m;
	}
	if (d <= 1)
		return d;
	else
		return current;
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	//std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
	return 0;
}

