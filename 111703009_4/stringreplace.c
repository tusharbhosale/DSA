#include<stdio.h>
#include<string.h>
int stringreplace(char *text, char *orig, char *new) {
	char s1[100], s2[100];
	int i = 0, j = 0, k = 0, c = 0, flag = 0, replace_cnt = 0, len_o = 0;
	len_o = strlen(orig);
	while(flag != -1) {
		i = 0;
		while(text[i] != '\0') {
			c = j = 1;
			if(text[i] == orig[0]) {
				while(c < len_o) {
					if(text[i + c] == orig[c]) 
						j++;
					else
						break;
					c++;
				}
				if(j == len_o) {
					flag = 1;
					replace_cnt++;
					break;
				}
			}
			i++;
			flag = -1;
		}
		if(flag == 1) {
			for(k = 0; k < i; k++)
				s1[k] = text[k];
			s1[k] = '\0';
			for(c = 0, k = i + j; text[k] != '\0'; k++) {
				s2[c] = text[k];
				c++;
			}
			s2[c] = '\0';
		}
		if(flag == 1) {
			c = 0;
			for(k = 0; s1[k] != '\0'; k++) {
				text[c] = s1[k];
				c++;
			}
			for(k = 0; new[k] != '\0'; k++) {
				text[c] = new[k];
				c++;
			}
			for(k = 0; s2[k] != '\0'; k++) {
				text[c] = s2[k];
				c++;
			}
			text[c] = '\0';
		}
	}
	return replace_cnt;
}
int main() {
	char text[128], orig[128], new[128];
	int count = 0;
	while(scanf("%s%s%s", text, orig, new) != -1) {
		count = stringreplace(text, orig, new);
		printf("%d %s\n", count, text);
	}
	return 0;
}
