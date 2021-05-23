#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            os << v[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << " ";
    }
    return os;
}

void transpose(vector<vector<int> > &b)
{
    if (b.size() == 0)
        return;

    vector<vector<int> > trans_vec(b[0].size(), vector<int>(b.size()));
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            //trans_vec[j].push_back(b[i][j]);
            trans_vec[j][i] = b[i][j];
        }
    }
    b = trans_vec;
}

int main()
{
    vector<vector<int>> vec = { {1, 2, 3}, {4, 5, 6} };
    transpose(vec);
    cout << vec;

    return 0;
}

