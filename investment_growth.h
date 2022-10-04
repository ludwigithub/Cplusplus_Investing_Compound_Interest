/*
 * CS210_Project_Two_DLUDWIG
 * Date: 07/31/2022
 * Name: Deonne Ludwig
 *
 */

#pragma once																					//code placed here is included only once per translation unit
#ifndef DEONNE_CS210_PROJECT_TWO_AIRGEAD_INVESTMENT_GROWTH_H_									//prevent redeclaration of any identifiers
#define DEONNE_CS210_PROJECT_TWO_AIRGEAD_INVESTMENT_GROWTH_H_									//compiler defines and includes the contents

class InvestmentGrowth {																		//class declaration contacts info
public:																							//declare public class functions
	InvestmentGrowth(double t_investment, double t_deposit, double t_interest, int t_years);	//parameterized constructor
	void reportWithoutMonthlyDeposits();														//to list w/o mnthy deposits
	void reportWithMonthlyDeposits();															//to list w/ mnthy deposits
private:																						//declare private class functions
	double m_initialInvestment;																	//declare variables to calculate interest
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numberOfYears;
};
#endif