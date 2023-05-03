#include<stdio.h>
int target[10] = {5,7,2,9,8,1,6,17,53,23};
int temp[10];

void Merge(int start, int end, int m){ 
	for(int i=start;i<=end;i++)
		temp[i] = target[i];

	int templeft = start;
	int tempright = m+1;
	int current = start;

	while(templeft<=m && tempright<=end){
		if(temp[templeft]<=temp[tempright]){
			target[current] = temp[templeft];
			templeft++;
		}
		else{
			target[current] = temp[tempright];
			tempright++;
		}
		current++;
	}
	int remaing = m - templeft;

	for(int i=0; i<=remaing; i++){
		target[current+i] = temp[templeft+i];
	}
}

void MergeSort(int size, int start, int end){
	if(start < end){
		int m = (start+end)/2;
		MergeSort(m-start+1, start, m);
		MergeSort(end-m, m+1, end);
		Merge(start, end, m);
		
		
	}
}


int main(void){
	MergeSort(10,0,9);
	for(int i=0;i<10;i++){
		printf("%d\n",target[i]);
	}
}
