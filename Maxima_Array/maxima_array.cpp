#include <iostream>
#include <algorithm>
using namespace std;

void find_second_largest_element(int arr[], int size)
{
	int max = 0;
	int second_max = 0;

	// Find max element
	for (int i = 0; i < size; i++)
		if (arr[max] < arr[i])
			max = i;
	
	cout << "Max element: " << arr[max] << " at index: " << max << "\n";

	// Find second max element
	for (int i = 0; i < size; i++)
		if (i != max && arr[second_max] < arr[i])
			second_max = i;

	cout << "Second max element: " << arr[second_max] << " at index: " << second_max << endl;
}

void printMaxima(int arr[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[max] < arr[i])
		{
			cout << "Max " << i << ": " << arr[i] << endl;
			max = i;
		}
	}
}

void printAlternateElement(int arr[], int size)
{
	cout << "Alternate element in array are: ";
	for (int i = 0; i < size; i++)
	{
		// Alternate elements are element at odd index such as 1, 3, 5, ...
		if (i % 2 == 0)
			cout << arr[i] << " ";
	}
	cout << "\n";
}

// array full of 0 and 1, write function sergregate 0 on left, 1 on right
void sergregate_array(int arr[], int size)
{
	cout << "Sergregate array: ";
	sort(arr, arr + size, [](int a, int b){
		return a < b;
			});
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int size = 5;
	int arr[5] = {1, 32, 59, 23, 22};
	int new_arr[] = {0, 1, 1, 1, 0};
	int n = sizeof(new_arr) / sizeof(int);
	find_second_largest_element(arr,size);
	printMaxima(arr, size);
	printAlternateElement(arr, size);
	sergregate_array(new_arr, n);
	return 0;
}
