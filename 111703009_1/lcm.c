#include<stdio.h>
int main() {
	int a = 0, b = 0, i = 1;
	scanf("%d%d", &a, &b);
	if(a != 0 && b!=0) {
		while(1) {
			if((a * i) % b == 0) {
				printf("%d\n", a * i);
				break;
			}
			i++;		
		}	
	}
	else {
		printf("0\n");	
	}
	return 0;
}
