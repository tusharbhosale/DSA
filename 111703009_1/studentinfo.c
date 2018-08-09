#include<stdio.h>
#include<string.h>
struct student {
	char name[16];
	int age;
	double  mark;
}info[50];
int main() {
	int i = 0, j = 0, c = 0;
	char search[16];
	for(i = 0; ; i++) {
		scanf("%s%d%lf", info[i].name, &info[i].age, &info[i].mark);
		c++;
		if(info[i].age == -1){
			break;
		}
	}
	scanf("%s", search);
	for(i = 0; i < c; i++) {
		j = strcmp(info[i].name, search);
		if(j == 0) {
			printf("%s %d %lf\n", info[i].name, info[i].age, info[i].mark);
		}
	}
	return 0;

}
