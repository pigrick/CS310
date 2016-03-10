#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>

char buf[6];
int i = 0;

int putc2(char d, char* file){
	buf[i] = d;
	i++;
	if(i == 5){
		int fd = open(file, O_WRONLY | O_APPEND, 777);
		write(fd, buf, i);
		close(fd);
		i = 0;
	}
}


void flush(char* file){
	int fd = open(file, O_WRONLY | O_APPEND, 777);
	write(fd, buf, i);
	close(fd);
	i = 0;

}

int main(){
	putc2('a', "test.txt");
	putc2('r', "test.txt");
	putc2('e', "test.txt");
	putc2(' ', "test.txt");
	putc2('y', "test.txt");
	putc2('o', "test.txt");
	putc2('u', "test.txt");
	putc2(' ', "test.txt");
	putc2('h', "test.txt");
	putc2('a', "test.txt");
	putc2('p', "test.txt");
	putc2('p', "test.txt");
	putc2('y', "test.txt");
	putc2('!', "test.txt");
	flush("test.txt");
	putc2(' ', "test.txt");
	putc2('?', "test.txt");
	putc2('\n', "test.txt");
	flush("test.txt");
}


