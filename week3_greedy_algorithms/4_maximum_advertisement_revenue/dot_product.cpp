#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
	// write your code here
	long long result = 0;
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	int n = a.size();
	//std::cout << "The size is: " << n<<std::endl;
	for (int i = n-1; i >= 0; i--) {
		result += ((long long)a[i]) * b[i];
	}
	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::cout << max_dot_product(a, b) << std::endl;
	//_getch();
	return 0;
}