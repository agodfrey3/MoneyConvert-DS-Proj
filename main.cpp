//Andrew Godfrey
//Money Value to English Expression with Expenditure Implementation
//Last Updated: 9/25/2016
//Known Bug: None. 
#include <iostream> // istream ostream
#include <string> // string 
#include <limits> // max
#include <sstream> // stringstream
#include <math.h> // ceil()

using namespace std;

#include "DollarAmount.h"
#include "DollarAmount.cpp"

// Each function below commented in DollarAmount.h as they are all friend functons
ostream& operator<<(ostream& output, DollarAmount& o);
istream& operator>>(istream& input, DollarAmount& o);
void swap(DollarAmount& d1, DollarAmount& d2);
void displayList(DollarAmount * list, int len);
template<class DollarAmount>void bubbleSort(DollarAmount * list, size_t len);
/*
 *@param: DollarAmount pointer to array of DollarAmount objects and the size of the array
 *@pre-conditoin: The array has been created and filled
 *@post-condition: The array has been sorted from least to greatest
*/
 
int main()
{
	const int MAX_SIZE = 10; // max size of the input array
	DollarAmount * DollarArray = new DollarAmount[MAX_SIZE]; // Dynamic array of DollarAmounts to hold each input
	string expense;
	bool isDone = false;
	int arrayLen = 0;
	int middleIndex; 
	
	do//gets input until the input satisfies conditions
	{
		cin >> DollarArray[arrayLen]; // Inputs the data to DollarAmount Object
		if ( DollarArray[arrayLen].getDollar() == -1 ) // Checks to see if user wishes to exit
			isDone = true;
		else
			arrayLen++; // Increments array size
	} while (isDone == false && arrayLen < 10 ); // Ends when list is full or use wishes to exit '-1'

	DollarAmount total = getTotal(DollarArray, arrayLen);// Creates an object to hold the total amount in
	total.extractValues();
	total.setEnglishDollarAmount();
	
	bubbleSort(DollarArray, arrayLen); // Sorts list from least to greatest
	displayList(DollarArray, arrayLen); // Displays the lsit of Dollar Amounts

	
	if ( !total.fail() )
		cout << endl << "Total: $" << total << "( " << total.getPhrase() << " )" << endl; // Outputs the total amount 
	else
		cout << endl << "Sorry, your total input was too large! ( > 999.99 ) \n";
	
	middleIndex = ceil(arrayLen / 2);// Finds middle index. If list is Even, it will round the index up
	cout << "Median: $" << DollarArray[middleIndex] << endl;

	delete [] DollarArray; //Releases the array's memory  
}

template<class DollarAmount>void bubbleSort(DollarAmount * list, size_t len)
{
	if ( len > 1 ) // Doesnt need to sort if length is 1
        {
                for ( int i = 0; i < len - 1; i++)
                {
                        for ( int j = i + 1; j < len; j++)
                        {
                                if ( list[i] > list[j] )
                                {
                                        swap(list[i], list[j]); // Swaps values
                                }
                        }
                }
        }
}

void displayList(DollarAmount * list, int len)
{
	for (int i = 0; i < len; i++)
	{
		if ( i == 9 )
			cout << (i+1) << ") " << list[i] << endl; // e.g  "10) 143.54 Apples " 
		else
			cout << ' ' << (i+1) << ") " << list[i] << endl;//"01) 143.54 Apples "
	}
}

DollarAmount getTotal(DollarAmount * list, int len)
{
	DollarAmount total(0,0);
	for (int i = 0; i < len; i++)
	{
		if ( list[i].dollar != -1 && list[i].dollar != -2 )
		{
			total = total + list[i]; 
		}
	}
	return total;
}

