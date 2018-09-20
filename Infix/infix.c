#include<stdio.h>
#include"istack.h"
#include"cstack.h"
#include <limits.h>

#define OPERAND	100
#define OPERATOR 200
#define END	300
#define ERR 400

typedef struct token{
	int type;
	int val;
	char op;
}token;
enum state { NUMBER, OP, FINISH, ERROR, SPC };
token gettoken(char *expr, int *reset) {
	static int i = 0;
	int no = 0;
	char currchar;
	static enum state currstate = SPC;
	enum state nextstate;
	token t;
	if(*reset == 1) {
		currstate = SPC;
		*reset = 0;
		i = 0;
	}
	while(1) {
		currchar = expr[i];
		//printf("currstate: %d currchar: %c\n", currstate, currchar);
		switch(currstate) {
			case NUMBER:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						nextstate = NUMBER;
						no = no * 10 + (currchar - '0');
						i++;
						break;
					case '+': case '-': case '*': case '/': case '%': case '(' : case ')' :
						nextstate = OP;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						i++;
						return t;
						break;
					default: // anything else
						nextstate = ERROR;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						return t;
						break;
				}
				break;
			case OP:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						no = currchar - '0';
						t.type = OPERATOR;
						t.op = expr[i - 1];
						nextstate = NUMBER;
						currstate = nextstate;
						//i++;
						return t;
						break;
					case '+': case '-': case '*': case '/': case '%': case '(' : case ')' :
						nextstate = OP;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;
					default: // anything else
						nextstate = ERROR;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
						break;
				}
				break;
			case FINISH:
				t.type = END;
				return t;
				break;
			case ERROR:
				t.type = ERR;
				return t;
				break;
			case SPC:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						no = currchar - '0';
						nextstate = NUMBER;
						i++;
						break;
					case '+': case '-': case '*': case '/': case '%': case '(' : case ')' :
						nextstate = OP;
						i++;
						break;
					case '\0':
						nextstate = FINISH;
						break;
					case ' ':
						nextstate = SPC;
						i++;
						break;
					default: // anything else
						nextstate = ERROR;
						break;
				}
				currstate = nextstate;
				break;
		}
	}
}
char ctop(cstack *s) {
	char ch;
	ch = cpop(s);
	cpush(s, ch);
	return ch;
}
int precedance(char o) {
	switch(o) {
		case ')' :
			return 0;
			break;
		case '+' :
		case '-' :
			return 1;
			break;
		case '*' :
		case '/' :
			return 2;
			break;
		case '%' :
			return 3;
			break;
		case '(' :
			return 4;
			break;
		default :
			return 5;
			break;
	}
	return 5;
}
int infix(char *exp) {
	token t;
	char curr_op, prev_op, ch;
	int a, b, z, cnt_ob = 0, cnt_cb = 0, reset  = 1, curr, prev;
	istack is;
	cstack cs;
	iinit(&is);
	cinit(&cs);
	prev = ERR;
	while(1) {
		t = gettoken(exp, &reset);
		curr = t.type;
		if(curr == prev && prev == OPERAND) {
			return INT_MIN;
		}
		if(t.type == OPERAND){
			ipush(&is, t.val);
		}
		else if(t.type == OPERATOR){
			curr_op = t.op;
			if(curr_op == '(')
				cnt_ob++;
			if(curr_op == ')')
				cnt_cb++;
			if(cnt_cb > cnt_ob)
				return INT_MIN;
			if(!cisempty(&cs)) {
				prev_op = ctop(&cs);
				while(precedance(prev_op) >= precedance(curr_op)) {
					prev_op = cpop(&cs);
					if(!iisempty(&is)) {
						a = ipop(&is);
					}
					else{
						cpush(&cs, prev_op);
						break;
					}
					if(!iisempty(&is)) {
						b = ipop(&is);
					}
					else {
						cpush(&cs, prev_op);
						ipush(&is, a);
						break;
					}
					if((prev_op == '/' || prev_op == '%') && a == 0) {
                                                fprintf(stderr, "Mathematical error\n");
                                                return INT_MIN;
                                        }
					switch (prev_op) {
						case '+' :
							z = b + a;
							ipush(&is, z);
							break;
						case '-' :
							z = b - a;
							ipush(&is, z);
							break;
						case '*' :
							z = b * a;
							ipush(&is, z);
							break;
						case '/' :
							z = b / a;
							ipush(&is, z);
							break;
						case '%' :
							z = b % a;
							ipush(&is, z);
							break;
						case '(' :
							cpush(&cs, prev_op);
							ipush(&is, b);
							ipush(&is, a);
							break;
						default :
							return INT_MIN;
					}
					if (prev_op == '(')
						break;
					if(!cisempty(&cs))
						prev_op = ctop(&cs);
					else
						break;
				}
			}
			cpush(&cs, t.op);
			if(curr_op == ')') {
				ch = cpop(&cs);
				cnt_cb--;
				ch = cpop(&cs);
				cnt_ob--;
			}
		}
		else if(t.type == END) {
			if(cnt_ob == cnt_cb) {
				while(!cisempty(&cs)) {
					if(!iisempty(&is)) {
						a = ipop(&is);
					}
					else {
						fprintf(stderr, "Less operands\n");
                                                return INT_MIN;
					}
					if(!iisempty(&is)) {
						b = ipop(&is);
					}
					else {
						fprintf(stderr, "Less operands\n");
                                                return INT_MIN;
					}
					ch = cpop(&cs);
					if((ch == '/' || ch == '%') && a == 0) {
						fprintf(stderr, "Mathematical error\n");
						return INT_MIN;
					}
					switch(ch) {
						case '+' :
							z = b + a;
							ipush(&is, z);
							break;
						case '-' :
							z = b - a;
							ipush(&is, z);
							break;
						case '*' :
							z = b * a;
							ipush(&is, z);
							break;
						case '/' :
							z = b / a;
							ipush(&is, z);
							break;
						case '%' :
							z = b % a;
							ipush(&is, z);
							break;
						default :
							return INT_MIN;
					}
				}
			}
			else {
				fprintf(stderr, "Error in Expression\n");
				return INT_MIN;
			}
			if(!iisempty(&is)){
				z = ipop(&is);
				if(iisempty(&is))
					return z;
				else {
                                	fprintf(stderr, "Less Operators\n");
                                	return INT_MIN;
                        	}
			}
			else {
				fprintf(stderr, "Less Operands\n");
				return INT_MIN;
			}	
		}
		else if(t.type == ERR) {
			return INT_MIN;
		}
		prev = curr;
	}
}
int readline(char *line, int len) {
	int i;
	char ch;
	i = 0;
	while(i < len - 1) {
		ch = getchar();
		if(ch == '\n') {
			line[i++] = '\0';
			return i - 1;
		}
		else
			line[i++] = ch;
	}
	line[len - 1] = '\0';
	return len - 1;
}
int main(int argc, char *argv[]) {
	int r;
	char line[128];
	while(readline(line, 128)) {
		r = infix(line);
		if(r != INT_MIN)
			printf("%d\n", r);
		else
			fprintf(stderr, "Error in expression\n");
	}
	return 0;
}
