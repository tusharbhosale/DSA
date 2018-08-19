#include<stdio.h>
int removeduplicate(double a[], int n) {
	int i, j, k;
	double temp;
	if(n == 1)
		return n;
	for(i = 0; i < n; i++) {
		temp = a[i];
		for(j = 0; j < n; j++) {
			if(temp == a[j] && i != j) {
				for(k = j + 1; k < n; k++) {
					a[k-1] = a[k];
				}
				n = n - 1;
				j--;
			}
		}
	}
	return n;
}
int main() {
	int i, n;
	double a[50];
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	n = removeduplicate(a, n);
	for(i = 0; i < n; i++) {
               printf("%.15lf\n", a[i]);
        }
	return 0;
}