void swap(DollarAmount& d1, DollarAmount& d2)
{
	int tempCen, tempDol;
	int *tempCenArray = new int[2];
	int *tempDolArray = new int[4];
	string tempExpense, tempEngPhrase, tempCenStr;
	
	tempCen = d1.cents; // Stores d1 data so data is not lost
	tempDol = d1.dollar;
	tempExpense = d1.expense;
	tempEngPhrase = d1.englishPhrase;
	tempCenStr = d1.centsStr;
	*tempCenArray = *d1.centArray;
	*tempDolArray = *d1.dollarArray;
	
	d1.cents = d2.cents;// sets d1 to d2 
	d1.dollar = d2.dollar;
	d1.expense = d2.expense;
	d1.englishPhrase = d2.englishPhrase;
	d1.centsStr = d2.centsStr;
	d1.centArray[0] = d2.centArray[0];
	d1.centArray[1] = d2.centArray[1];
	d1.dollarArray[0] = d2.dollarArray[0];
	d1.dollarArray[1] = d2.dollarArray[1];
	d1.dollarArray[2] = d2.dollarArray[2];	
	d1.dollarArray[3] = d2.dollarArray[3];

	d2.cents = tempCen; // sets d2 to d1 ( temp ) 
	d2.dollar = tempDol;
	d2.expense = tempExpense;
	d2.englishPhrase = tempEngPhrase;
	d2.centsStr = tempCenStr;
	d2.centArray[0] = tempCenArray[0];
	d2.centArray[1] = tempCenArray[1];
	d2.dollarArray[0] = tempDolArray[0];
	d2.dollarArray[1] = tempDolArray[1];
	d2.dollarArray[2] = tempDolArray[2];
	d2.dollarArray[3] = tempDolArray[3];
	
	delete [] tempCenArray; // releases memory 
	delete [] tempDolArray;
	
}
ostream& operator<<(ostream& output, DollarAmount &o)
{
	if (o.dollar != -2 && o.cents != -2 && o.dollar != -1) // Makes sure the object has valid data before outputting
	{
		output << o.dollar << '.' << o.centsStr << ' '; 
		if (o.expense != "NONE")
			output << o.expense;
	}
	else
		output << "Empty";

	return output;
}
istream& operator>>(istream &input, DollarAmount &o)
{
        char code = 'x';
        do
	{
                cout << "Enter Expenditure(e.g. 35.45 Mirror) OR enter -1 to quit. [Note: Your total expenses cannot exceed $9999.99 and you may only enter 10 expenses] : $";
                int dol, cenVal;// temp vars to hold dollar and cent input for processing
                string cen, exp;
                code = 'g';
                char ch;// variable to hold the separator, '.'
                while (true)
                {
                        input >> o.dollar;//get input for dollars
                        if (input.fail() || o.dollar > 9999)// Checks to make sure that the input is valid
                        {
                                code = 'e';// sets an error flag
                                input.clear();// clears the cin failure flag
                                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// clears the buffer to nex    t line
                                break;// ends loop
                        }
                        if ( o.dollar == -1 )
                        {
                                code = 'q';
                                break;
                        }
                        input >> ch;
                        if (input.fail() || ch != '.')//gets input for separater and checks validity
                        {
                                code = 'e';
                                input.clear();
                                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                break;
                        }
			input >> o.centsStr;		
                        if (input.fail() || o.centsStr.size() > 2)//gets input for cents and checksvalidity
                        {
                                code = 'e';
                                input.clear();
                                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                break;
                        }
                        cenVal = ((o.centsStr[0] - '0') * 10) + (o.centsStr[1] - '0'); // Logic to convert the cent string to cent int
                        if (cenVal < 0 || cenVal > 99)// checks to make sure the cent is within the proper range[ 0-99 ]
                        {
                            code = 'e';
                                input.clear();
                                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                break;
                        }
			o.cents = cenVal;
                        getline(cin, o.expense);
                        if ( input.fail() )
                        {
                                code = 'e';
                                input.clear();
                                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                break;
                        }
                	break;
                }
                if (code == 'g')// Sets the dollar/cent vars to the values of the temp vars since input was valid
                {
                        o.extractValues();
                        o.setEnglishDollarAmount();
                        return input;
		}
                else if ( code == 'e' )
		{
                        cout << "Invalid Input, please retry\n";
		}
                else if ( code == 'q' )
                {
                        cout << "Processing Entered Data...\n\n";
                        code = 'g';
                }
                else
                        cout << "Error in code; continuing as if bad input    \n";
	}while (code != 'g');
	
}


