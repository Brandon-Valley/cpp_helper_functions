#ifndef TEST_CASE_H
#define TEST_CASE_H

#include <iostream>
#include <string>
#include <typeinfo>
#include<bits/stdc++.h>

using std::string;
using namespace std;


struct test_var
{
    string lable;             	//need
    string data;				//need
    int max_data_chars;
    string alignment_type;
    string lable_data_seperation_spacing;
    string lable_data_seperation_str;
};


class Test_Case
{
private:
	std::vector< test_var > m_test_vars;

public:
	Test_Case() {};


	void add_test_var(  string lable,            			 //need
						string data,						 //need
						int max_data_chars 					 = 5,
						string alignment_type 				 = "right",
						string lable_data_seperation_spacing = " ",
						string lable_data_seperation_str 	 = ":");


	void display( 	string 	pre_spaces 	= "  ",  		//what gets printed before anything else, the distance of the text from the left side of the screen
					string 	between_str	= "  ",  		//gets printed in between every test case
					string 	post_str 	= "",    		//gets printed after everything else
					string 	print_type 	= "one line");
};



string make_aligned_str(string data, int max_data_chars, string alignment_type);















#endif
