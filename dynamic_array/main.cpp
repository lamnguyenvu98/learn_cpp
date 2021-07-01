#include "dynamic_array.hpp"

struct Student
{
	string name;
	int id;

	friend ostream& operator<<(ostream& os, const Student& s)
	{
		os << "[Name: " << s.name << ", ID: " << s.id << "]";
		return os;
	}
};

int main()
{
	dynamic_array<int> arr(4);
	for (int i = 0; i < 4; i++)
		arr[i] = i + 1;

	cout << "Array 1: \n" << arr << endl;

	dynamic_array<int> arr2(4);
	for (int i = 0; i < 4; i++)
		arr2[i] = (i + 1)*3;
	
	cout << "\nArray 2: \n" << arr2 << endl;

	dynamic_array<int> result = arr + arr2;

	cout << "\nConcat 2 array: \n" << result << endl;

	dynamic_array<int> add_result = arr.add(arr2);

	cout << "\nElement wise add: \n" << add_result << endl;
	
	cout << "\nData type struct: \n";

	dynamic_array<Student> student(2); 
	student[0] = Student{"John", 8}; 
	student[1] = Student{"Mark", 9};
	
	try 
	{
		//student[2] = Student{"Neil", 10};
		student.at(2) = Student{"Neil", 10};
	}

	catch(string s)
	{
		cout << s << endl;
	}

	cout << student << endl;

	cout << "\nSmall test: \n";
	cout << *(arr.end() - 2) << endl;

	return 0;
}
