// Programmer: Alfredo Yebra Jr.
// Data: June 22, 2016
// Description: Timing different algorithms with random data.

#include "sorts.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <omp.h>
#include <vector>

typedef std::vector<long> mergeSortVector; // Vector for merge sort
int getRandom(int min, const int max);

int main(int argCount, char** argVector) {
	const int SIZE = 1000;		// Size of array.
	const int COUNT = 5000;		// Number of times to sort data.
	int data[SIZE];				// Random data.
	int test[SIZE];				// Data to be sorted.
	int size = 100;				// Sort counter.
	int count = 0;				// Variable to count
	clock_t sortTime = 0;		// Sort timer.
	clock_t oTime = 0;			// Overhead timer.
	double duration = 0.00;		// Total time of sort.
	Algorithms algs;			// Algorithm object.
	omp_set_nested(1);			// Number of nested omp sections

	string sortParameter = atoi[1];
	if(sortParameter == NULL) {fprintf(stderr, "must define a sorting algorithm to use\n"); exit(-1);}
	int thread_count = atoi(argv[2]);
 	if (frames < 1) {fprintf(stderr, "error: thread_count must be at least 1\n"); exit(-1);}

	// Seed random number generator with real time.
	srand(unsigned(time(NULL)));

	// Outer data sweep.
	for (int pass = 0; pass < 10; pass++) {

		// Populate data array with random numbers, start sort counter and overhead timer.
		for (int i = 0; i < size; i++)
			data[i] = getRandom(0, SIZE);
		count = COUNT;
		oTime = clock();

		// Populate test array with random data and reset sort counter.
		while (count--)
			for (int i = 0; i < size; i++)
				test[i] = data[i];

		// Get the difference in time for overhead. and start sort timer.
		oTime = clock() - oTime;
		sortTime = clock();
		count = COUNT;

		// Populate test array
		while (count--) {
			for (int i = 0; i < size; i++)
				test[i] = data[i];
			algs.insertionSort(test, size);
		}

		// Calculate time.
		sortTime = clock() - sortTime;
		duration = double((sortTime - oTime)) / CLOCKS_PER_SEC;
		std::cout << "Time to sort " << size << " items " << COUNT << " times: ";
		std::cout << std::fixed << std::setprecision(3) << duration << " seconds." << std::endl;
		size += 100;
	}

	EXIT_SUCCESS;
}
int getRandom(int min, const int max) {
	return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}
