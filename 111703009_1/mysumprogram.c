#include<stdio.h>
int main() {
	int i = 0, sum = 0;
	while(1) {
		scanf("%d", &i);
		if (i == -10000000)
			break;
		sum = sum + i;
	}
	printf("%d\n", sum);
	return 0;
}
