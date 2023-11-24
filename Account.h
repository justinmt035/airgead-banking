//Justin M Taylor
//Professor Chan
//CS-210 Project 2
//6-5-2022

#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

/**
* Account class header file
*/
class Account {
public:
	Account();
	void SetOpeningAmount(double openingAmount);
	void SetDepositAmount(double depositAmount);
	void SetInterestRate(double interestRate);
	void SetYears(int years);
	void SetEarnedInterest(double earnedInterest);

	double GetOpeningAmount();
	double GetDepositAmount();
	double GetInterestRate();
	int GetYears();
	double GetEarnedInterest() ;

	
	void CalculateBalanceNoDpst(double openingAmount, double interestRatw);
	void CalculateBalance(double openingAmount, double depositAmount, double interestRate);
	void PrintLineDeposits();
	void PrintLineNoDeposits();

private:
	int years;
	double openingAmount;
	double depositAmount;
	double interestRate;
	double earnedInterest;
};

#endif // !ACCOUNT_H
