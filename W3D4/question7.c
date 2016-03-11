#include <stdio.h>
#include <unistd.h>
#include <string.h>

int pipecircular(char *cmd[], int piped[]){
	int wt[2];
	int rd[2];
	pipe(wt);
	pipe(rd);
	int pid1;
	int pid2;
	if((pid1=fork()) == 0){
		close(wt[1]);
		dup2(wt[0] , 0);
		close(wt[0]);
		close(rd[0]);
		dup2(rd[1] , 1);
		close(rd[1]);
		execv(cmd[0], cmd);
		perror("execv failed");
		_exit(1);
	}

	if((pid2=fork()) == 0 ){
		close(wt[1]);
		dup2(wt[0] , 0);
		close(wt[0]);
		close(rd[0]);
		dup2(rd[1] , 1);
		close(rd[1]);
		_exit(1);
	}
	close(wt[0]);
	piped[1] = wt[1];
	close(rd[1]);
	piped[0] = rd[0];
	return 0;
}

int readl(int fd, char s[], int size){
	int i, r;
	for(i = 0; i < size-1; i++){
		r = read(fd, &s[i], 1);
		if(r == 0 || s[i] == '\n'){
			break;
		}
	}
	s[i+1] = '\0';
	return i;
}

#define SIZE 256

int main(){
	char test_string[] = "This is a TEST with UPPERCASE characterS\n";
	char buf[SIZE];

	char* str[2];
	str[0] = "./lowercase";
	str[1] = NULL;
	int pd[2];
	pipecircular(str, pd);
	write(pd[1], test_string, strlen(test_string));
	readl(pd[0], buf, SIZE);
	printf("Received from lowercase:\n%s", buf);
}
