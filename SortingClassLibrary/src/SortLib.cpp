#include "SortLib.h"
#include <iostream>
#include <vector>
#include <array>


void SelectionSort(std::vector<int>& a_in) {
	for (unsigned int outer = 0; outer < (a_in.size() - 1); outer++) {
		for (unsigned int inner = outer + 1; inner < a_in.size(); inner++) {
			if (a_in[inner] < a_in[outer]) {
				int temp = a_in[inner];
				a_in[inner] = a_in[outer];
				a_in[outer] = temp;
			}
		}
	}
	return;
}