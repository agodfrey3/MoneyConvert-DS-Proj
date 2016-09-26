DollarAmount::DollarAmount()
{
	dollar = -2;
	cents = -2;
	expense = "NONE";
}
DollarAmount::DollarAmount(int dol, int cen)
{
	cents = cen % 100;
	int extra = cen / 100;
	dollar = dol + extra;
}
DollarAmount::DollarAmount(int dol, int cen, string exp)
{	
	cents = cen % 100;
	int extra = cen / 100;
	dollar = dol + extra;
	expense = exp;
}
int DollarAmount::getDollar()
{
	return dollar;
}
int DollarAmount::getCents()
{
	return cents;
}
string DollarAmount::getExpense()
{
	return expense;
}
string DollarAmount::getPhrase()
{
	return englishPhrase;
}
void DollarAmount::setDollar(int dol)
{
	dollar = dol;
}
void DollarAmount::setCents(int cen)
{
	cents = cen;
}
void DollarAmount::setExpense(string exp)
{
	expense = exp;
}
void DollarAmount::setCenStr(string s)
{
	centsStr = s;
}
DollarAmount DollarAmount::operator+(const DollarAmount &d2)
{
	DollarAmount temp;
	int newCents = (cents + d2.cents) % 100;
	temp.cents = newCents;
	int extra = ( cents + d2.cents ) / 100;
	temp.dollar = ( dollar + d2.dollar + extra );
	
	ostringstream convert;
	convert << newCents;

	string testString = convert.str();
	if ( testString.size() == 1 ) // Makes .1 -> .01 to show that it is one cent and not ten
	{
		testString = "0" + testString;
	}
	
	temp.centsStr = testString;

	return temp;
}
bool DollarAmount::operator>(const DollarAmount& d2)
{
	if ( dollar > d2.dollar )
		return true;
	else if ( dollar < d2.dollar )
		return false;
	else if ( dollar == d2.dollar )
	{
		if ( cents > d2.cents )
			return true;
		else
			return false;
	}
}
bool DollarAmount::fail()
{
	if (dollar > 9999)
		return true;
	else
		return false;
}
void DollarAmount::extractValues()
{
	int tempDol = dollar;
	int tempCen = cents;
	dollarArray[0] = dollar / 1000;//returns the largest int that goe    s into dollars 1000 times + stores it into thousands
        dollar = dollar % 1000;//changes the value to the remainder afte    r the thousands operation
        dollarArray[1] = dollar / 100;
        dollar = dollar % 100;
        dollarArray[2] = dollar / 10;
        dollar = dollar % 10;
        dollarArray[3] = dollar;
 
        centArray[0] = cents / 10;
        cents = cents % 10;
        centArray[1]= cents;
	
	dollar = tempDol;
	cents = tempCen;
}
void DollarAmount::setEnglishDollarAmount()
{
	// Lookup tables for dollar/cent values // I know you said to make these static, but I'm unsure as to why it is beneficial, as they are only neede    d within this function, which is only called once
        static string thousandsTable[10] = { "", "One Thousand ","Two Thousand ","Three Thousand ","Four Thousand ","Five Thousand ","Six Thousand ","Seve    n Thousand ","Eight Thousand ","Nine Thousand " };
        static string hundredsTable[10] = { "", "One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ", "Six Hundred ", "Seven     Hundred ", "Eight Hundred ", "Nine Hundred " };
        static string tensTable[10] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };
        static string onesWithOneTenTable[10] = { "Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Ninet    een " };
        static string onesTable[10] = { "", "One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine " };
 
	string output; // Temp var that will be moved to englishPhrase

        if (dollar > 0)
        {
		output = thousandsTable[dollarArray[0]] + hundredsTable[dollarArray[1]]; // Adds thousands and hundreds phrases to the return string
       		if (dollarArray[2] == 1)
       			output = output + onesWithOneTenTable[dollarArray[3]] + "dollars"; // Adds phrase correlating numbers with a one in the tens plac
                else
                	output = output + tensTable[dollarArray[2]] + onesTable[dollarArray[3]] + "dollars"; // Adds phrase correlating to numbers with a     digit other than one in the tens place
        }
        if (cents > 0) // checks to make sure that cents is > 0, else there is no need to state anything
        {
        	output = output + " and ";
        	if (centArray[0] == 1)
       			output = output + onesWithOneTenTable[centArray[1]];// adds phrase correlating to cents with a tenth digit of 1
       		else
       			output = output + tensTable[centArray[0]] + onesTable[centArray[1]];// adds phrase correlating to cents with a tenth digit != 1
       			output = output + "cents";
        }
 
	if (dollar == 0 && cents == 0)
        	output = "Silly person, you have no money";

	englishPhrase = output;
}
