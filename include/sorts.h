#ifndef SORTS_H
#define SORTS_H


class Algorithms {

	public:
		Algorithms();
		void bubbleSort(int array[], int size);
		void modifiedBubbleSort(int array[], int size);
		void insertionSort(int array[], int size);
		void merge(int a[], int size, int temp[]);
		void mergeSort(int array[], int threads, int size, int temp[]);
		void oddEvenSort(int array[], int thread_count, int size);
};


#endif
