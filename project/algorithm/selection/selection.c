#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int Partition(A[], int start, int end){
	int pivot = A[start];
	int low = start+1
	int high = end;
	int temp = 0;

	while(low<=high){
		while(low<=end && A[low]<=pivot){
			low++;
		}
		while(high>=(start+1) && A[high]>=pivot){
			high--;
		}
		if(low<=high){
			temp = A[low];
			A[low] = A[high];
			A[high] = temp;
		}
	}
	temp = A[start];
	A[start] = A[high];
	A[high] = temp;

	return high;
}

int select(int A[], int start, int end, int select){
	if(select>0 && select<=end-start+1){
		int pos = Partition(A,start,end);
	}

	if(pos-start == select-1){
		return A[pos];
	}
	else if(pos-start>select-1){
		return select_Prob(A,start,pos-1,select);
	}
	else{
		return select_Prob(A, pos+1, end, select-pos+start-1);
	}
	return -1
}

int main(void){
	int n
}
