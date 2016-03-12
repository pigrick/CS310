#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int ab[2];
	pipe(ab);
	char buf[20];
	char*buf2;
	
	if(fork() == 0){
		read(ab[0], buf, 19);
		close(ab[0]);
		float num1= atof(strtok(buf, " \t"));
		printf("%f\n", num1);
		char* operation = strtok(NULL, " \t");
		char* num2 = strtok(NULL, " \t");
		float result = 0;

		switch(operation[0]){
			case '+':
				result = atof(num1) + atof(num2);
				break;
			case '-':
				result = atof(num1) - atof(num2);
				break;
			case '*':
				result = atof(num1) * atof(num2);
				break;
			case '/':
				result = atof(num1) + atof(num2);
				break;
			default:
				result -1;
				break;
		}
		char ans[20];
		sprintf(ans, "%f", result);
		printf("%s\n", ans);
		write(ab[1], ans, 19);
		close(ab[1]);
		_exit(0);
	}
	if(argc != 4){
		fprintf(stderr, "Need 2 numbers and a operation");
	}
	sprintf(buf,"%s %s %s", argv[1], argv[2], argv[3]);
	write(ab[1], buf, 19);
	close(ab[1]);
	wait(NULL);
	read(ab[0], buf, 19);
	close(ab[0]);
	printf("%s\n", buf);

}	
