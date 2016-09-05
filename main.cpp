//Andrew Godfrey
//Money Value to English Expression
//Last Updated: 9/4/2016
//Known Bug:
#include <iostream>
#include <string>
using namespace std;

char getInput(int &dollars, int &cents);//gets and checks input
void inputStatus(char exitCode);//displays a message commenting on whether or not input was valid
void extractValues(int dollars, int cents, int &thousands, int &hundreds, int &tens, int &ones, int &tenths, int &hundreths);//splits the input into each digit
void displayEnglishToH(int ToH, string type);//displays, in english, the hundreds or thousands place
void displayEnglishTens(int hundreds, int tens, int ones);//displays, in english, the tens place
void displayEnglishOnes(int tens, int ones);//displays, in english, the ones place

int main()
{
	int  dollars, cents, thousands, hundreds, tens, ones, tenths, hundreths;
	char exitCode, choice;

	do// Main Loop. Runs the MoneyToEnglish functions until user wishes to stop
	{
		do//gets input until the input satisfies all conditions
		{
			cout << "----------------Welcome to MakeMoney----------------\n"
				<< "Please enter an amount between 9999.99 and 0.00\n"
				<< "Enter an amount to convert: $";
			exitCode = getInput(dollars, cents);//gets input and returns a code connected to an error or successful run
			inputStatus(exitCode);              // Outputs whether the input was valid or not
		} while (exitCode != 'g');

		extractValues(dollars, cents, thousands, hundreds, tens, ones, tenths, hundreths);//extracts each digit from initial input

		displayEnglishToH(thousands, "thousand");//displays the thousands
		displayEnglishToH(hundreds, "hundred");  //displays the hundreds
		displayEnglishTens(hundreds, tens, ones);          //displays the tens
		displayEnglishOnes(tens, ones);          //displays the ones

		cout << "Would you like to try another?\n"
			<< "   Enter y/n\n";
		cin >> choice;//user can choose to enter another number or not
	} while (choice != 'n' || choice != 'N');

	return 0;//clean exit
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

void extractValues(int dollars, int cents, int &thousands, int &hundreds, int &tens, int &ones, int &tenths, int &hundreths)
{
	thousands = dollars / 1000;//returns the largest int that goes into dollars 1000 times + stores it into thousands
	dollars   = dollars % 1000;//changes the value to the remainder after the thousands operation
	hundreds  = dollars / 100;
	dollars   = dollars % 100;
	tens      = dollars / 10;
	dollars   = dollars % 10;
	ones      = dollars;
	
	tenths    = cents / 10;
	cents     = cents % 10;
	hundreths = cents;
}

void displayEnglishToH(int ToH, string type)
{
	if (ToH > 0 && ToH < 10)//outputs nothing is the value is 0
	{
		switch (ToH)//gets the proper value of the hundreds or thousands place (in english) 
		{
			case (1) :
				cout << "One ";
				break;
			case (2) :
				cout << "Two ";
				break;
			case (3) :
				cout << "Three ";
				break;
			case (4) :
				cout << "Four ";
				break;
			case (5) :
				cout << "Five ";
				break;
			case (6) :
				cout << "Six ";
				break;
			case (7) :
				cout << "Seven ";
				break;
			case (8) :
				cout << "Eight ";
				break;
			case (9) :
				cout << "Nine ";
				break;
			default:
				cout << "Error: Inproper " << type << " digit\n";
				break;
		}
		cout << type << ' ';//adds 'thousand' or 'hundred' and a space so the next value lines up properly on the line
	}
}
void displayEnglishTens(int hundreds, int tens, int ones)
{
	if ( hundreds > 0)
		cout << "and ";
	if (tens > 1 && tens < 10)
	{
		switch (tens)//handles tens digit
		{
			case (2) :
				cout << "Twenty ";
				break;
			case (3) :
				cout << "Thirty ";
				break;
			case (4) :
				cout << "Forty ";
				break;
			case (5) :
				cout << "Fifty ";
				break;
			case (6) :
				cout << "Sixty ";
				break;
			case (7) :
				cout << "Seventy ";
				break;
			case (8) :
				cout << "Eighty ";
				break;
			case (9) :
				cout << "Ninety ";
				break;
			default:
				cout << "Error: Invalid Tens Digit\n";
				break;
		}
	}
	else if (tens == 1)
	{
		switch (ones)//case of last two digits being teens
		{
			case (0) :
				cout << " Ten ";
				break;
			case (1) :
				cout << " Eleven ";
				break;
			case (2) :
				cout << " Twelve ";
				break;
			case (3) :
				cout << " Thirteen ";
				break;
			case (4) :
				cout << " Fourteen ";
				break;
			case (5) :
				cout << " Fifteen ";
				break;
			case (6) :
				cout << " Sixteen ";
				break;
			case (7) :
				cout << " Seventeen ";
				break;
			case (8) :
				cout << " Eighteen ";
				break;
			case (9) :
				cout << " Nineteen ";
				break;
			default:
				cout << "Error: Invalid Tens Digit\n";
				break;
		}
		cout << "Dollars " << endl;
	}
}

void displayEnglishOnes(int tens, int ones)
{
	if ((tens == 0 || tens > 1) && tens < 10)
	{
		switch (ones)//displays the ones digit
		{
			case (0) :
				cout << "Zero ";
				break;
			case (1) :
				cout << "One ";
				break;
			case (2) :
				cout << "Two ";
				break;
			case (3) :
				cout << "Three ";
				break;
			case (4) :
				cout << "Four ";
				break;
			case (5) :
				cout << "Five ";
				break;
			case (6) :
				cout << "Six ";
				break;
			case (7) :
				cout << "Seven ";
				break;
			case (8) :
				cout << "Eight ";
				break;
			case (9) :
				cout << "Nine ";
				break;
			default:
				break;
		}
		cout << "Dollars " << endl;
	}
}
