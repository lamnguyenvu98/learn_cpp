#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

void print_ordered(stack<pair<int, int>>& s)
{
    // base
    if (s.empty()) return;
    pair<int, int> val = s.top();
    s.pop();
    print_ordered(s);
    cout << "[" << val.first << ", " << val.second << "] ";
}

void merge_interval(vector<pair<int, int>> vec)
{
    if (vec.size() == 0) return;
    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });
    
    stack<pair<int, int>> s;
    s.push(vec[0]);
    
    for (int i = 1; i < vec.size(); i++)
    {
        pair<int, int> top = s.top();
        
        if (top.second < vec[i].first)
            s.push(vec[i]);
        
        if (top.second < vec[i].second && top.second > vec[i].first)
        {
            top.second = vec[i].second;
            s.pop();
            s.push(top);
        }
    }
    
    // while (!s.empty())
    // {
    //     pair<int, int> p = s.top();
    //     cout << "[" << p.first << ", " << p.second << "] ";
    //     s.pop();
    // }
   print_ordered(s);
    cout << endl;
}

int main()
{
    vector<pair<int, int>> input = {{1, 4}, {3, 6}, {8, 10}};
    merge_interval(input);
    return 0;
}

