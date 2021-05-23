#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class LongestSubsequence
{
private:
    T *arr;
    int n;
public:
    LongestSubsequence(T arr[], int n)
    {
        this->arr = arr;
        this->n = n;
    }
    int max(int a, int b);
    int increasing();
    int non_decreasing();
    vector<T> list_increasing();
    vector<T> list_non_decreasing();
};

template <typename T>
int LongestSubsequence<T>::max(int a, int b)
{
    return (a > b) ? a : b;
}

template <typename T>
int LongestSubsequence<T>::increasing()
{
    int length[n] = {1}; // fill array with 1 elements
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && length[i] < length[j] + 1)
                length[i] = length[j] + 1;
    }
    int lis = 0;
    for (int i = 0; i < n; i++)
        lis = max(lis, length[i]);
    return lis;
}

template <typename T>
int LongestSubsequence<T>::non_decreasing()
{
    int length[n] = {1}; // fill array with 1 elements
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j] && length[i] < length[j] + 1)
                length[i] = length[j] + 1;
    }
    int lis = 0;
    for (int i = 0; i < n; i++)
        lis = max(lis, length[i]);
    return lis;
}

template <typename T>
vector<T> LongestSubsequence<T>::list_increasing()
{
    vector<vector<T>> L(n);
    L[0].push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && L[i].size() < L[j].size() + 1)
                L[i] = L[j];
        }
        L[i].push_back(arr[i]);
    }
    
    vector<T> max_ = L[0];
    for (auto x : L)
    {
        if (x.size() > max_.size())
            max_ = x;
    }
    return max_;
}

template <typename T>
vector<T> LongestSubsequence<T>::list_non_decreasing()
{
    vector<vector<T>> L(n);
    L[0].push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] >= arr[j] && L[i].size() < L[j].size() + 1)
                L[i] = L[j];
        }
        L[i].push_back(arr[i]);
    }
    
    vector<T> max_ = L[0];
    for (auto x : L)
    {
        if (x.size() > max_.size())
            max_ = x;
    }
    return max_;
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v)
{
    os << "(";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
        else os << ")";
    }
    return os;
}

int main()
{
    float a[] = { -1.0, 3.2, 4.0, 5.3, 2.2, 2.2, 2.5, 3.0};
    LongestSubsequence<float> l(a, 8);
    //vector<float> result = l.list_non_decreasing();
    cout << "List of non decreasing: " << l.list_non_decreasing();
    cout << "\nLength of non decreasing: " << l.non_decreasing();
    cout << "\nList of increasing: " << l.list_increasing();
    cout << "\nLength of increasing: " << l.increasing();
    return 0;
}
