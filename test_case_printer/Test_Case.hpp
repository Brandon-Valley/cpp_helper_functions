
#include "test_case_printer.h"

Test_Case::Test_Case()
{
//	m_num_test_vars;

//	m_test_vars = new test_var[ m_num_test_vars ];
}

//Test_Case::~Test_Case() { delete [] m_test_vars; }

////increases size of m_test_vars so a new test_var can be added
//void Test_Case::grow_test_vars()
//{
//	test_var *new_test_vars = new test_var[ m_num_test_vars + 1 ];
//
//	for (int i = 0 ; i < m_num_test_vars ; i++)
//		new_test_vars[i] = m_test_vars[i];
//
//	delete [] m_test_vars;
//	m_test_vars = new_test_vars;
//	m_num_test_vars ++ ;
//}

void Test_Case::add_test_var(	string lable,            	//need
								string data,				//need
								int max_data_chars,
								string alignment_type,
								string lable_data_seperation_spacing,
								string lable_data_seperation_str)
{
	test_var tv;
	tv.lable 							= lable;
	tv.data 							= data;
	tv.max_data_chars					= max_data_chars;
	tv.alignment_type 					= alignment_type;
	tv.lable_data_seperation_spacing 	= lable_data_seperation_spacing;
	tv.lable_data_seperation_str 		=  lable_data_seperation_str;

	m_test_vars.push_back(tv);
}


void Test_Case::display(string pre_spaces, string between_str, string post_str, string print_type)
{
//	//for debugging ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	cout << "num_test_vars: " << num_test_vars << endl;
//	cout << "pre_spaces: " << pre_spaces << endl;
//	cout << "between_str: " << between_str << endl;
//	cout << "post_str: " << post_str << endl;
//	cout << "print_type: " << print_type << endl;

	//make tv_strings
	string tv_strings[m_test_vars.size()];

	for (int i = 0 ; i < m_test_vars.size() ; i++)
	{
		test_var tc = m_test_vars[i];

		string tc_str = tc.lable + tc.lable_data_seperation_str + tc.lable_data_seperation_spacing;
		tc_str.append( make_aligned_str(tc.data, tc.max_data_chars, tc.alignment_type));
		tv_strings[i] = tc_str;
//		cout << "tv_strings[" << i << "]: " << tv_strings[i] << endl;//for debugging~~~~~~
	}

	//display
	if (print_type == "one line")
		cout << pre_spaces;

	for (int i = 0 ; i < m_test_vars.size() ; i++)
	{
		if 		(print_type == "one line")
			cout << tv_strings[i] + between_str;
		else if (print_type == "one case per line")
			cout << pre_spaces + tv_strings[i] << endl;
		else
			cout << "YOU MISSPELLED PRINT_TYPE" << endl;
	}

	cout << post_str << endl;
}

string make_aligned_str(string data, int max_data_chars, string alignment_type)
{
	if (max_data_chars < data.length())
		return "YOUR DATA IS LONGER THAN YOUR MAX_DATA_CHARS, NEED TO INCRESE TO AT LEAST: " + to_string( data.length() );

	string result = data;

	while(result.length() < max_data_chars)
	{
		if 		(alignment_type == "left")
			result += " ";
		else if (alignment_type == "right")
			result.insert(0," ");
		else
			result = "YOU MISSPELLED THE ALIGNMENT TYPE";
	}
	return result;
}


//int main()
//{
//	char c1 = 'g';
//	string s;
//	s += c1;
//
//	Test_Case tc;
//
//	tc.add_test_var( "data1" , to_string(32) );
//	tc.add_test_var( "data2", "test" );
//	tc.add_test_var( "data3",  s, 10, "left" );
//
//	tc.display();
//  cout << endl;
//	tc.display("  ", "   ", "", "one case per line" );
//}
