#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

template <typename T>
class dynamic_array
{
	private:
		T* data;
		size_t n;
	public:
		dynamic_array(int n)
		{
			this->n = n;
			data = new T[n];
		}

		dynamic_array(const dynamic_array<T>& other)
		{
			n = other.n;
			data = new T[n];
			for (int i = 0; i < n; i++)
			{
				data[i] = other[i];
			}
		}

		T& operator[](int index)
		{
			return data[index];
		}

		const T& operator[](int index) const
		{
			return data[index];
		}

		T& at(int index)
		{
			if (index < n)
				return data[index];
			throw string("Index out of range");
		}

		size_t size() const
		{
			return n;
		}

		~dynamic_array()
		{
			delete[] data; // prevate memory leak
		}

		// add Iterator function
		T* begin()
		{
			return data;
		}

		const T* begin() const
		{
			return data;
		}

		T* end()
		{
			return data + n;
		}

		const T* end() const
		{
			return data + n;
		}

		friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, const dynamic_array<T>& arr2)
		{
			dynamic_array<T> result(arr1.size() + arr2.size());
			copy(arr1.begin(), arr1.end(), result.begin());
			copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
			return result;
		}

		dynamic_array<T> add(const dynamic_array<T>& arr)
		{
			dynamic_array<T> result(arr.size());
			for (int i = 0; i < arr.size(); i++)
				result[i] = data[i] + arr[i];
			return result;
		}

		string to_string(const string& sep = ", ")
		{
			if (n==0)
				return "";
			ostringstream os;
			os << data[0];

			for (int i = 1; i < n; i++)
				os << sep << data[i];

			return os.str();
		}

		friend ostream& operator<<(ostream& os, const dynamic_array<T>& arr)
		{
			os << "[";
			for (int i = 0; i < arr.size(); i++)
			{
				if (i != arr.size() - 1 )
					os << arr[i] << " ";
				else os << arr[i];
			}
			os << "]";
			return os;
		}


};
