#include<stdio.h>
int main() {
	int n = 0, m = 0, p = 0, i = 0, j = 0, k = 0, sum = 0;
	int m1[20][20], m2[20][20], mul[20][20];
	scanf("%d%d%d", &n, &m, &p);
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			scanf("%d", &m1[i][j]);
		}
	}
	for(i = 0; i < m; i++) {
                for(j = 0; j < p; j++) {
                        scanf("%d", &m2[i][j]);
                }
        }
	for(i = 0; i < n; i++) {
		for(j = 0; j < p; j++) {
			for(k = 0; k < m; k++) {
				sum = sum + m1[i][k] * m2[k][j];
			}
		mul[i][j] = sum;
		sum = 0;
		}
	}
	for(i = 0; i < n; i++) {
                for(j = 0; j < p; j++) {
                        printf("%d\n", mul[i][j]);
                }
        }
	return 0;
}
