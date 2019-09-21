#include <iostream>
#include <vector>

using std::string;
using std::vector;
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	
	int n = a.size();
	int m = b.size();
	int p = c.size();
	vector<vector<vector<int>>> d(n + 1, vector<vector<int>>(m + 1, vector<int>(p + 1)));
	for (int i = 0; i <= n; i++)
	{
		d[i][0][0] = 0;
	}
	for (int j = 0; j <= m; j++)
	{
		d[0][j][0] = 0;
	}
	for (int k = 0; k <= p; k++)
	{
		d[0][0][k] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= p; k++)
			{
				if ((a[i - 1] == b[j - 1]) && (a[i-1] == c[k - 1]))
				{
					d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					d[i][j][k] = max(max(d[i - 1][j][k], d[i][j - 1][k]), d[i][j][k - 1]);
				}
			}
		}
	}
	//return std::min(std::min(a.size(), b.size()), c.size());
	return d[n][m][p];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) {
		std::cin >> a[i];
	}
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) {
		std::cin >> b[i];
	}
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) {
		std::cin >> c[i];
	}
	std::cout << lcs3(a, b, c) << std::endl;
	//_getch();
	return 0;
}
