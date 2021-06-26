#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> vec, int value)
{
    int low = 0, high = vec.size() - 1;
    int mid;
	while(low <= high)
    {

    	mid = low + (high - low)/2;
        if (vec[mid] == value) return mid;
        else
        {
            if (value < vec[mid]) high = mid - 1;
            else low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v {1, 4, 5, 7 ,8, 9, 12};
    sort(v.begin(), v.end());
	cout << BinarySearch(v, 8) << endl;
}
