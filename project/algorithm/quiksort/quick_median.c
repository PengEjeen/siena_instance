#include<stdio.h>

#define MAX 10

void QuickSort(int A[], int start, int end){
	int left = start;
	int right = end;
	int temp;
	int pivot = A[(start+end)/2];
	
	while(left<=right){
		while(A[left]<pivot)
			left++;
		while(A[right]>pivot)
			right--;
		
		if(left<=right){
			if(left!=right){
				temp = A[left];
				A[left] = A[right];
				A[right] = temp;
			}
			left++; 
			right--;
		}


	}
	if(start<right)
		QuickSort(A, start, right);
	if(left<end)
		QuickSort(A,left,end);

}

void printArr(int A[]){
	for(int i=0;i<MAX;i++){
		printf("%d\n", A[i]);
	}
}

int main(void){
	int A[MAX] = {3,5,7,9,1,2,4,6,8,0};
	printArr(A);
	QuickSort(A, 0, MAX-1);
	printf("sort\n");
	printArr(A);

	return 0;
}
