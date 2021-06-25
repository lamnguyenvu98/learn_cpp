#include <iostream>
using namespace std;

bool checkPrime(int num)
{
	if (num <= 3) return num > 1;
	else if (num % 2 == 0 || num % 3 == 0) return false;
	else
	{
		for (int i = 5; i * i <= num; i+=6)
		{
			if (num % i == 0 || num % (i+2) == 0)
				return false;
		}
		return true;
	}
}

void sexy_prime(int num)
{
	for (int i = 2; i <= num; i++)
	{
		if (checkPrime(i) && checkPrime(i+6))
			cout << "(" << i << ", " << i+6 << ")" << endl;
	}
}

int main()
{
	sexy_prime(485);
	return 0;
}
