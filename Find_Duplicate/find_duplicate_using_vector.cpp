#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void find_duplicate(int arr[], int size)
{
	vector<int> vec;
	cout << "Duplicate elements are (method 1): ";
	for (int i = 0; i < size; i++)
	{
		if (find(vec.begin(), vec.end(), arr[i]) != vec.end())
			cout << arr[i] << " ";
		else vec.push_back(arr[i]); 
	}
	cout << "\n";
}

void find_dub(vector<int>& data)
{
	int size = data.size();
	vector<int> counter(size, 0);
	cout << "Duplicate elements are (method 2): ";
	for (int i = 0; i < size; i++)
	{
		if (counter[data[i]] == 1) 
			cout << data[i] << " ";
		else counter[data[i]]++;
	}
	cout << "\nSize: " << counter.size() << endl;
	for (auto c : counter)
		cout << c << " " << endl;
}

int main()
{
	int arr[] = {1, 1, 32, 32, 5, 1, 2, 5, 22};
	vector<int> input = {1, 1, 32, 32, 5, 1, 2, 5, 22};
	int size = sizeof(arr)/sizeof(int);
	find_duplicate(arr, size);
	cout << "\n";
	find_dub(input);
	return 0;
}
