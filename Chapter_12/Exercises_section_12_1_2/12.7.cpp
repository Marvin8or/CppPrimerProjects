#include "section_interface.h"

shared_ptr<vector<int>> getSafeDynamicallyAllocatedVector(int size)
{
	shared_ptr<vector<int>> ptr = make_shared<vector<int>>(size, 0);
	return ptr;
}

void fillSafeVectorWithValues(shared_ptr<vector<int>> vptr)
{
	for (int i = 0; i < vptr->size(); i++)
	{
		int newvalue;
		cout << "Insert value: " << endl;
		cin >> newvalue;
		vptr->at(i) = newvalue;
	}
}

void printSafeVectorValues(shared_ptr<vector<int>> vptr)
{
	for (int i = 0; i < vptr->size() - 1; i++)
	{
		cout << "Value at index " << i << ": " << vptr->at(i) << endl;
	}
}