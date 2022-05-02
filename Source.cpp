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
		char c;
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
		int i;
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

// Function Prototype
char character(char, int);

int main()
{
	// Array for test values
	char cArr[] = { 'a', 'a', 'Z', '?', 'A' };
	int iArr[] = { 1, -1, -1, 5, 32 };

	for (int i = 0; i < 5; i++)
	{
		try
		{
			cout << "The result of character('" << cArr[i] << "', " << iArr[i] << ") is: ";
			cout << character(cArr[i], iArr[i]) << endl;
		}
		catch (invalidCharacterException e)
		{
			cout << e.getChar() << " is not a valid starting character.\n";
		}
		catch (invalidRangeException e)
		{
			cout << e.getOffset() << " is not a valid offset.\n";
		}
	}

	system("pause");
	return 0;
}

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