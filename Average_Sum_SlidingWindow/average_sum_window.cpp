#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
void average_window(T arr[], int n, int k)
{
    T sum = 0.0;
    T avg = 0.0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    
    avg = sum / k;
    
    for (int i = k; i < n; i++)
    {
        cout << fixed;
        cout << setprecision(2);
        cout << avg << " ";
        sum = sum + arr[i] - arr[i-k];
        avg = sum / k;
    }
    cout << fixed;
    cout << setprecision(2);
    cout << avg << " ";
}

template <class T>
void sum_window(T arr[], int n, int k)
{
    T sum = 0.0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    
    for (int i = k; i < n; i++)
    {
        cout << sum << " ";
        sum = sum + arr[i] - arr[i-k];
    }
    cout << sum << " ";
}

int main()
{
    double arr[5] = {1.0, 2.5 , 3.23, 2.12, 4.9};
    int arrr[6] = {1, 5 ,2 ,6 ,7, 2};
    average_window(arr, 5, 3);
    cout << " \n";
    sum_window(arrr, 6, 2);

    return 0;
}

