/**
 * @file
 * @author Richard J Pougnet <pougnerj@mcmaster.ca>
 * @brief File implementing QuickSort for 2-tuples
 *
*/
#include "sorter.h"

int Partition(float *A, float *B, int n)
{	
	float x = A[n-1];
	int i = 0;
	int j;
	float temp;

	for (j=0; j<=n-2; j++) {
		if (A[j] <= x) {
			temp = A[i];
			A[i]=A[j];
			A[j]=temp;
			temp = B[i];
			B[i]=B[j];
			B[j]=temp;
			i=i+1;
		}
	}
	temp = A[i];
	A[i]=A[n-1];
	A[n-1]=temp;

	temp = B[i];
	B[i]=B[n-1];
	B[n-1]=temp;

	return i;
}
				
/**
 * @brief QuickSort the 2-tuple by A
 * @param *A Pointer to array containing the element to sort by.
 * @param *B Pointer to array fo the other element
 * @param n The number of elements in the array.
*/
void QuickSort(float *A, float *B, int n)
{
	int q;

	if (n>1){
		q = Partition(A,B,n);
		QuickSort(&A[0],&B[0],q);
		QuickSort(&A[q+1],&B[q+1],n-1-q);
	}
}

