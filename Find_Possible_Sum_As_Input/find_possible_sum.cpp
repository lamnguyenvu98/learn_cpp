#include <iostream>
#include <algorithm>
using namespace std;

int findSmallClosest(int arr[], int n, int target)
{
    int idx;
    if (target <= arr[0])
        return 0;
    if (target >= arr[n-1])
        return arr[n-1];
    
    int l = 0, h = n, mid = 0;
    while (l < h)
    {
        mid = (l + h)/2;
        if (target >= arr[mid])
        {
            // search right
            if (mid < n - 1 && target < arr[mid + 1])
                idx = mid;
            l = mid + 1;
        }
        if (target < arr[mid])
        {
            // search left
            if ( mid > 0 && target > arr[mid - 1])
                idx = mid - 1;
            h = mid;
        }
    }
    return idx;
}

int findPossibleSum(int arr[], int n, int target)
{
	int idx, dem = 0;
	sort(arr, arr + n);
	idx = findSmallClosest(arr, n, target);
	for (int i = 0; i <= idx; i++)
	{
		int sum = arr[i];
		for (int j = i + 1; j <= idx; j++)
		{
			if (sum > target)
			{
				sum -= arr[j];
                continue;
			}
			else if (sum == target) dem++;
			else sum += arr[j];
		}
	}
	return dem;
}

int main()
{
	int n = 5;
	int arr[n] = {1, 5 ,4 , 2 ,10};
	int input = 9;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	    cout << arr[i] << " ";
	cout << endl;
	cout << findPossibleSum(arr, n, input);
	//cout << findSmallClosest(arr, n, input);
	return 0;
}
