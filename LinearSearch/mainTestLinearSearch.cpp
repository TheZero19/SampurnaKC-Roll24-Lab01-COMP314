#include<iostream>
#include<gtest/gtest.h>
#include "linearSearch.h"
#include "randomArrayGeneratorLS.h"
#include "timeComplexityLS.h"

using namespace std;

//same test cases as of binary search:

TEST(LINEAR_SEARCH_TEST, ReturnValidIndex) {

	//test array: arr with predefined elements in sorted order.
	int arr[5] = { 1, 2, 3, 4, 5 };
	//target 1-3 within range:
	int target1 = 1;
	int target2 = 3;
	int target3 = 5;


	EXPECT_EQ(0, linearSearch(arr, target1, 5));
	EXPECT_EQ(2, linearSearch(arr, target2, 5));
	EXPECT_EQ(4, linearSearch(arr, target3, 5));

}

TEST(NotPresentInArray, ReturnNegativeOne) {
	int target = -1;

	//test array: arr.
	int arr[5] = { 1, 2, 3, 4, 5 };

	EXPECT_EQ(-1, linearSearch(arr, target, 5));
}



int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	//finding data for time complexities wrt variable input size:
	//using same data as of Binary Search for uniformity.
	int size[] = { 100000, 1000000, 10000000, 100000000, 1000000000 };

	int bestCaseTarget = 0; //best case is when the value we're looking for is in the 1st index.

	int worstCaseTarget[] = {99999, 999999, 9999999, 99999999, 999999999};	//worst case is when the value we're looking for lies at the end of array.

	cout << "For Best Case: " << endl << endl;
	for (int i = 0; i < 4; i++) {
		int* arr = randomArrayGeneratorLS(size[i]);
		timeComplexity(arr, bestCaseTarget, size[i]);
		delete[] arr;
	}

	cout << "For Worst Case: " << endl;
	for (int i = 0; i < 4; i++) {
		int* arr = randomArrayGeneratorLS(size[i]);
		timeComplexity(arr, worstCaseTarget[i], size[i]);
		delete[] arr;
	}

	return RUN_ALL_TESTS();

}