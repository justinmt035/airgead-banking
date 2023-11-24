//Justin M Taylor
//Professor Chan
//CS-210 Project 2

#include <iostream>
#include <iomanip>
#include "Account.h"
using namespace std;

/**
 * Default Account constructor
 *
 * @param years, years to display in report
 * @param openingAmount, amount account started with
 * @param depositAmount, amount of monthly deposit
 * @param interestRate, annual rate, to be compounded monthly
 * @param earnedInterest, total interest earned
 */
Account::Account() {
	years = 0;
	openingAmount = 0.0;
	depositAmount = 0.0;
	interestRate = 0.0;
	earnedInterest = 0.0;
}


/**
* Sets opening amount
* 
* @param openingAmount
*/
void Account::SetOpeningAmount(double openingAmount) {
	this->openingAmount = openingAmount;
}
/**
* Gets opening amount
*
* @return openingAmount
*/
double Account::GetOpeningAmount() {
	return openingAmount;
}

/**
* Sets deposit amount
*
* @param depositAmount
*/
void Account::SetDepositAmount(double depositAmount) {
	this->depositAmount = depositAmount;
}
/**
* Gets deposit amount
*
* @return depositAmount
*/
double Account::GetDepositAmount() {
	return depositAmount;
}

/**
* Sets interest rate
*
* @param interestRate
*/
void Account::SetInterestRate(double interestRate) {
	this->interestRate = interestRate;
}
/**
* Gets interest rate
*
* @return interestRate
*/
double Account::GetInterestRate() {
	return interestRate;
}

/**
* Sets years to display
*
* @param years
*/
void Account::SetYears(int years) {
	this->years = years;
}
/**
* Gets years to display
*
* @return years
*/
int Account::GetYears() {
	return years;
}

/**
* Sets total interest earned
*
* @param earnedInterest
*/
void Account::SetEarnedInterest(double earnedInterest) {
	this->earnedInterest = earnedInterest;
}
/**
* Gets total interest earned
*
* @return earnedInterest
*/
double Account::GetEarnedInterest() {
	return earnedInterest;
}

/**
* iterates through each month, calculating and storing compounding interest/adding it to the total balance,
* and accounting for additional monthly deposits
* 
* @param interest, interest earned in one monthly compounding based on updated balances
* @param total, keeps running tab of total balance and sets the final value to the account
* @param totalInterest, keeps running tab of interest earned and sets the final value to the account
*/
void Account::CalculateBalance(double openingAmount, double depositAmount, double interestRate) {
	int i;
	double interest;
	double total = openingAmount;
	double totalInterest = 0.0;

	//loop for each month and calculate total interest and total balance
	for (i = 0; i < 12; ++i) {
		interest = (total + depositAmount) * ((interestRate / 100) / 12);   //with monthly deposit
		total = total + depositAmount + interest;
		totalInterest = totalInterest + interest;
	}

	//update account variables
	this->earnedInterest = totalInterest;
	this->openingAmount = total;
}

/**
* iterates through each month, calculating and storing compounding interest/adding it to the total balance,
* with the addition of no monthly deposits
*
* @param interest, interest earned in one monthly compounding based on updated balances
* @param total, keeps running tab of total balance and sets the final value to the account
* @param totalInterest, keeps running tab of interest earned and sets the final value to the account
*/
void Account::CalculateBalanceNoDpst(double openingAmount, double interestRate) {
	int i;
	double interest;
	double total = openingAmount;
	double totalInterest = 0.0;

	//loop for each month and calculate total interest and total balance
	for (i = 0; i < 12; ++i) {
		interest = (total) * ((interestRate / 100) / 12);   //without monthly deposit
		total = total + interest;
		totalInterest = totalInterest + interest;
	}

	//update account variables
	this->earnedInterest = totalInterest;
	this->openingAmount = total;
}
/**
* Prints a report that takes additional monthly deposits into consideration.
* Loops for each year and calls the CalculateBalance method on each iteration,
* printing the results then moving to the next year 
*/
void Account::PrintLineDeposits() {
	cout << setw(60) 
		 << "    Balance and Interest With Additional Monthly Deposits    " << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	cout << setfill(' ') << setw(6) << right << "Year"
	 	 << setw(26) << right << "Year End Balance"
		 << setw(30) << right << "Year End Earned Interest" 
		 << setw(3) << "" << endl;
	cout << setfill('-') << setw(64) << "" << endl;

	int i;
	for (i = 1; i <= years; ++i) {
		this->CalculateBalance(this->openingAmount, this->depositAmount, this->interestRate);
		cout << setfill(' ') << setw(6) << right << i
			<< setw(26) << fixed << setprecision(2) << right << this->GetOpeningAmount()
			 << setw(30) << fixed << setprecision(2) << right << this->GetEarnedInterest() << endl;
	}
}
/**
* Prints a report that does not take additional monthly deposits into consideration.
* Loops for each year and calls the CalculateBalance method on each iteration,
* printing the results then moving to the next year
*/
void Account::PrintLineNoDeposits() {
	cout << setw(60)
		 << "    Balance and Interest Without Additional Monthly Deposits    " << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	cout << setfill(' ') << setw(6) << right << "Year"
		 << setw(26) << right << "Year End Balance"
		 << setw(30) << right << "Year End Earned Interest"
		 << setw(3) << "" << endl;
	cout << setfill('-') << setw(64) << "" << endl;

	int i;
	for (i = 1; i <= years; ++i) {
		this->CalculateBalanceNoDpst(this->openingAmount, this->interestRate);
		cout << setfill(' ') << setw(6) << right << i
			 << setw(26) << fixed << setprecision(2) << right << this->GetOpeningAmount()
			 << setw(30) << fixed << setprecision(2) << right << this->GetEarnedInterest() << endl;
	}
}
