#include "UnitTesting.h"
#include <vector>
#include <iostream>
#include <chrono>


typedef std::chrono::high_resolution_clock Clock;

int Test_SelectionSort(void) {
	int result = 1;
	// print out test suite message
	std::cout << "Selection Sort Test Suite:" << std::endl;


	// Test 1: Simple test 0-9
	std::vector<double> sortArray = { 1, 0, 2, 3, 7, 5, 4, 6, 9, 8 }, ans = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	// Now call Selection Sort on sortArray, recording the time the process takes
	auto start = Clock::now();
	SelectionSort(sortArray);
	auto finish = Clock::now();

	// Now verify equality and print out the results
	if (Verify(sortArray, ans)) {
		std::cout << "  Test 1 (Simple Test):    PASSED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}
	else {
		result = 0;
		std::cout << "  Test 1 (Simple Test):    FAILED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}


	// Test 2: Char test
	sortArray = { 'A', 'M', 'D', 'L', 'C', 'F', 'Z', 'I', 'H' }, ans = { 'A', 'C', 'D', 'F', 'H', 'I', 'L', 'M', 'Z' };
	start = Clock::now();
	SelectionSort(sortArray);
	finish = Clock::now();

	// Now verify equality and print out the results
	if (Verify(sortArray, ans)) {
		std::cout << "  Test 2 (Char Test):      PASSED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}
	else {
		result = 0;
		std::cout << "  Test 2 (Char Test):      FAILED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}


	// Test 3: Unequal Vectors
	sortArray = { 1, 3, 5, 6 }, ans = { 3, 5, 6, 9 };
	start = Clock::now();
	SelectionSort(sortArray);
	finish = Clock::now();

	// Now verify equality and print out the results
	if (!Verify(sortArray, ans)) {
		std::cout << "  Test 3 (Unequal Test):   PASSED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}
	else {
		result = 0;
		std::cout << "  Test 3 (Unequal Test):   FAILED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}


	// Test 4: Multiples of Items
	sortArray = { 1, 3, 5, 7, 10, 1, 20, 2, 3, 1 }, ans = { 1, 1, 1, 2, 3, 3, 5, 7, 10, 20 };
	start = Clock::now();
	SelectionSort(sortArray);
	finish = Clock::now();

	// Now verify equality and print out the results
	if (Verify(sortArray, ans)) {
		std::cout << "  Test 4 (Multiples Test): PASSED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}
	else {
		result = 0;
		std::cout << "  Test 4 (Multiples Test): FAILED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}

	// Test 5: Floats
	sortArray = { 0.5, 10.1, 3.14, 1.5, 0.2, 1, 3 }, ans = { 0.2, 0.5, 1, 1.5, 3, 3.14, 10.1 };
	start = Clock::now();
	SelectionSort(sortArray);
	finish = Clock::now();

	// Now verify equality and print out the results
	if (Verify(sortArray, ans)) {
		std::cout << "  Test 5 (Floats Test):    PASSED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}
	else {
		result = 0;
		std::cout << "  Test 5 (Floats Test):    FAILED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}

	// Test 5: Negative Numbers
	sortArray = { -1, 100, 1, 0, 1.5, -3, -300 }, ans = { -300, -3, -1, 0, 1, 1.5, 100 };
	start = Clock::now();
	SelectionSort(sortArray);
	finish = Clock::now();

	// Now verify equality and print out the results
	if (Verify(sortArray, ans)) {
		std::cout << "  Test 6 (Negatives Test): PASSED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}
	else {
		result = 0;
		std::cout << "  Test 6 (Negatives Test): FAILED  (" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "us)" << std::endl;
	}

	return result;
}


// ######## MAIN #########
int main() {
	Test_SelectionSort();


	std::cin.get();
	return(1);
}


// #### HELPER FUNCTIONS ####
int Verify(const std::vector<double>& sortArray, const std::vector<double>& ans) {
	for (unsigned int index = 0; index < sortArray.size(); index++) {
		if (sortArray[index] != ans[index]) {
			return 0;
		}
	}
	return 1;
}