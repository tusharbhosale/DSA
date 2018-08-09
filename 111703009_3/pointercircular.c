#include<stdio.h>
#include<stdlib.h>
typedef struct data {
	char name;
	struct data *r;
}data;
int main() {
	data *p, *q;
	int n, i = 1;
	scanf("%d", &n);
	if(n > 0) {
		p = (data*)malloc(sizeof(data));
		q = p;
		scanf(" %c", &(p->name));
		while (i < n) {
			q->r = (data*)malloc(sizeof(data));
			scanf(" %c", &(q->r->name));
			q = q->r;
			i++;			
		}
		q->r = p;
	}
	else {
		p = NULL;
	}
}
