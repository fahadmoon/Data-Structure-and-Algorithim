/* C++ implementation of QuickSort */
#include <iostream>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int e, int s)
{
	int pivot = arr[s]; // pivot
	int i
		= (e- 1); 

	for (int j = e; j <= s - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[s]);
	return (i + 1);
}
void quickSort(int arr[], int e, int s)
{
	if (e < s) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, e, s);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, e, pi - 1);
		quickSort(arr, pi + 1, s);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = { 12,2,9,45,33,22,99,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra
