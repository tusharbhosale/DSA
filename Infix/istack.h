typedef struct inode {
	int a;
	struct inode *p;
}inode;
typedef struct istack {
	inode *head, *tail;
}istack;
void iinit(istack *s);
/*
   initialize a istack
*/
void ipush(istack *s, int t); /* 
	push an element to stack 
	first argument is istack pointer and second argument is element to be push
*/
int ipop(istack *s); /*
	 pop element from stack
	 First argument is istack pointer
*/
int iisempty(istack *s); /*
	cheak wheather a stack is empty or not 
i	Return 1 when empty and 0 when not empty
*/
