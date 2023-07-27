#include "Account.h"
#include <iostream>

Account::Account(std::string& owner_name)
{
	name = owner_name;
}

void Account::getCurrentSate(bool notInterestRate)
{
	if(notInterestRate)
	{
		std::cout << "Current amount without interest: " << currentState << std::endl;
	}
	else
	{
		double amount = currentState * interestRate;
		std::cout << "Current amount with interest: " << amount << std::endl;

	}
}

void Account::deposit(double amount)
{
	currentState += amount;
}

void Account::withdraw(double amount)
{
	currentState -= amount;
}
void Account::initRate(double rate)
{
	interestRate = rate;
}

void Account::rate()
{
	std::cout << "The interest rate is: " << interestRate << std::endl;
}
