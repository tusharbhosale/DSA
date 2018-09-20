typedef struct cnode {
	int a;
	struct cnode *p;
}cnode;
typedef struct cstack {
	cnode *head, *tail;
}cstack;
void cinit(cstack *s);
/*
   initialize a istack
*/
void cpush(cstack *s, char t); /* 
	push an element to stack 
	first argument is istack pointer and second argument is element to be push
*/
char cpop(cstack *s); /*
	 pop element from stack
	 First argument is istack pointer
*/
int cisempty(cstack *s); /*
	cheak wheather a stack is empty or not 
	Return 1 when empty and 0 when not empty
*/
