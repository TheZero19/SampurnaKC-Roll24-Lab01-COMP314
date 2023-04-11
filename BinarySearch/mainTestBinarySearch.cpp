#include"pch.h"
#include<iostream>
#include<gtest/gtest.h>
#include"binarySearch.h"
#include"timeComplexityBS.h"
#include"randomSortedArrayGenerator.h"

//test cases:

TEST(BINARY_SEARCH_TEST, ReturnValidIndex) {

	//test array: arr with predefined elements in sorted order.
	int arr[5] = { 1, 2, 3, 4, 5 };
	//target 1-3 within range:
	int target1 = 1;
	int target2 = 3;
	int target3 = 5;
	

	EXPECT_EQ(0, binarySearch(arr, 0, 5 - 1, target1));
	EXPECT_EQ(2, binarySearch(arr, 0, 5 - 1, target2));
	EXPECT_EQ(4, binarySearch(arr, 0, 5 - 1, target3));

}

TEST(NotPresentInArray, ReturnNegativeOne) {
	int target = -1;

	//test array: arr.
	int arr[5] = { 1, 2, 3, 4, 5 };

	EXPECT_EQ(-1, binarySearch(arr, 0, 5 - 1, target));
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	
	//finding data for time complexities wrt variable input size:
	int size[] = { 100000, 1000000, 10000000, 100000000, 1000000000 };
	/*worst case scenario occurs when the value we're searching either lies towards the starting indices
	* or towards the end indices of our sorted array in Binary Search.
	* But only testing for initial starting indices values as the array we're generating might not
	* contain high end indices values. For our example, taking "1" as the worst Case value.
	*/
	int worstCaseTarget = 1;
	for (int i = 0; i < 5; i++) {
		int* arr = randomSortedArrayGenerator(size[i]);
		timeComplexity(arr, worstCaseTarget, size[i]);
		delete[] arr;
	}


	return RUN_ALL_TESTS();

}