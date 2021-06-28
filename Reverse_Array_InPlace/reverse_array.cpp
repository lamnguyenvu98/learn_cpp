#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverse_array(int arr[], int size)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = {4, 5 , 1, 13, 10};
	int size = sizeof(arr)/sizeof(int);
	reverse_array(arr,size);
	return 0;
}
