//Andrew Godfrey
//Money Value to English Expression
//Last Updated: 9/13/2016
//Known Bug: None. Implemented Array for dollar/cent amount and fixed the issue where 150.1 == 150.01
#include <iostream>
#include <string>
#include <limit>
using namespace std;

char getInput(int &dollars, int &cents);
/*
@param         : gets variables from main to store the user input values correlating to dollar and cent values which will later be converted to english words
@pre-condition : empty variables for dollar/cent. User is ready to enter their desired dollar amount. 
@post-condition: the input is either stored into variables (dollar and cent) and the function has returned a value to signify whether these values were stored or not. 
@return        : char signifying whether the attempt was a success or failure. A return of 'g' means the dollar/cent values are stored and were valid. A return of 'e' means there was an error in the user's input.
*/
void inputStatus(char exitCode);
/*
@param         : Recieves code from 'getInput' that signifies whether the function was successful or not in obtaining values for dollar/cent
@pre-condition : getInput has been run and returned a character that signifies whether the dollar/cent values have been stored or not.
@post-condition: The user is informed as to whether or not their input was valid.
*/
void extractValues(int dollars, int cents, int dollarArray[], int centArray[]);
/*
@param         : dollars and cents are the input from user signifying the dollar and cent amounts they desire to be translated into english. The arrays are arrays that will store a digit correlating to a place value. ex: one thousand will be stored dollarArray[1XXX]  
@pre-condition : The user has successfully entered a dollar amount, and variables are ready to hold each of the digits within the dollar amount entered. 
@post-condition: Each digit from the user input dollar amount has been stored in a variable.
*/
string getEnglishDollarAmount(int dollarArray[], int centArray[], int cents, int dollars);
/*
@param         : Two arrays containing digits correlating to place values of the user input dollar/cent amounts. Dollar and cent hold the user's input for their dollar amount
@pre-condition : The digits have been extracted from the user's dollar and cent input
@post-condition: The proper english names have been concatenated into a string that displays the english phrase for the user's entered dollar amount
@return        : A string correlating to the english phrase of the user's dollar/cent input
*/


int main()
{
	int  dollars, cents, dollarArray[4], centArray[2];// Variables to store each digit in the dollar amount as well as the dollar and cent amounts themselves
	char exitCode, choice;// Exit code correlates to the success or failure of an input operation; choice is y/n
	
	do// Main Loop. Runs the MoneyToEnglish functions until user wishes to stop
	{
		do//gets input until the input satisfies conditions
		{
			exitCode = getInput(dollars, cents);//gets input and returns a code connected to an error or successful run
			inputStatus(exitCode);              // Outputs whether the input was valid or not
		} while (exitCode != 'g');

		extractValues(dollars, cents, dollarArray, centArray);//extracts each digit from initial input

		cout << "Amount is: "
			<< getEnglishDollarAmount(dollarArray, centArray, cents, dollars);// Displays the user entered dollar amount in english
		cout << "Would you like to try another?\n"
			<< "   Enter y/n\n";
		cin >> choice;//user can choose to enter another number or not
	} while (choice != 'n' && choice != 'N');

	cout << "Thank you for using MoneyConvert\n";

	return 0;//clean exit
}

char getInput(int &dollars, int &cents)
{
	cout << "----------------Welcome to MakeMoney----------------\n"
		<< "Please enter an amount between 9999.99 and 0.00\n"
		<< "Enter an amount to convert: $";
	int dol, cenVal;// temp vars to hold dollar and cent input for processing 
	string cen;
	char ch;// variable to hold the separator, '.'
	char code = 'g'; // Sets return val to good by default
	while (true)
	{
		cin >> dol;//get input for dollars
		if (cin.fail() || dol > 9999)// Checks to make sure that the input is valid 
		{
			code = 'e';// sets an error flag
			cin.clear();// clears the cin failure flag
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// clears the buffer to next line
			break;// ends loop
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
		if (cin.fail())//gets input for cents and checks validity 
		{
			code = 'e';
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}

		cenVal = ((cen[0] - '0') * 10) + (cen[1] - '0'); // Logic to convert the cent string to cent int 
		if (cenVal < 0 || cenVal > 99)// checks to make sure the cent is within the proper range[ 0-99 ]
		{
			code = 'e';
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		break;
	}

		

	if (code == 'g')// Sets the dollar/cent vars to the values of the temp vars since input was valid
	{
		dollars = dol;
		cents = cenVal;
	}

	return code;// returns 'g' for good or 'e' for error
}

void inputStatus(char exitCode)
{
	switch (exitCode)
	{
	case ('e')://code for error
		cout << "Your input was invalid, please try again.\n\n";
		break;
	case ('g')://code for good input
		cout << "Thank you. Your input was valid.\n"
			<< "\tProcessing...\n\n";
		break;
	default://code if the getInput function malfunctioned
		cout << "Bug in code. Check over logic\n";
		break;
	}
}

void extractValues(int dollars, int cents, int dollarArray[], int centArray[])
{
	dollarArray[0] = dollars / 1000;//returns the largest int that goes into dollars 1000 times + stores it into thousands
	dollars = dollars % 1000;//changes the value to the remainder after the thousands operation
	dollarArray[1] = dollars / 100;
	dollars = dollars % 100;
	dollarArray[2] = dollars / 10;
	dollars = dollars % 10;
	dollarArray[3] = dollars;

	centArray[0] = cents / 10;
	cents = cents % 10;
	centArray[1]= cents;
}

string getEnglishDollarAmount(int dollarArray[], int centArray[], int cents, int dollars)
{
	// Lookup tables for dollar/cent values
	string thousandsTable[10] = { "", "One Thousand ","Two Thousand ","Three Thousand ","Four Thousand ","Five Thousand ","Six Thousand ","Seven Thousand ","Eight Thousand ","Nine Thousand " };
	string hundredsTable[10] = { "", "One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ", "Six Hundred ", "Seven Hundred ", "Eight Hundred ", "Nine Hundred " };
	string tensTable[10] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };
	string onesWithOneTenTable[10] = { "Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen " };
	string onesTable[10] = { "", "One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine " };
	string output;
	
	if (dollars > 0)
	{
		output = thousandsTable[dollarArray[0]] + hundredsTable[dollarArray[1]]; // Adds thousands and hundreds phrases to the return string
		if (dollarArray[2] == 1)
			output = output + onesWithOneTenTable[dollarArray[3]] + "dollars"; // Adds phrase correlating numbers with a one in the tens place
		else
			output = output + tensTable[dollarArray[2]] + onesTable[dollarArray[3]] + "dollars"; // Adds phrase correlating to numbers with a digit other than one in the tens place

	}
	if (cents > 0) // checks to make sure that cents is > 0, else there is no need to state anything
	{
		output = output + " and ";
		if (centArray[0] == 1)
			output = output + onesWithOneTenTable[centArray[1]];// adds phrase correlating to cents with a tenth digit of 1
		else
			output = output + tensTable[centArray[0]] + onesTable[centArray[1]];// adds phrase correlating to cents with a tenth digit != 1
		output = output + "cents.";
	}

	output = output + '\n';

	if (dollars == 0 && cents == 0)
		output = "Silly person, you have no money.\n";

	return output; // returns english phrase for the desired user's dollar/cent amounts
	
}
