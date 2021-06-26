#include <iostream>
using namespace std;

int sum_divisor(int const number)
{
	int result = 1;
	for (int i = 2; i*i < number; i++)
	{
		if (number % i == 0)
			result += (i == (number/i)) ? i : (i + number/i);
	}
	return result;
}

int find_abundant(int const value)
{
	return sum_divisor(value) - value;
}

int main()
{
	int num = 12;
	cout << find_abundant(num) << endl;
	return 0;
}
