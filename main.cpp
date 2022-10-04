/*
 * CS210_Project_Two_DLUDWIG
 * Date: 07/31/2022
 * Name: Deonne Ludwig
 *
 */

#include <iostream>														//enables use cout, cin, endl, etc.
#include <iomanip>														//to be able to use setfill, setw, etc.
#include "investment_growth.h"											//include the header file investment_growth.h

using namespace std;													//enables std without typing

int main() {															//begin program
	double initialInvestment, monthlyDeposit, interestRate;				//variables to hold information
	int numberOfYears;
	char endProgram = 'X';

	while (endProgram != 'Q') {
		try {															//try/catch for wrong input
			cout << setfill('*') << setw(41) << "*" << endl;			//display blank menu
			cout << setfill('*') << setw(14) << "*";
			cout << " Data Input " << setw(14) << "*" << endl;
			cout << "Initial Investment Amount: " << endl;
			cout << "Monthly Deposit: " << endl;
			cout << "Annual Interest: " << endl;
			cout << "Number of years: " << endl << endl << endl;

			cout << setfill('-') << setw(41) << "-" << endl;			//prompt user for input
			cout << " *PLEASE ENTER YOUR INFORMATION BELOW*" << endl;
			cout << setfill('-') << setw(41) << "-" << endl << endl;

			cout << setfill('*') << setw(41) << "*" << endl;			//get user info
			cout << setfill('*') << setw(14) << "*";
			cout << " Data Input " << setw(14) << "*" << endl;
			cout << "Initial Investment Amount: $";
			cin >> initialInvestment;
			if (initialInvestment < 0) {								//check for positive real number
				throw runtime_error("Invalid amount");
			}
			cout << "Monthly Deposit: $";
			cin >> monthlyDeposit;
			if (monthlyDeposit < 0) {									//check for positive real number
				throw runtime_error("Invalid amount");
			}
			cout << "Annual Interest: %";
			cin >> interestRate;
			cout << "Number of years: ";
			cin >> numberOfYears;
			system("pause");

			InvestmentGrowth InvestmentTotals = InvestmentGrowth(initialInvestment, monthlyDeposit, interestRate, numberOfYears); //store user input
			cout << endl;
			InvestmentTotals.reportWithoutMonthlyDeposits();			//call w/o mnthy deposits list
			cout << endl;
			if (monthlyDeposit > 0) {									//call w/ mnthy deposits list
				InvestmentTotals.reportWithMonthlyDeposits();
			}
		}
		catch (runtime_error& excpt) {									//prints the error message passed by throw statement
			cout << excpt.what() << endl;
			cout << "Cannot compute investment interest" << endl;
		}
		cout << endl << "Return to main menu (Y) or to quit (Q) ";		//user input to quit or re-enter info
		cin >> endProgram;

	}
	return 0;
}
