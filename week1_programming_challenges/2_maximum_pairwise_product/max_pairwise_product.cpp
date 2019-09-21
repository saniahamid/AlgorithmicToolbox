
#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<long long>& numbers) {
	long long max_product = 0;
	int n = numbers.size();

	int index1, index2;

	index1 = 0;
	index2 = 0;
	for (int i = 1; i < n; i++)
	{
		if (numbers[i] > numbers[index1])
		{
			index1 = i;
		}
	}

	if (index1 == 0)
		index2 = 1;
	else
		index2 = 0;

	for (int i = 1; (i < n) ; i++)
	{
		if ((i != index1) && (numbers[i] > numbers[index2]))
		{
			index2 = i;
		}
	}

	return numbers[index1] * numbers[index2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
	
	/*while (true)
	{

	}
*/
		
    return 0;
}

