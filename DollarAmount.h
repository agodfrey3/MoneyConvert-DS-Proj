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
	DollarAmount operator+(DollarAmount &d2);
	/*
 	@param         : The right side object we wish to use in our addition
	@pre-condition : The objects to the left and right of '+' have been successfully filled with data
	@post-condition: A new object is created which adds the values within the objects
	@return        : An object of type DollarAmount that contains the added values
 	*/
private:
	int dollar, cents; // dollar and cent vars to store price infc
	string expense;    // a string to hold the name of the expense 
};

