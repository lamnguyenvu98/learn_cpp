#include <iostream>
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

int main()
{
	int size = 5;
	int arr[5] = {1, 32, 54, 2, 22};
	find_second_largest_element(arr,size);
	printMaxima(arr, size);
	return 0;
}
