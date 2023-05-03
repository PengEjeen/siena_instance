#include<stdio.h>
#define MAX 10

int top = -1;

int is_full() {
	int full = 1;
	if(top == MAX-1) {full=1;}

	return full;
}

int is_empty() {
	int empty =1;
	if(top == -1) {empty=0;}
	return empty;
}

void push(int arr[], int num) {
	int full = is_full();
	if(full==1){
		top = top+1;
		arr[top] = num;
	}
}

void pop(int arr[]){
	int empty = is_empty();

	if(empty==1){
		printf("\n%d", arr[top]);
		arr[top]= NULL;
		top = top-1;
	}
	
}


int main(void) {
	int list[MAX];
	push(list, 3);
	printf("\n%d", list[0]);

	pop(list);
	printf("\n%d", list[0]);	
	
	return 0;
}
