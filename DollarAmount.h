class DollarAmount
{
public:
	DollarAmount(); // Initializes all varaibles to 0 
	DollarAmount( int dol, int cen ); // Initializes price variables
	DollarAmount( int dol, int cen, string expense); // Initializes all varibles to user given values
	int getDollar();
	/*
 	@pre-condition : DollarAmount.dollar has been declared and defined
	@return        : int correlating to dollar amount of class type DollarAmount object
 	*/
	int getCents();
	/*
 	@pre-condition: DollarAmount.cent has been declared and defined
	@return       : int correlating to cent amount of class type DollarAmount object
 	*/
	string getExpense();
	/*
 	@pre-condition: DollarAmount.expense has been declared and defined
	@return       : string correlating to the item expense entered by the user
 	*/
	string getPhrase();
	/*
 * 	pre-condition: A phrase has been created
 * 	post-condition: The Phrase was returned
 * 	return: The phrase was returned
 * 	*/
	void setCents( int cen );
	/*
 	@param         : cent value that you wish to set as DollarAmount.cent
	@pre-condition : value has been obtained that you wish to fill the variable with
	@post-condition: cent has been defined correlating the the users given input
 	*/
	void setDollar( int dol );
	/*
 	@param         : int that the user wishes to use as a dollar amount
	@pre-condition : The user has already been prompted for information
	@post-condition: The value is stored in the cent var 
 	*/
	void setExpense( string exp );
	/*
 	@param         : String correlating to the item of expense
	@pre-condition : User has been prompted for their expense
	@post-condition: The expense string has been stored
 	*/
	bool fail();
	/*
	@pre-conditon  : The user has been prompted to fill their list of expenditures
	@post-condition: A flag is thrown which lets the program know if the input adds up to a valid amount
	@return        : true if value <= 9999.99 and >= 0, or false if not
 	*/
	DollarAmount operator+(const DollarAmount &d2);
	/*
	@pre-condition : The objects to the left and right of '+' have been successfully filled with data
	@post-condition: A new object is created which adds the values within the objects
	@return        : An object of type DollarAmount that contains the added values
 	*/
	bool operator>(const DollarAmount &d2);
	/*
 *	@param: Two objects to compare price
 *	@pre-condition: Both objects are full and ready to be compared	
 *	@post-condition: The object's prices have been compared
 *	@return: True if LHS > RHS or False if LHS < RHS
 * 	*/
	friend void swap(DollarAmount& d1, DollarAmount& d2);
	/*
 *	@param         : Two dollar amounts to swap
 *	@pre-condition : Both objects are filled and need to be swapped
 *	@post-condition: The objects have been swapped
 * 	*/
	friend istream& operator>>(istream &input, DollarAmount& );
	/*
 	@param         : istream - > cin       DollarAmount - > The object you wish to fill with info
	@pre-condition : There is a dollar amount object ready to be used, and the user is ready to input info
	@post-condition: The new object is filled with information by the user
	@return        : The object which was filled with new info from the user
 	*/
	friend ostream& operator<<(ostream& output, DollarAmount &o);
	/*
 	@param         : ostream -> cout        DollarAmount -> the item you wish to output 
 	@pre-condition : Object has data and is ready to be output
	@post-condition: Objects data (price) is output. e.g. "54.67 Waffles" 
 	*/
	friend DollarAmount getTotal(DollarAmount * list, int len);
	/*
 * 	@param: a list of dollar amounts and the length of the list
 * 	@pre-condition: The array has been filled 
 * 	@post-condition: The elements of the array have been added up
 * 	@return: A dollar amount object that holds the total value of the array's objects
 * 	*/
	void extractValues();
	/*
 	@pre-condition : The object has been given values for dollar/cent
	@post-condition: The digit values have been extracted to arrays
 	*/
	void setEnglishDollarAmount();
	/*
 	@pre-condition : The digit values have been stored into an array
	@post:condition: The dollar amount string been stored in englishPhrase
 	*/
	void setCenStr(string s);
	/*
 * 	@param: the string you wish to set centsStr to
 * 	@pre-condition: There is an onject ready to be filled
 * 	@post-condition: The arguments value has been set the centsStr
 * 	*/
private:
	int dollar, cents; // dollar and cent vars to store price infc
	int dollarArray[4], centArray[2];
	string expense, englishPhrase, centsStr;    // a string to hold the name of the expense 
};

