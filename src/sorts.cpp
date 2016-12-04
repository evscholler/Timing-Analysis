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

void Algorithms::merge(int a[], int size, int temp[]) {

	int i1 = 0;
    int i2 = size/2;
    int tempi = 0;
    while (i1 < size/2 && i2 < size) {
        if (a[i1] < a[i2]) {
            temp[tempi] = a[i1];
            i1++;
        } else {
            temp[tempi] = a[i2];
            i2++;
        }
        tempi++;
    }
    while (i1 < size/2) {
        temp[tempi] = a[i1];
        i1++;
        tempi++;
    }
    while (i2 < size) {
        temp[tempi] = a[i2];
        i2++;
        tempi++;
    }
    // Copy sorted temp array into main array, a
    memcpy(a, temp, size*sizeof(int));
}

void Algorithms::mergeSort(int array[], int threads, int size, int temp[]) {
	
	if ( threads == 1) {
//        printf("Thread %d begins serial merge sort\n", omp_get_thread_num());
    	//mergesort_serial(a, size, temp);
    } else if (threads > 1) {
       #pragma omp parallel sections num_threads(2)
       {
//		        printf("Thread %d begins recursive section\n", omp_get_thread_num());
			#pragma omp section
		        { //printf("Thread %d begins recursive call\n", omp_get_thread_num());
			mergesort_parallel_omp(a, size/2, temp, threads/2);}
			#pragma omp section
		        { //printf("Thread %d begins recursive call\n", omp_get_thread_num());
			mergesort_parallel_omp(a + size/2, size - size/2, temp + size/2, threads - threads/2);}
			// The above use of temp + size/2 is an essential change from the serial version	
       }
	   // Thread allocation is implementation dependent
       // Some threads can execute multiple sections while others are idle 
       // Merge the two sorted sub-arrays through temp
       merge(a, size, temp); 
    } else {
       printf("Error: %d threads\n", threads); 
       return;
    }
}

void Algorithms::oddEvenSort(int array[], int thread_count, int size) {
	
	int i, phase, temp;

#	pragma omp parallel num_threads(thread_count) \
		default(none) shared(array, size) private(i, temp, phase)
		for (phase = 0; phase < size; phase++) {
			if (phase % 2 == 0) 
#				pragma omp for
				for (i = 1; i < size; i += 2) {
					if (array[i-1] > array[i]) {
						temp = array[i-1];
						array[i-1] = array[i];
						array[i] = temp;
					}
				}
			else
#				pragma omp for 
				for (i = 1; i < size-1; i += 2) {
					if (array[i] > array[i+1]) {
						temp = array[i+1];
						array[i+1] = array[i];
						array[i] = temp;
					}
				}
		}
}

