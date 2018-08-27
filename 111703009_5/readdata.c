#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdlib.h>
typedef struct data {
	int age;
	char name[16];
}data;
int main(int argc, char *argv[]) {
	int fd, i, *pi, n, j;
	char c, s[50];
	data *ps;
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("Error\n");
		return errno;
	}
	read(fd, &n, sizeof(int));
	pi = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++) {
		read(fd, (pi + i), sizeof(int));
		printf("%d\n", pi[i]);
	}
	read(fd, &n, sizeof(int));
	ps  = (data *)malloc(n * sizeof(data));
	for(i = 0; i < n; i++) {
                read(fd, (ps + i), sizeof(data));
                printf("%d %s\n", ps[i].age, ps[i].name);
        }
	read(fd, &n, sizeof(int));
	for(i = 0; i < n; i++) {
		j = 0;
		while(1) {
			read(fd, &c, 1);
			s[j] = c;
			j++;
			if(c == '\0')
				break;
		}
		printf("%s\n", s);
	}
	close(fd);
	return 0;
}
