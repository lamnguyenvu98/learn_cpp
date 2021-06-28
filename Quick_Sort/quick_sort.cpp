#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while(left <= right && arr[left] < pivot) left++;
		while(left <= right && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		quick_sort(arr, low, p - 1);
		quick_sort(arr, p + 1, high);
	}
}

int main()
{
	int arr[] = {1, 0, 1, 1, 0, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
