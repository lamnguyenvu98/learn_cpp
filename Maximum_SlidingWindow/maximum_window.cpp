#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void findMax(int arr[], int n, int k)
{
    deque<int> v(k);
    for (int i = 0; i < k; i++)
    {
        while(!v.empty() && arr[i] >= arr[v.back()])
            v.pop_back();
        
        v.push_back(i);
    }
    
    for (int i = k; i < n; i++)
    {
        cout << arr[v.front()] << " ";
        
        while (!v.empty() && v.front() <= i - k)
            v.pop_front();
        
        while (!v.empty() && arr[i] >= arr[v.back()])
            v.pop_back();
        
        v.push_back(i);
    }
    cout << arr[v.front()];
}

int main()
{
    int n;
    cout << "Size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++)
    {
        cin>>arr[i];
    }
    cout << "\nMax element in k size: \n";
    findMax(arr, n, 3);
}
