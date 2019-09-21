#include <iostream>

int gcd_naive(int a, int b) {
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
			if (d > current_gcd) {
				current_gcd = d;
			}
		}
	}
	return current_gcd;
}

int gcd_fast(int a, int b)
{
	int divisor, remainder, dividend;
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

	return divisor;

}

int main() {
	int a, b;
	std::cin >> a >> b;
	//std::cout << gcd_naive(a, b) << std::endl;
	std::cout << gcd_fast(a, b) << std::endl;
	return 0;
}
