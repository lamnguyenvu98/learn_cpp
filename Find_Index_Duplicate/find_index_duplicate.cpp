#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

ostream& operator<<(ostream& os, vector<int> v)
{
	for (auto elem : v)
		os << elem << " ";
	return os;
}

void find_index_duplicate(vector<int> const& data)
{
	int size = data.size();
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < size; i++)
		mp[data[i]].push_back(i);
	
	cout << "Indexes of duplicate element: \n";
	for (auto c : mp)
		if (c.second.size() > 1)
			cout << c.first << " at indexes: " << c.second << endl;
}

int main()
{
	vector<int> data = {1, 1, 3, 2, 43, 3, 1, 44, 43};
	find_index_duplicate(data);
	return 0;
}
