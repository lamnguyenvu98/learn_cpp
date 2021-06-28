#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Interval
{
	int first, last;
	
	inline Interval& operator=(const Interval& x)
	{
		first = x.first;
		last = x.last;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Interval& x)
	{
		os << "[" << x.first << ", " << x.last << "]";
		return os;
	}
};

bool compare_Interval(Interval v1, Interval v2)
{
	return v1.first < v2.first;
}

void stack_in_vector(vector<Interval>& vec, stack<Interval>& s)
{
	// base case
	if (s.empty()) return;

	Interval val = s.top();
	s.pop();
	stack_in_vector(vec, s);
	vec.push_back(val);
}

void merge_Interval(vector<Interval> arr, int size)
{
	// sort the Interval array
	sort(arr.begin(), arr.end(), compare_Interval);
	
	// create stack to store interval
	stack<Interval> s;
	
	// push first Interval into stack
	s.push(arr[0]);

	for (int i = 1; i < size; i++)
	{
		Interval top = s.top();
	
	 	// check if there is overlap between Interval in stack (top) 
		// and current interval
		if (top.last < arr[i].first)
		{
			s.push(arr[i]);
		}

		if (top.last < arr[i].last && top.last > arr[i].first)
		{
			top.last = arr[i].last;
			s.pop();
			s.push(top);
		}
	}

	vector<Interval> result;

	stack_in_vector(result, s);

	cout << "Merge overlap: ";
	/*while(!s.empty())
	{
		Interval t = s.top();
		cout << "[" << t.first << ", " << t.last << "]" << " ";
		s.pop();
	}*/

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	cout << endl;
}

int main()
{
	vector<Interval> v = {{1, 4}, {3, 6}, {8, 10}};
	//int size = sizeof(v) / sizeof(Interval);
	merge_Interval(v, v.size());
	return 0;
}




