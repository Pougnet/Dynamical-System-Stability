#include "sorter.h"
#include "stdio.h"

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
				

void QuickSort(float *A, float *B, int n)
{
	int q;

	if (n>1){
		q = Partition(A,B,n);
		QuickSort(&A[0],&B[0],q);
		QuickSort(&A[q+1],&B[q+1],n-1-q);
	}
}

