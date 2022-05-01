// Dane Merriman
// CIS 1202 501
// May 1, 2022
// Fifteenth Assignment - Exception Handling

#include <iostream>
using namespace std;

// Exception classes
class invalidCharacterException
{
	private:
		char c = NULL;
	public:
		invalidCharacterException(char c)
		{
			this->c = c;
		}

		char getChar()
		{
			return c;
		}
};

class invalidRangeException
{
	private:
		int i = NULL;
	public:
		invalidRangeException(int i)
		{
			this->i = i;
		}

		int getOffset()
		{
			return i;
		}
};