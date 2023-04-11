#pragma once
//Binary Search:

int binarySearch(int arr[], int leftIndex, int rightIndex, int target) {
	int index;
	index = (leftIndex + rightIndex) / 2;

	if (leftIndex <= rightIndex) {
		if (arr[index] == target) {
			return index;
		}
		if (arr[index] < target) {
			return binarySearch(arr, index + 1, rightIndex, target);
		}
		if (arr[index] > target) {
			return binarySearch(arr, leftIndex, index - 1, target);
		}
	}

	return -1;
}