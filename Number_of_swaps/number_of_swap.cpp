#include <bits/stdc++.h>
using namespace std;

int number_of_swap(int arr[], int n)
{
    int count = 0;
    vector<pair<int, int>> v(n);
    
    for (int i = 0; i < n; i++)
    {
        v[i].first = arr[i];
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    cout << "Sort an array: \n";
	for (auto p : v)
        cout << p.first << " - " << p.second << endl;
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == i) continue;
        swap(v[i].first, v[v[i].second].first);
        swap(v[i].second, v[v[i].second].second);
        if (i != v[i].second) i--;
        count++;
    }
	cout << "Array when not sorted: \n";
    for (auto p : v)
        cout << p.first << " - " << p.second << endl;
    
	cout << "\nNumber of swap when sort array are: " << count << endl;
    return count;
}

int main()
{
    int arr[] = {12, 15, 11, 14, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    number_of_swap(arr, n);
}
