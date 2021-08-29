#include<stdio.h>
#include<stdlib.h>
#define size 100000
#include<time.h>

int val[size];
void random(int val[]) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		val[i] = rand() % 100000 + 1;
		
	}
}


void insertion_sort(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		
		arr[j + 1] = key;
	}
	
	printf("The array sorted using insertion sort in %u seconds\n", clock());
}

void swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void quick_sort(int start, int end) {
	if (start >= end)return;
	int key = start, i = start + 1, j = end;
	while (i <= j) {
		while (i <= end && val[i] <= val[key]) i++;
		while (j > start && val[j] >= val[key])j--;
		if (i > j) swap(&val[key], &val[j]);
		else swap(&val[i], &val[j]);
	}
	
	quick_sort(start, j - 1);
	quick_sort(j + 1, end);
	
}


int main() {
	int arr[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100000 + 1;
	}
	printf("Array of 100000 random numbers is initialized \n");
	random(val);
	quick_sort(0, size - 1);
	printf("The array sorted using quick sort in %u seconds\n", clock());
	insertion_sort(arr, size);
	return 0;
	
}

