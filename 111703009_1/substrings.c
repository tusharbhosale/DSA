#include<stdio.h>
#include<string.h>
int main() {
	char str[20][20], sub[15];
	int i = 0, j = 0, len1 = 0, len2 = 0, k = 0, c = 0, cnt = 0;
	for(i = 0; ; i++) {
		fgets(str[i], 10, stdin);
		cnt++;
		if(str[i][1] == '\0')
			break;
	}
	scanf("%s", sub);
	len2 = strlen(sub);
	for(i = 0; i < cnt; i++) {
		len1 = strlen(str[i]);
		for(j = 0; j < len1; j++){
			k=0;
			if(str[i][j] == sub[k]) {
				while(k < len2-1) {
					k++;
					if(str[i][j+k] == sub[k]) {
						c++;
						continue;
					}
					else {
						break;
					}
				}
				if(c == len2-1) {
					printf("%s", str[i]);
					c = 0;
					break;	
				}
			}
		}
	}

}
