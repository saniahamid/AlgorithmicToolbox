#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h> 
#include <cassert>
#include <sstream>
#include <string>


using std::vector;


int get_change(int m) {
	//We need n+1 rowss as the table is constructed in bottong up manner using bse case 0
	//value case (n=0)
	vector<vector<int>> table(4);
	int i, j, x, y;
	//Fill the entry for 0 value case
	for (i = 0; i < 4; i++)
	{
		table[i] = vector<int>(m+1);
	}	
	for (i = 0; i < m+1; i++)
	{
		table[0][i] = i;
	}
	for (i = 0; i < 4; i++)
	{
		table[i][0] = 0;
	}
	int coin[4] = {0,1,3,4 };
	//Fill rest of the table entries in bottom up manner
	for (i = 1; i < 4; i++)
	{
		for (j = 1; j < m+1; j++)
		{
			
			if (j >= coin[i])
			{
				x = table[i - 1][j];
				y = 1 + table[i][j - coin[i]];
				table[i][j] = std::min(x, y);
			}
			else
				table[i][j] = table[i - 1][j];
			
		}
		
	}

	//for (i = 0; i < 4; i++) 
	//{
		//for (j = 0; j < table[i].size(); j++)
			//std::cout << table[i][j] << "\t";
		//std::cout << std::endl;
	//}
	return table[3][m];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
	return 0;
}
