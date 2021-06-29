#include <iostream>
#include <algorithm>
using namespace std;

void find_duplicate(int arr[], int size)
{
	bool trace[size];
	int count;
	
	sort(arr, arr + size);
	cout << "Duplicate elements are: ";
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == arr[i-1]) 
		{
			// 1, 1, 2, 2, 4, 4, 4, 5
			trace[i] = true;
			trace[i-1] = false;
		}
		else trace[i] = false;
	}

	for (int i = 0; i < size; i++)
		if (trace[i]) cout << arr[i] << " ";

	cout << "\n";
}

int main()
{
	int arr[] = {1, 1, 4, 2, 2, 4, 4, 5};
	int size = sizeof(arr)/sizeof(int);
	find_duplicate(arr, size);
	return 0;
}
