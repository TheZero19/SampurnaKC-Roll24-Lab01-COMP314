#pragma once
#include<iostream>
#include"binarySearch.h"
#include<chrono>
#include<thread>

using namespace std;

void timeComplexity(int arr[], int target, int size) {

	// Record the start time
	auto start_time = std::chrono::high_resolution_clock::now();

	binarySearch(arr, 0, size - 1, target);

	// Record the end time
	auto end_time = std::chrono::high_resolution_clock::now();

	// Calculate the elapsed time
	auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	// Print the elapsed time in milliseconds
	cout << "Elapsed time for: inputSize: " << size <<" = " << elapsed_time.count() << " microseconds\n";

}
