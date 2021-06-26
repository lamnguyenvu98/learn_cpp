#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reserved_array(vector<int>& vec, int start, int end)
{
	while (start < end)
	{
		swap(vec[start], vec[end]);
		start++;
		end--;
	}
}

void rotate_array(vector<int>& vec, int k)
{
	int size = vec.size();
	reserved_array(vec, 0, k - 1);
	reserved_array(vec, k, size - 1);
	reserved_array(vec, 0, size - 1);
}

int main()
{
	vector<int> v;
	int n = 1;
	while (n <= 10)
	{
		v.push_back(n);
		n++;
	}
	
	rotate_array(v, 4);
	for (int iter : v)
	{
		cout << iter << " ";
	}
	cout << "\n";

}
