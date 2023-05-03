#include <stdio.h>

void fib(int n) {
	unsigned int first = 0;
	unsigned int cal = 1;
	unsigned int last = 1;

	for(int i=0;i<=n;i++){
		printf("%d \n", cal);
		
		cal = first+last;
		first = last;
		last = cal;	
	}
}

int main(void){
	int n=0;
	printf("넣어라");
	scanf("%d", &n);
	fib(n);	
}
