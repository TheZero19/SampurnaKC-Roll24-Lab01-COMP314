#pragma once

int* randomArrayGeneratorLS(int size) {
	int* randomArray = new int[size];
	for (int i = 0; i < size; i++) {
		randomArray[i] = i;
	}
	return randomArray;
}