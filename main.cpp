#include <iostream>
using namespace std;

int main()
{
         int  dollars, cents, thousands, hundreds, tens, ones, tenths, hundreths;
         char ch, exitCode;
         bool isGood;
 
          cout << "-----Welcome to MakeMoney-----\n"
               << "Enter an amount to convert: $";
          while(true)//Creating main loop to take input ( will be placed into a function later)
          {
                  cin >> dollars;
                  if (cin.fail() || dollars > 9999)//Checks dollar amount to ensure validity
                  {
                          cin.clear();
                          cin.ignore();
                          exitCode = 'd';//exit code for invalid dollar 
                          break;
                  }
                  cin >> ch;
                  if (cin.fail() || ch != '.')//checks to make sure there is a period separating the two values
                  {
                          cin.clear();
                          cin.ignore();
                          exitCode = 's';//exit code for separation error
                          break;
                  }
                  cin >> cents;
                  if (cin.fail() || cents > 99)//checks cents for validity
                  {
                          cin.clear();
                          cin.ignore();
                          exitCode = 'c';//exit code for cent error
                          break;
                  }
                  exitCode = 'g';//exit code for clean entry
                  break;
          }
 
          switch (exitCode)//returns a message based on the exitCode from initial input function
          {
                  case ('d'):
                          cout << "You have entered an invlid input to the dollars place.\n"
                               << "\tPlease try again.\n";
                          break;
                  case ('s'):
                          cout << "Error: You need to separate the dollar amount by a period.\n"
                               << "\tPlease try again.\n";
                          break;
                  case ('c'):
                          cout << "You have entered an invalid input to the cents place\n"
                               << "\tPlease try again\n";
                          break;
                  case ('g'):
                          cout << "Thank you. Your input was valid.\n"
                               << "\tProcessing...\n";
                          break;
                  deafult:
                          cout << "Bug in code. Check over logic\n";
                          break;
          }
          return 0;
  }
 
