#include <iostream>
#include <vector>
#include<algorithm>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
using std::vector;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	int n = weights.size();

	vector<float> ratios(n);
	for (int i = 0; i < n; i++)
	{
		//casting 
		ratios[i] = double(values[i]) / double(weights[i]);
	}
	
	//Making a pair of ratio and weights
	vector< std::pair <double, int> > ratio_weight;
	for (int i = 0; i < n; i++)
		ratio_weight.push_back(std::make_pair(ratios[i], weights[i]));

	//Making a pair of ratio and values
	vector< std::pair <double, int> > ratio_value;
	for (int i = 0; i < n; i++)
		ratio_value.push_back(std::make_pair(ratios[i], values[i]));
	
	//sorting by ratio
	std::sort(ratio_weight.begin(), ratio_weight.end());
	//sorting by ratio
	std::sort(ratio_value.begin(), ratio_value.end());
	
		for (int i = n-1; i >= 0; i--)
		{
			if (ratio_weight[i].second <= capacity)
			{
				value += ratio_value[i].second;
				capacity -= ratio_weight[i].second;
			}
			else
			{
				value += capacity * ratio_value[i].first;
				capacity = 0;
				break;
			}
		}

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);
	cout << std::setprecision(3) << std::fixed;
	round(optimal_value);
	std::cout << optimal_value << std::endl;
	//_getch();
	return 0;
}