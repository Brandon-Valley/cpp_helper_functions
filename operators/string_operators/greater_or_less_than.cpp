
#include "string_operators.h"

// "9" < "10" , "-10" < "-9" < "0"  - useful for BigIntegers
//bool operator < (const string &a, const BigInteger &b)
//{
//	if 		(a.length() > b.length())
//		return true;
//	else if (a.length() < b.length() or a == b)
//		return false;
//
//
//	int a_digit;
//	int b_digit;
//
//	// lengths =
//	for(int i = a.length() ; i > 0 ; i--)
//	{
//		a_digit = a[i - 1] - '0';
//		b_digit = b[i - 1] - '0';
//
//		if 		(a_digit > b_digit)
//			return true;
//		else if (a_digit < b_digit)
//			return false;
//	}
//	return false; //should never get here
//}


// "5"	  > "4"
// "-010" > "-000900"
bool a_greater_than_b(string a, string b)
{
	if (a == b)
		return false;

	a = trim_leading_0s(a);
	b = trim_leading_0s(b);

	bool a_neg = false;
	bool b_neg = false;

	if (a[0] == '-')
		a_neg = true;

	if (b[0] == '-')
		b_neg = true;

	if ( a_neg != b_neg)//if a and b don't have the same sign
		return a_neg == false;

	// if a and b are both negative, SWAP and remove -'s
	if (a_neg == true)
	{
		string temp = a;
		a = b;
		b = temp;

		a.erase(0, 1);
		b.erase(0, 1);
	}

	if 		(a.length() > b.length())
		return true;
	else if (a.length() < b.length())
		return false;

	// lengths = , so compare each digit, starting at most significant
	int a_digit;
	int b_digit;

	for(int i = a.length() ; i > 0 ; i--)
	{
		a_digit = a[i - 1] - '0';
		b_digit = b[i - 1] - '0';

		if 		(a_digit > b_digit)
			return true;
		else if (a_digit < b_digit)
			return false;
	}
	return false; //should never get here
}



// -005 -> -5 , -0 -> 0
string trim_leading_0s(string int_str)
{
	bool neg = false;

	if(int_str[0] == '-')
	{
		neg = true;
		int_str.erase(0, 1);
	}

	for (int i = 0 ; i < int_str.length() ; i++)
	{
		if (int_str[i] != '0')
		{
			string trimmed_int_str = int_str.substr(i);

			if (neg)
				return '-' + trimmed_int_str;
			else
				return trimmed_int_str;
		}
	}
	return "0";
}



int main()
{
	string s0 = "-00000000000000000000000000000000";
	string s1 = "-00010";
	string s2 = "0090";
	string s3 = "100";
	string s4 = "-5000";

	cout << ":" << trim_leading_0s(s0) << ":"<< endl;
	cout << ":" << trim_leading_0s(s1) << ":"<< endl;
	cout << ":" << trim_leading_0s(s2) << ":"<< endl;
	cout << endl;


	cout << a_greater_than_b(s0 , s2) << endl;
	cout << a_greater_than_b(s2 , s3) << endl;
	cout << a_greater_than_b(s4 , s1) << endl;
	cout << a_greater_than_b(s4 , s3) << endl;

	cout << a_greater_than_b(s0 , s0) << endl;
	cout << a_greater_than_b(s2 , s0) << endl;
	cout << a_greater_than_b(s3 , s2) << endl;
	cout << a_greater_than_b(s1 , s4) << endl;
	cout << a_greater_than_b(s3 , s4) << endl;
}



