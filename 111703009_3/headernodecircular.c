#include<stdio.h>
#include<stdlib.h>
typedef struct data {
	char name;
	struct data *p;
}data;
int main() {
	data a, *q;
	int i = 1, n = 0;
	q = &a;
	scanf("%d", &n);
	while(i <= n) {
		q->p = (data*)malloc(sizeof(data));
		scanf(" %c", &(q->p->name));
		q = q->p;
		i++;
	}
	q->p = &a;
	return 0;
}
