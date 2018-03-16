
#include "test_case_printer.h"


int main()
{
	char c1 = 'g';
	string s;
	s += c1;

	test_case tc1 = {"data1" , to_string(32)};
	test_case tc2 = {"data2", "test"};
	test_case tc3 = {"data3",  s, 10, "left"};

	test_case test_cases[] = { tc1, tc2, tc3 };
	display_test_cases(test_cases, 3);
	display_test_cases(test_cases, 3, "  ", "   ", "", "one case per line" );
}
