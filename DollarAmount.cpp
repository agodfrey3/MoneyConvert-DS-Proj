DollarAmount::DollarAmount()
{
	setDollar(0);
	setCents(0);
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
DollarAmount DollarAmount::operator+(DollarAmount &d2)
{
	DollarAmount temp;
	int newCents = (cents + d2.getCents()) % 100;
	temp.setCents(newCents);
	int extra = ( (cents) + (d2.getCents()) ) / 100;
	temp.setDollar( dollar + d2.dollar + extra );
	return temp;
}
bool DollarAmount::fail()
{
	if (dollar > 9999)
		return true;
	else
		return false;
}
