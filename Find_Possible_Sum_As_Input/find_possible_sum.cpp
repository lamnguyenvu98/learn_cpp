#include <iostream>
#include <algorithm>
using namespace std;

int findPossibleSum(int arr[], int n, int in)
{
	int idx, dem = 0;
	sort(arr, arr + n);
	auto itr = find(arr, arr + n, in);
	if (itr != (arr + n))
	{
		idx = distance(arr, itr); 
	}
	else idx = n;
	
	for (int i = 0; i < idx; i++)
	{
		int sum = arr[i];
		for (int j = i + 1; j < idx; j++)
		{
			if (sum > in)
			{
				sum -= arr[j];
			}
			else if (sum == in) dem++;
			else sum += arr[j];
		}
	}
	return dem;
}

int main()
{
	int n = 6;
	int arr[n] = {1, 5, 7, 15, 16, 9, 11, 6};
	int input = 12;
	cout << findPossibleSum(arr, n, input);
	return 0;
}
