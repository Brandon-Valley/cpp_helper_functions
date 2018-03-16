#ifndef TEST_CASE_PRINTER_H
#define TEST_CASE_PRINTER_H

//#include "test_case_printer.cpp"

#include <iostream>
#include <string>
#include <typeinfo>

using std::string;
using namespace std;


struct test_case
{
    string lable;             	//need
    string data;				//need
    int max_data_chars = 10;
    string alignment_type = "right";
    string lable_data_seperation_spacing = " ";
    string lable_data_seperation_str = ":";
};

string make_aligned_str(string data, int max_data_chars, string alignment_type);

//void display_test_cases(test_case test_cases[], int num_test_cases, string pre_spaces, string between_str, string post_str, string print_type);

void display_test_cases(test_case test_cases[], int num_test_cases, string pre_spaces = "  ",
						string between_str = "   " , string post_str = "", string print_type = "one line");



#endif
