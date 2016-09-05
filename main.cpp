//Andrew Godfrey
//Money Value to English Expression
//Last Updated: 9/4/2016
//Known Bug:
#include <iostream>
#include <string>
using namespace std;

char getInput(int &dollars, int &cents);
void inputStatus(char exitCode);
void displayValues(int dollars, int cents);

int main()
{
	int  dollars, cents;
	char exitCode;

	do//gets input until the input satisfies conditions
	{
		cout << "----------------Welcome to MakeMoney----------------\n"
			<< "Please enter an amount between 9999.99 and 0.00\n"
			<< "Enter an amount to convert: $";
		exitCode = getInput(dollars, cents);//gets input and returns a code connected to an error or successful run
		inputStatus(exitCode);// Outputs whether the input was valid or not
	} while (exitCode != 'g');

	displayValues(dollars, cents);

	return 0;
}

char getInput(int &dollars, int &cents)
{
	int dol, cen;
	char ch;
	char code = 'g';
	while (true)
	{
		cin >> dol;
		if (cin.fail() || dol > 9999)//get input for dollars and checks validity
		{
			code = 'e';
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}

		cin >> ch;
		if (cin.fail() || ch != '.')//gets input for separater and checks validity
		{
			code = 'e';
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}

		cin >> cen;
		if (cin.fail() || cen > 99)//gets input for cents and checks validity 
		{
			code = 'e';
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		break;
	}

	if (code == 'g')//uses param variables to change the main functions dollar and cents main variables if the input was good
	{
		dollars = dol;
		cents   = cen;
	}
	return code;
}

void inputStatus(char exitCode)
{
	switch (exitCode)
	{
	case ('e') ://code for error
		cout << "Your input was invalid, please try again.\n\n";
		break;
	case ('g') ://code for good input
		cout << "Thank you. Your input was valid.\n"
		<< "\tProcessing...\n\n";
		break;
	default://code if the getInput function malfunctioned
		cout << "Bug in code. Check over logic\n";
		break;
	}
}

void displatValues(int dollars, int cents)
{

}
