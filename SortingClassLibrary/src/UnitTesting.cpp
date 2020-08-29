#include "UnitTesting.h"
#include <vector>
#include <iostream>




int Test_SelectionSort(void) {
	int result = 1;
	// print out test suite message
	std::cout << "Selection Sort Test Suite:" << std::endl;


	// Test 1: Simple test 0-9
	std::vector<int> sortArray = { 1, 0, 2, 3, 7, 5, 4, 6, 9, 8 }, ans = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	// Now call Selection Sort on sortArray
	SelectionSort(sortArray);

	// Now check for equality
	for (unsigned int index = 0; index < sortArray.size(); index++) {
		if (sortArray[index] != ans[index]) {
			std::cout << "  Test 1 (Simple Test): FAILED" << std::endl;
			result = 0;
			break;
		}
		// Now print out a passing status message
		if (index == (sortArray.size() - 1)) {
			std::cout << "  Test 1 (Simple Test): PASSED" << std::endl;
		}
	}
	return result;
}


// ######## MAIN #########
int main() {
	Test_SelectionSort();


	std::cin.get();
	return(1);
}