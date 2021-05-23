/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

ostream& operator<<(ostream& os, vector<int> v)
{
    os << "( ";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << " ";
    }
    os << ")";
    return os;
}

void transpose(vector<vector<int> > &b)
{
    if (b.size() == 0)
        return;

    vector<vector<int> > trans_vec(b[0].size(), vector<int>());

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].push_back(b[i][j]);
        }
    }

    b = trans_vec;
}

vector<int> sliding_window(const vector<int>& v, int k)
{
    vector<int> result;
    deque<int> window(k);
    int n = v.size();
    for (int i = 0; i < k; i++)
    {
        while (!window.empty() && v[i] >= v[window.back()])
            window.pop_back();
        
        window.push_back(i);
        
    }
    
    for (int i = k; i < n; i++)
    {
        result.push_back(v[window.front()]);
        
        while (!window.empty() && window.front() <= i - k)
            window.pop_front();
            
        while (!window.empty() && v[i] >= v[window.back()])
            window.pop_back();
        
        window.push_back(i);
    }
    result.push_back(v[window.front()]);
    return result;
}

int main()
{
    vector<vector<int>> vec = {
        {3, 4, 2, 1},
        {1, 5, 4, 6},
        {3, 6, 7, 2},
        {3, 2, 5, 4}
    };
    
    vector<vector<int>> slicing_row;
    vector<vector<int>> slicing_col;
    
    for (int i = 0; i < vec.size(); i++)
    {
        vector<int> result = sliding_window(vec[i], 2);
        slicing_row.push_back(result);
    }
    transpose(slicing_row);
    
    
    for (int i = 0; i < slicing_row.size(); i++)
    {
        vector<int> result = sliding_window(slicing_row[i], 2);
        slicing_col.push_back(result);
    }
    transpose(slicing_col);
    
    for (int i = 0; i < slicing_col.size(); i++)
        cout << slicing_col[i] << " ";
    return 0;
}

