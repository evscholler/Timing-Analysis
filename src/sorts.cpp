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

vector<long> Algorithms::merge(const vector<long>& left, const vector<long>& right) {

	vector<long> result;
    unsigned left_it = 0, right_it = 0;
 
    while(left_it < left.size() && right_it < right.size()) {
		if(left[left_it] < right[right_it]) {
            result.push_back(left[left_it]);
            left_it++;
        }
        else {
            result.push_back(right[right_it]);
            right_it++;
        }
    }
 
    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size()) {
        result.push_back(left[left_it]);
        left_it++;
    }
 
    while(right_it < right.size()) {
        result.push_back(right[right_it]);
        right_it++;
    }
 
    return result;
}

vector<long> Algorithms::mergeSort(vector<long>& vec, int threads) {
	
	// Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1) 
    	return vec;
 
 	// Determine the location of the middle element in the vector
    std::vector<long>::iterator middle = vec.begin() + (vec.size() / 2);
 
    vector<long> left(vec.begin(), middle);
    vector<long> right(middle, vec.end());
 
    // Perform a merge sort on the two smaller vectors
 
    if (threads > 1) {
      #pragma omp parallel sections
      {
        #pragma omp section
        {
          left = mergesort(left, threads/2);
        }
        #pragma omp section
        {
          right = mergesort(right, threads - threads/2);
        }
      }
    } 
    else {
      left = mergesort(left, 1);
      right = mergesort(right, 1);
    }
 
    return merge(left, right);
}

