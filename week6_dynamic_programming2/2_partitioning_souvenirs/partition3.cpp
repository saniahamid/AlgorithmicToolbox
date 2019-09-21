#include <iostream>
#include <vector>
#include <numeric> 

using std::vector;
using namespace std;

int partition3(vector<int> &A) {
	int n = A.size();
	int sum = accumulate(A.begin(), A.end(), 0);

	if (sum % 3 != 0)
	{
		return 0;
	}
	vector<vector<int>>d(n + 1, vector<int>((sum / 3) + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum / 3; j++)
		{
			if (j >= A[i - 1])
			{
				d[i][j] = max(d[i - 1][j - A[i - 1]] + A[i - 1], d[i - 1][j]);
			}
			else
			{
				d[i][j] = d[i - 1][j];
			}
		}
	}
	//for (int i = 0; i <= n; i++)
	//{
		//for (int j = 0; j <= sum / 3; j++)
		//{
			//cout << d[i][j] << " ";
		//}
		//cout << endl;
	//}
	return d[n][sum/3]==sum/3;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) {
		std::cin >> A[i];
	}
	std::cout << partition3(A) << '\n';
	//_getch();
	return 0;
}
