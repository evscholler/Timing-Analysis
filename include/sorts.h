#ifndef SORTS_H
#define SORTS_H


class Algorithms {

	public:
		Algorithms();
		void bubbleSort(int array[], int size);
		void modifiedBubbleSort(int array[], int size);
		void insertionSort(int array[], int size);
		vector<long> merge(const vector<long>& left, const vector<long>& right);
		vector<long> mergeSort(vector<long>& vec, int threads);
		void oddEvenSort(int array[], int thread_count, int size);
};


#endif
