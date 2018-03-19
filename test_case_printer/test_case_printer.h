#ifndef test_var_PRINTER_H
#define test_var_PRINTER_H

#include <iostream>
#include <string>
#include <typeinfo>

using std::string;
using namespace std;


struct test_var
{
    string lable;             	//need
    string data;				//need
    int max_data_chars = 5;
    string alignment_type = "right";
    string lable_data_seperation_spacing = " ";
    string lable_data_seperation_str = ":";
};

//void display_test_vars(test_var 	test_vars[],
//						int 		num_test_vars,
//						string 		pre_spaces 	= "  ",  		//what gets printed before anything else, the distance of the text from the left side of the screen
//						string 		between_str	= "  ",  		//gets printed in between every test case
//						string 		post_str 	= "",    		//gets printed after everything else
//						string 		print_type 	= "one line");

string make_aligned_str(string data, int max_data_chars, string alignment_type);


class Test_Case
{
private:
	int m_num_test_vars; //default num_test_vars
	test_var *m_test_vars;
	void grow_test_vars();

public:
	Test_Case();
//	Test_Case(int num_test_vars) { m_num_test_vars = num_test_vars; }
	~Test_Case();// { delete [] m_test_vars; }

//	Test_Case(int num_test_vars) {m_num_test_vars = num_test_vars;}

	void add_test_var(  string lable,            	//need
						string data,				//need
						int max_data_chars = 5,
						string alignment_type = "right",
						string lable_data_seperation_spacing = " ",
						string lable_data_seperation_str = ":");


	void display_test_vars( string 	pre_spaces 	= "  ",  		//what gets printed before anything else, the distance of the text from the left side of the screen
							string 	between_str	= "  ",  		//gets printed in between every test case
							string 	post_str 	= "",    		//gets printed after everything else
							string 	print_type 	= "one line");

	void test() { cout << ": " << m_num_test_vars << endl; }//remove!!!!!!!!!!!!!!!!!!!!!!!!!!

};


//struct test_var
//{
//    string lable;             	//need
//    string data;				//need
//    int max_data_chars = 5;
//    string alignment_type = "right";
//    string lable_data_seperation_spacing = " ";
//    string lable_data_seperation_str = ":";
//};

//template <typename T>
//MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
//{
//	if (this != &source)
//	{
//		reserved_size = source.reserved_size;
//		data_size = source.data_size;
//
//		delete[] m_data;
//		m_data = new T [source.reserved_size];
//
//		for(int i = 0 ; i < source.data_size ; i++)
//			m_data[i] = source.m_data[i];
//	}
//	return *this;
//}




















#endif
