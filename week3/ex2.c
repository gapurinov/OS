#include <stdio.h>

const int MXN = 1e5 + 7;

void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void bubbleSort(int arr[], int n) { 
   for(int i = 0; i < n-1; i++)           
       for(int j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

int main() {
	int n, a[MXN];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bubbleSort(a, n);
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}