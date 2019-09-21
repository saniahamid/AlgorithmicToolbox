#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	
	stops.insert(stops.begin(), 0);
	stops.push_back(dist);
	int num_stops = 0;
	int last_refill = 0;
	int current_refill = 0;
	int n = stops.size();
	while (current_refill < n-1)
	{
		last_refill = current_refill;
		while ((current_refill < n-1) && ((stops.at(current_refill + 1) - stops.at(last_refill)) <= tank))
		{
			++current_refill;
		}
		if (current_refill == last_refill)
		{
			return -1;
		}
		if (current_refill < n-1)
		{
			
			++num_stops;
		}
	}
	return num_stops;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";
	//_getch();
	return 0;
}