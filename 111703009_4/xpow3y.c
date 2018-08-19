#include <stdio.h>
#include <math.h>
double pow_fun(int x, int y) {
	double prod, term;
	int sign;
	sign = 0;
	if(x == 0 && y == 0) {
		return NAN; 
	}
	if(y < 0) {
		sign = 1;
		y = -y;
	}
	prod = 1.0;
	term  = (double) x;
	while(y > 0) {
		if(y % 3 == 1) 
			prod = prod * term;
		if(y % 3 == 2)
			prod = prod * term * term;
		term  = term  * term  * term;
		y = y / 3;	
	}
	if(sign == 1) 
		prod = 1.0 / prod;
	return prod;
}
int main() {
	int x, y;
	double pow;
	while(scanf("%d%d", &x, &y) != -1) {
		pow = pow_fun(x, y);
		printf("%lf\n", pow);
	}
	return 0;
}
