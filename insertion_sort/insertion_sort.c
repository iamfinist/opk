#define N 5

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void insertion_sort(int* arr, int n) {
	int temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

void sort_test(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
		assert(arr[i] <= arr[i + 1]);
}


int main() {

	int arr[N] = { 5, 2, 3, 4, 1 };
	insertion_sort(arr, N);
	sort_test(arr, N);

	int* arr2;
	int n = rand() % 100;
	arr2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		arr2[i] = rand() % 100;
	insertion_sort(arr2, n);
	sort_test(arr2, n);		

	return 0;
}