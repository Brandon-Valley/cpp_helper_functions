
#include <iostream>
#include <vector>

using namespace std;
using std::vector;


template <typename T>
string content(vector<T> vec)
{
	string result = "[";

	for (int i = 0 ; i < vec.size() ; i++)
	{
		result += to_string(vec[i]);

		if ( i < vec.size() - 1 )
			result += ", ";
	}

	result += "]";
	return result;
}



string content(vector<string> vec)
{
	string result = "[";

	for (int i = 0 ; i < vec.size() ; i++)
	{
		result += "\"" + vec[i] + "\"";

		if ( i < vec.size() - 1 )
			result += ", ";
	}

	result += "]";
	return result;
}



string content(vector<char> vec)
{
	string result = "[";

	for (int i = 0 ; i < vec.size() ; i++)
	{
		result += "\'";
		result += vec[i];
		result += "\'";

		if ( i < vec.size() - 1 )
			result += ", ";
	}

	result += "]";
	return result;
}


int main()
{
	cout << "hi" << endl;

	vector<int> v1 = {9, 4, 444, NULL, 0 };
	vector<string> v2 = {"sfdsd", "", "df", "0"};
	vector<char> v3 = {'s', 'o', '3', '0'};


	cout << content(v1) << endl;
	cout << content(v2) << endl;
	cout << content(v3) << endl;
}
