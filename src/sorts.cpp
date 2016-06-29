#include "sorts.h"


Algorithms::Algorithms() {}

void Algorithms::bubbleSort(int array[], int size) {
	for (int i=0; i<size-1; i++) {
		for (int j=0; j<size-1; j++) {
			if (array[j] > array[j+1]) {
				int temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}

void Algorithms::modifiedBubbleSort(int array[], int size) {
	for (int i = 0; i<size-1; i++) {
		for (int c = 0; c<size-1-i; c++) {
			if (array[c] > array[c+1]) {
				int tmp = array[c];
				array[c] = array[c+1];
				array[c+1] = tmp;
			}
		}
	}
}

void Algorithms::insertionSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 && array[j-1] > array[j]) {
			int tmp = array[j];
			array[j] = array[j - 1];
			array[j-1] = tmp;
			j--;
		}
	}
}

