/*
 * CS210_Project_Two_DLUDWIG
 * Date: 07/31/2022
 * Name: Deonne Ludwig
 *
 */

#include <iostream>																								//enables use cout, cin, endl, etc.
#include <iomanip>																								// to be able to use setfill, setw, etc.
#include "investment_growth.h"																					//include the header file investment_growth.h

using namespace std;																							//enables std without typing


InvestmentGrowth::InvestmentGrowth(double t_investment, double t_deposit, double t_interest, int t_years) {		//parameterized constructor
	this->m_initialInvestment = t_investment;																	//sets values for member variables
	this->m_monthlyDeposit = t_deposit;
	this->m_interestRate = t_interest;
	this->m_numberOfYears = t_years;
}

void InvestmentGrowth::reportWithoutMonthlyDeposits() {															//header for w/o mnthy deposits list
	cout << "   Balance and Interest WITHOUT Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(75) << "=" << endl;
	cout << setfill(' ') << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(75) << "-" << endl;

	int currentYear = 1;																						//iterate and increase for years input and calculate interest
	double yearEndBalance = this->m_initialInvestment;
	while (currentYear <= this->m_numberOfYears) {																
		double yearEndEarnedInterest = yearEndBalance * this->m_interestRate / 100;
		yearEndBalance += yearEndEarnedInterest;																
		cout << right << setfill(' ') << setw(10) << currentYear << fixed << setprecision(2)					//print w/o mnthy deposits list				
			<< setw(20) << yearEndBalance
			<< setw(35) << yearEndEarnedInterest << endl;
		currentYear++;																							
	}
}

void InvestmentGrowth::reportWithMonthlyDeposits() {															//header for w/ mnthy deposits list
	cout << "   Balance and Interest WITH Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(75) << "=" << endl;
	cout << setfill(' ') << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(75) << "-" << endl;

	int currentYear = 1;																						//iterate and increase for years input and calculate interest
	double yearEndBalance = this->m_initialInvestment;
	while (currentYear <= this->m_numberOfYears) {																
		int currentMonth = 1;
		double yearEndEarnedInterest = 0.0;
		double monthEndBalance = yearEndBalance;
		while (currentMonth <= 12) {
			monthEndBalance += this->m_monthlyDeposit;															
			double monthEndEarnedInterest = monthEndBalance * this->m_interestRate / (100 * 12);						
			yearEndEarnedInterest += monthEndEarnedInterest;																	
			monthEndBalance += monthEndEarnedInterest;																	
			currentMonth++;																							
		}

		yearEndBalance = monthEndBalance;																		

		cout << right << setfill(' ') << setw(10) << currentYear << fixed << setprecision(2)					//print w/o mnthy deposits list					
			<< setw(20) << yearEndBalance
			<< setw(35) << yearEndEarnedInterest << endl;
		currentYear++;																							
	}
}