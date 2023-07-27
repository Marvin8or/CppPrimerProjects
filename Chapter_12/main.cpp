#include "Exercises_section_12_1_2/section_interface.h"

int main()
{
	/*
	 * Exrcise 12.6
	vector<int>* vptr = getDynamicallyAllocatedVector(5);
	fillVectorWithValues(vptr);
	printVectorValues(vptr);
	delete vptr;
	printVectorValues(vptr);
	*/

	/*
	* Exrcise 12.7
	*/
	{
		// Execute in scope to see effect of shared_ptr
		shared_ptr<vector<int>> vptr;
		vptr = getSafeDynamicallyAllocatedVector(5);

		{
			shared_ptr<vector<int>> vptr2 = vptr;
		}

		fillSafeVectorWithValues(vptr);
		printSafeVectorValues(vptr);
	}

	return 0;
}