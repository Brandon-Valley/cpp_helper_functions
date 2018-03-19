
#include "test_case_printer.h"

Test_Case::Test_Case()
{
	m_num_test_vars = 0;
//	m_test_vars = new test_var[ m_num_test_vars ];
}

Test_Case::~Test_Case() { delete [] m_test_vars; }

//increases size of m_test_vars so a new test_var can be added
void Test_Case::grow_test_vars()
{
	test_var *new_test_vars = new test_var[ m_num_test_vars + 1 ];

	for (int i = 0 ; i < m_num_test_vars ; i++)
		new_test_vars[i] = m_test_vars[i];

	delete [] m_test_vars;
	m_test_vars = new_test_vars;
	m_num_test_vars ++ ;
}

void Test_Case::add_test_var(	string lable,            	//need
								string data,				//need
								int max_data_chars,
								string alignment_type,
								string lable_data_seperation_spacing,
								string lable_data_seperation_str)
{




	test_var tv;




}


void Test_Case::display_test_vars(string pre_spaces, string between_str, string post_str, string print_type)
{
	cout << "display" << endl;
////	//for debugging ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
////	cout << "num_test_vars: " << num_test_vars << endl;
////	cout << "pre_spaces: " << pre_spaces << endl;
////	cout << "between_str: " << between_str << endl;
////	cout << "post_str: " << post_str << endl;
////	cout << "print_type: " << print_type << endl;
//
//	//make tc_strings
//	string tc_strings[num_test_vars];
//
//	for (int i = 0 ; i < num_test_vars ; i++)
//	{
//		test_var tc = test_vars[i];
//
//		string tc_str = tc.lable + tc.lable_data_seperation_str + tc.lable_data_seperation_spacing;
//		tc_str.append( make_aligned_str(tc.data, tc.max_data_chars, tc.alignment_type));
//		tc_strings[i] = tc_str;
////		cout << "tc_strings[" << i << "]: " << tc_strings[i] << endl;//for debugging~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	}
//
//	//display
//	if (print_type == "one line")
//		cout << pre_spaces;
//
//	for (int i = 0 ; i < num_test_vars ; i++)
//	{
//		if 		(print_type == "one line")
//			cout << tc_strings[i] + between_str;
//		else if (print_type == "one case per line")
//			cout << pre_spaces + tc_strings[i] << endl;
//		else
//			cout << "YOU MISSPELLED PRINT_TYPE" << endl;
//	}
//
//	cout << post_str << endl;
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

////need this because g++ sucks and cant do
//test_var make_test_var()






//int main()
//{
//	char c1 = 'g';
//	string s;
//	s += c1;
//
//	test_var tc1 = {"data1" , to_string(32)};
//	test_var tc2 = {"data2", "test"};
//	test_var tc3 = {"data3",  s, 10, "left"};
//
//	test_var test_vars[] = { tc1, tc2, tc3 };
//	display_test_vars(test_vars, 3);
//	display_test_vars(test_vars, 3, "  ", "   ", "", "one case per line" );
//
//}
