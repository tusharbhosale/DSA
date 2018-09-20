#include<stdlib.h>
#include"cstack.h"
void cinit(cstack *cs) {
	cs -> head = cs -> tail = NULL;
}
void cpush(cstack *cs, char t) {
	cnode *temp = (cnode *)malloc(sizeof(cnode));
	temp -> a = t;
	temp -> p = NULL;
	if(cs -> head == NULL) {
		cs -> head = temp;	
		cs -> tail = temp;
	}
	else {
		cs -> tail ->p = temp;
		cs -> tail = temp;
	}
}
char cpop(cstack *cs) {
	cnode *t, *y;
	int  cnt = 0;
	char b;
	t = cs -> head;
	y = t;
	while(t -> p != NULL) {
		y = t;
		t = t -> p;
		cnt++;
	}
	b = t -> a;
	cs -> tail = y;
	cs -> tail -> p = NULL;
	if(cnt == 0) {
		cs -> head = cs -> tail = NULL;
	}
	free(t);
	return b;
}
int cisempty(cstack *cs) {
	return cs -> head == NULL;
}

