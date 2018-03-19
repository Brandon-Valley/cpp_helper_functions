
#include "Test_Case.h"


int main()
{
	char c1 = 'g';
	string s;
	s += c1;

	Test_Case tc;

	tc.add_test_var( "data1" , to_string(32) );
	tc.add_test_var( "data2", "test" );
	tc.add_test_var( "data3",  s, 10, "left" );

	tc.display();
	cout << endl;
	tc.display("  ", "   ", "", "one case per line" );
}
