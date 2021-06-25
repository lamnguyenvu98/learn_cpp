#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

string to_roman(unsigned int value)
{
	vector<pair<unsigned int, char const*>> roman = {
	{ 1000, "M" },{ 900, "CM" }, { 500, "D" },{ 400, "CD" },
	{ 100, "C" },{ 90, "XC" }, { 50, "L" },{ 40, "XL" },
	{ 10, "X" },{ 9, "IX" }, { 5, "V" },{ 4, "IV" }, { 1, "I" }};

	string result;
	for (auto const& kvp : roman)
	{
		while(value >= kvp.first)
		{
			result = result + kvp.second;
			value = value - kvp.first;
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	int number = stoi(argv[1]);
	if (argc < 2)
	{
		cout << "./<execute file> <number to convert>" << endl;
		return -1;
	}
	cout << to_roman(number) << endl;
	return 0;
}
