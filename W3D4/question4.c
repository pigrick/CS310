#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>



int fdpopen(char* cmd, int access, char* argv[]){
	int fd = open(cmd, access);
	execv(cmd, argv);
	return fd;
}

int main(){
	int main(int argc, char* argv[]){
		char cmd[80];
		int count = 0;
		int total = 0;
		int fd;
		int i;
		for(i = 1; i < argc; i++){
			sprintf(cmd, "wc -w %s\n", argv[i]);
			fd = fdpopen(cmd, 0x0000, argv);
			count = (int) read(fd, stdin, sizeof(stdin));
			total += count;
			close(fd);
		}
		printf("total count is %d words\n", total);
	}
}
