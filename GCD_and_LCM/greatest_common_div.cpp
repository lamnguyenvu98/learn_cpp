#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gcd(int number1, int number2)
{
	return (number2 == 0) ? number1 : gcd(number2, number1 % number2); 
}

template<typename... ARGS>
int gcd(int number, ARGS&... args)
{
	return gcd(number, gcd(args...));
}

int GCD(vector<int> vec)
{
	int result = vec[0];
	int n = vec.size();
	for (int i = 1; i < n; i++)
	{
		result = gcd(vec[i], result);
		if (result == 1) return 1;
	}
	return result;
}

int main(int argc, char* argv[])
{
	/*
	int number1 = stoi(argv[1]);
	int number2 = stoi(argv[2]);
	int number3 = stoi(argv[3]);
	cout << gcd(number1, number2, number3) << endl;
	*/
	
	vector<int> input(argc);

	for (int i = 1; i < argc; i++)
	{
		input.push_back(stoi(argv[i]));
	}
	
	cout << GCD(input) << endl;

	return 0;
}
