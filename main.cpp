//Justin M Taylor
//Professor Chan
//CS-210 Project 2
//6-5-2022

#include <iostream>
#include <iomanip>
#include "Account.h"
using namespace std;

void MainMenu(Account& account);

int main() {
	double originalDeposit = 0.0;
	char cont = 'y';
	char correct = 'n';

	Account account;

	//loop the program until user is satisfied
	while (cont != 'n') {
		
		//loop main menu until user is satisfied with input
		correct = 'n';
		while (correct == 'n') {
			MainMenu(account);
			cout << "Correct? y/n: ";
			cin >> correct;
			cout << endl;
		}

		//hold the original balance in a placeholder and print one report
		originalDeposit = account.GetOpeningAmount();
		account.PrintLineNoDeposits();
		cout << endl;

		//reset the original balance with the placeholder and print other report
		account.SetOpeningAmount(originalDeposit);
		account.PrintLineDeposits();
		cout << endl;

		//prompt user for more input or exit
		cout << "Continue? y/n: ";   //continues on anything but 'n'
		cin >> cont;
		cout << endl;
	}

	return 0;

}

/**
* Displays a menu and takes/sets initial parameters for new account
*/
void MainMenu(Account& account) {
	double openingAmount;
	double depositAmount;
	double interestRate;
	int years;

	cout << setfill('*') << setw(36) << "" << endl;
	cout << setfill('*') << setw(23) << "Data Input" << setfill('*') << setw(13) << "" << endl;
	cout << "Initial Investment Amount: $";
	cin >> openingAmount;
	cout << "Monthly Deposit: $";
	cin >> depositAmount;
	cout << "Annual Interest (%): ";
	cin >> interestRate;
	cout << "Number of years ";
	cin >> years;

	account.SetOpeningAmount(openingAmount);
	account.SetDepositAmount(depositAmount);
	account.SetInterestRate(interestRate);
	account.SetYears(years);

}