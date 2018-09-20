#include<stdlib.h>
#include"istack.h"
void iinit(istack *is) {
	is -> head = is -> tail = NULL;
}
void ipush(istack *is, int t) {
	inode *temp = (inode *)malloc(sizeof(inode));
	temp -> a = t;
	temp -> p = NULL;
	if(is -> head == NULL) {
		is -> head = temp;	
		is -> tail = temp;
	}
	else {
		is -> tail ->p = temp;
		is -> tail = temp;
	}
}
int ipop(istack *is) {
	inode *t, *y;
	int b, cnt = 0;
	t = is -> head;
	y = t;
	while(t -> p != NULL) {
		y = t;
		t = t -> p;
		cnt++;
	}
	b = t -> a;
	is -> tail = y;
	is -> tail -> p = NULL;
	if(cnt == 0) {
		is -> head = is -> tail = NULL;
	}
	free(t);
	return b;
}
int iisempty(istack *is) {
	return is -> head == NULL;
}

