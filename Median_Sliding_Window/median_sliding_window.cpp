#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
class MedianSlidingWindow
{
public:
    multiset<double> arr;
    
    void insert_(double x);
    void delete_(double x);
    double get_median();
    vector<double> get_result(vector<T>& input, int k);
};

template <typename T>
void MedianSlidingWindow<T>::insert_(double x)
{
    arr.insert(x);
}

template <typename T>
void MedianSlidingWindow<T>::delete_(double x)
{
    arr.erase(arr.find(x));
}

template <typename T>
double MedianSlidingWindow<T>::get_median()
{
    double a = *next(arr.begin(), arr.size() / 2 - 1);
    double b = *next(arr.begin(), arr.size() / 2);
    if (arr.size() & 1) return b; 
    return (a + b) * 0.5;
}

template <typename T>
vector<double> MedianSlidingWindow<T>::get_result(vector<T>& input, int k)
{
    vector<double> result;
    arr.clear();
    for (int i = 0; i < k; i++)
        insert_(input[i]);
        
    for (int i = k; i < input.size(); i++)
    {
        result.push_back(get_median());
        delete_(input[i-k]);
        insert_(input[i]);
    }
    result.push_back(get_median());
    return result;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec)
{
    for (auto iter : vec)
        os << iter << " ";
    return os;
}

int main()
{
    vector<double> v = {1.3, 3.2, 5.6, 11.23, 5.66};
    MedianSlidingWindow<double> ob;
    cout << ob.get_result(v, 3);

    return 0;
}

