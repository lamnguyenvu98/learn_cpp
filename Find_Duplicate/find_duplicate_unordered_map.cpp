#include <iostream>
#include <unordered_map>
using namespace std;

void find_element(int arr[], int size)
{
	unordered_map<int , int > mp;
	for (int i = 0; i < size; i++)
		mp[arr[i]]++;
	cout << "Duplicate elements are: ";
	for (auto k : mp)
	{
		if (k.second > 1) cout << k.first << " ";
	}
	cout << "\n";
	cout << "Frequency of each element: ";
	for (auto k : mp)
		cout << k.first << " -> " << k.second << " times" << endl;
	cout << "\n";
}

int main()
{
	int arr[] = {2, 5, 32, 1, 6, 2, 5, 5, 12};
	int size = sizeof(arr)/sizeof(int);
	find_element(arr, size);
	return 0;
}
