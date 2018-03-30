
#include <iostream>
#include <vector>

using namespace std;
using std::vector;



// This relies on you having implemented the .at() and .size() member functions first.
template <typename T>
std::ostream & operator << (std::ostream &out, vector<T> &vec)
{
    out << "[";

    for(int i = 0; i < vec.size(); i++)
    {
    	if ( i < vec.size() - 1 )
    		out << vec.at(i) << ", ";
    	else
    		out << vec.at(i);
    }
    out << "]";

    return out;
}


std::ostream & operator << (std::ostream &out, vector<string> &vec)
{
    out << "[";

    for(int i = 0; i < vec.size(); i++)
    {
    	if ( i < vec.size() - 1 )
    		out << "\"" << vec.at(i) << "\"" << ", ";
    	else
    		out << "\"" << vec.at(i) << "\"";
    }
    out << "]";

    return out;
}


std::ostream & operator << (std::ostream &out, vector<char> &vec)
{
    out << "[";

    for(int i = 0; i < vec.size(); i++)
    {
    	if ( i < vec.size() - 1 )
    		out << "\'" << vec.at(i) << "\'" << ", ";
    	else
    		out << "\'" << vec.at(i) << "\'";
    }
    out << "]";

    return out;
}



template <typename T>
void print(vector<T> vec){ cout << content(vec) << endl; }

int main()
{
	vector<int> v1 = {9, 4, 444, NULL, 0 };
	vector<string> v2 = {"sfdsd", "", "df", "0"};
	vector<char> v3 = {'s', 'o', '3', '0'};

	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
}
