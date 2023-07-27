#pragma once
#include <iostream>
// Literal class Account from Section 7.6 (Static keyword)

class Account
{
private:
	static double interestRate;
	double currentState;
	std::string name;
public:
	void getCurrentSate(bool notInterestRate = true);
	void deposit(double amount);
	void withdraw(double amount);
	static void rate();
	Account(std::string& owner_name);
	static void initRate(double rate);

};

