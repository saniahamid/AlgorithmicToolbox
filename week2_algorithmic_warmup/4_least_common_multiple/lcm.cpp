#include <iostream>

long long lcm_naive(int a, int b) {
	for (long l = 1; l <= (long long)a * b; ++l)
		if (l % a == 0 && l % b == 0)
			return l;

	return (long long)a * b;
}

long long lcm_fast(long long a, long long b)
{
	long long divisor, remainder, dividend;
	if (a <= b)
	{
		divisor = a;
		dividend = b;
		remainder = dividend % divisor;
	}
	else
	{
		divisor = b;
		dividend = a;
		remainder = dividend % divisor;
	}
	while (remainder != 0)
	{
		dividend = divisor;
		divisor = remainder;
		remainder = dividend % divisor;
	}

	return (a*b) / divisor;
}

int main() {
	long long a, b;
	std::cin >> a >> b;
	//std::cout << lcm_naive(a, b) << std::endl;
	std::cout << lcm_fast(a, b) << std::endl;
	return 0;
}