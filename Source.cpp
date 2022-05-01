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

char character(char start, int offset)
{
	// If start is NOT between 'a' and 'z' or 'A' and 'Z'
	if (!((start >= 'a' && start <= 'z') || (start >= 'A' && start <= 'Z')))
	{
		throw invalidCharacterException(start);
	}

	char newChar = start + offset;

	// If newChar is NOT between 'a' and 'z' or 'A' and 'Z'
	// OR if offset is greater than or equal to 32 (to prevent looping from 'A' to 'a')
	if (!((newChar >= 'a' && newChar <= 'z') || (newChar >= 'A' && newChar <= 'Z')) || offset >= 32)
	{
		throw invalidRangeException(offset);
	}

	return newChar;
}