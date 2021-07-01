// C++ program to print the count of
// subsets with sum equal to the given value X

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to return the count
// of subsets with sum equal to the given value
int subsetSum(vector<vector<int>>& lol, vector<int>& arr, int i,
			int sum, int count, vector<int>& l)
{
	// The recursion is stopped at N-th level
	// where all the subsets of the given array
	// have been checked
	int n = arr.size();
	if (i == n) {

		// Incrementing the count if sum is
		// equal to 0 and returning the count
		if (sum == 0) {
			count++;
			lol.push_back(l);
		}
		//if (sum > arr[i]);
		return count;
	}

	// Recursively calling the function for two cases
	// Either the element can be counted in the subset
	// If the element is counted, then the remaining sum
	// to be checked is sum - the selected element
	// If the element is not included, then the remaining sum
	// to be checked is the total sum
	l.push_back(arr[i]);
	count = subsetSum(lol, arr, i + 1, sum - arr[i], count, l);
	l.pop_back();
	count = subsetSum(lol, arr, i + 1, sum, count, l);
	return count;
}

// Driver code
int main()
{
	vector<int> input = { 1, 2, 3, 5, 6};
	vector<vector<int>> lol;
	vector<int> l;
	int sum = 6;
	//int n = sizeof(arr) / sizeof(arr[0]);

	cout << subsetSum(lol, input, 0, sum, 0, l) << endl;;
	for (auto data : lol)
	{
		for (auto d : data)
			cout << d << " ";
		cout << endl;
	}
	return 0;
}

