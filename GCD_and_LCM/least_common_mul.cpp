#include <iostream>
#include <vector>
#include <string>
using namespace std;

int get_abs(int value)
{
	int result = (value >> 31);
	return (value ^ result) - result;
}

int gcd(int num1, int num2)
{
	return (num2 == 0) ? num1 : gcd(num2, num1 % num2);
}

int lcm(int num1, int num2)
{
	return get_abs(num1  * num2) / gcd(num1, num2);
}

int LCM(vector<int> vec)
{
	int result = vec[0];
	int n = vec.size();
	for (int i = 1; i < n; i++)
	{
		result = lcm(vec[i], result);
		if (result == 1) return vec[i];
	}
	return result;
}

int main(int argc, char* argv[])
{
	/*
	int num1 = stoi(argv[1]);
	int num2 = stoi(argv[2]);
	cout << lcm(num1, num2) << "\n";
	*/
	vector<int> input;
	for (int i = 1; i < argc; i++)
	{
		input.push_back(stoi(argv[i]));
	}
	cout << LCM(input) << endl;
	return 0;
}

