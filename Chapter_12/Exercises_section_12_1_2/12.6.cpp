#include "section_interface.h"

vector<int>* getDynamicallyAllocatedVector(int size)
{
	vector<int>* ptr = new vector<int>(size, 0);
	return ptr;
}

void fillVectorWithValues(vector<int>* vptr)
{
	for(int i = 0; i < vptr->size(); i++)
	{
		int newvalue;
		cout << "Insert value: " << endl;
		cin >> newvalue;
		vptr->at(i) = newvalue;
	}
}

void printVectorValues(vector<int>* vptr)
{
	for (int i = 0; i < vptr->size() - 1; i++)
	{
		cout << "Value at index " << i << ": " << vptr->at(i) << endl;
	}
}