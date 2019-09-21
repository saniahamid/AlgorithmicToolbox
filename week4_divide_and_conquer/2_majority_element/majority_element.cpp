#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int>& a, int left, int right) {
	
	if (left == right) return -1;
	if (left + 1 == right) return a[left];

	int mid = left + (right - left) / 2;
	int left_elm = get_majority_element(a, left, mid);
	int right_elm = get_majority_element(a, mid, right);

	if (left_elm == right_elm)
		return left_elm;

	int countl = 0;
	int countr = 0;

	for(int i = left; i < right; i++)
	{
		if (a[i] == left_elm)
		{
			++countl;
		}
	}
	if (countl > (right - left) / 2) return left_elm;
	
	for (int i = left; i < right; i++)
	{
		if (a[i] == right_elm)
		{
			++countr;
		}
	}
	if (countr > (right - left) / 2) return right_elm;

	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}