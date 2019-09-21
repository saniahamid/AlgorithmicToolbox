#include <iostream>
#include <vector>

using std::string;
using std::vector;
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
	//write your code here
	int n = a.size();
	int m = b.size();
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++)
	{
		d[i][0] = 0;
	}
	for (int i = 0; i <= m; i++)
	{
		d[0][i] = 0;
	}
	int cost = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else
			{
				d[i][j] = std::max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}

	//for (int i = 0; i <= n; i++)
	//{
		//for (int j = 0; j <= m; j++)
		//{
			//cout << d[i][j] << "\t";
		//}
		//cout << endl;
	//}
	//return std::min(std::min(a.size(), b.size()), c.size());
	return d[n][m];
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;
	//_getch();
	return 0;
}
