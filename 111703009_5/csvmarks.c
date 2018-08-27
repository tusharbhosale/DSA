#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<stdlib.h>
int main(int arcv, char *argv[]) {
	int fd, i = 0, j = 0, x = 1, k, l, cnt = 0, c1, c2;
	char c, s1[100], s2[20], s3[10];
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("Error\n");
		return 0;
	}
	while(x != 0) {
		i = j = cnt = 0;
		while(x != 0) {
			x = read(fd, &c, 1);
			if(c == 10) {
				s1[i] = '\0';
				break;
			}
			s1[i] = c;
			i++;
		}
		for(j = 0, k = 0, l = 0; j < i; j++) {
			if(s1[j] == ',')
				cnt ++;
			if(cnt == 0) {
				s2[l] = s1[j];
				l++;
			}
			if(cnt == 2) {
				s3[k] = s1[j + 1];
				k++;
			}
		}
		s2[l] = '\0';
		s3[k] = '\0';
		c1 = atoi(s3);
		c2 = atoi(argv[2]);
		if(c1 == c2)
			printf("%s\n", s2);
	}
	close(fd);
	return 0;
}
