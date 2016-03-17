#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>

#define MAXLINE 40
#define MAXARG 5
#define WHITE " \n\t"

char* history[100];
int hislen = 0;
int bg = 0;
typedef enum {NORMAL, TOREDI, FROMREDI, ATOREDI, PIPEREDI} Redirection;
Redirection redi = NORMAL;

int tokenize(char *cmd, char* argv[]){
	int i = 0;
	char* tok = strtok(cmd, WHITE);
	argv[i++] = tok;
	if((strcmp(argv[i-1], "ls")) == 0){
		argv[i-1] = "/bin/ls";
	}else if ((strcmp(argv[i-1], "cat")) == 0){
		argv[i-1] = "/bin/cat";
	}else if ((strcmp(argv[i-1], "rm")) == 0){
		argv[i-1] = "/bin/rm";
	}else if ((strcmp(argv[i-1], "touch")) == 0){
		argv[i-1] = "/bin/touch";
	}
	
	redi = NORMAL;
	while (i < MAXARG && tok != NULL){
		argv[i++] = tok = strtok(NULL, WHITE);
		if(tok != NULL){
			if((strcmp(tok, ">")) == 0){
				redi = TOREDI;
			} else if ((strcmp(tok, "<")) == 0){
				redi = FROMREDI;
			} else if ((strcmp(tok, ">>")) == 0){
				redi = ATOREDI;
			} else if ((strcmp(tok, "|")) == 0){
				redi = PIPEREDI;
			}

			if((strcmp(argv[i-1], "ls")) == 0){
				argv[i-1] = "/bin/ls";
			}else if ((strcmp(argv[i-1], "cat")) == 0){
				argv[i-1] = "/bin/cat";
			}else if ((strcmp(argv[i-1], "rm")) == 0){
				argv[i-1] = "/bin/rm";
			}else if ((strcmp(argv[i-1], "touch")) == 0){
				argv[i-1] = "/bin/touch";
			}


			if((strcmp(tok, "&")) == 0){
				argv[--i] = NULL;
				bg = 1;
				return 1;
			}
		}
	}

	if(tok != NULL){
		fprintf(stderr, "More than MAXARG tokens\n");
		return 0;
	}
	return 1;

}

int background(char* argv[]){
	int id = fork();
	if(id == 0){
		execv(argv[0], argv);
		_exit(1);
	} else if (id < 0){
		fprintf(stderr, "fork failed\n");
		perror("background");
	}
	return id;
}

int main(){
	char cmd[MAXLINE+1];
	char tempcmd[MAXLINE+1];
	char* argv[MAXARG+1];
	char* argv2[MAXARG+1];
	char* got;
	int historyfind;
	char curdir[256];
	while(1){
		getcwd(curdir, 255);
		printf("mysh ready~ %s $", curdir);
		got = fgets(cmd, MAXLINE, stdin);
		if((strncmp(cmd, "\n", 1)) != 0){
			if((strncmp(cmd, "!", 1)) == 0){
				if((strncmp(cmd, "!!", 2)) == 0){
					strcpy(cmd, history[hislen-1]);
				} else {
					sscanf(cmd, "!%d", &historyfind);
					strcpy(cmd, history[historyfind-1]);
				}
			}
			char* buf = (char*) malloc (sizeof(cmd));
			strcpy(buf, cmd);
			history[hislen++] = buf;
			strcpy(tempcmd, cmd);

			if(got == NULL){
				printf("\n");
				exit(0);
			}

			bg = 0;
			if(cmd[strlen(cmd)-1] == '\n'){
				if(tokenize(cmd, argv)){
					int len = 0;
					char* s = argv[0];
					while(s != NULL){
						len++;
						s = argv[len];
					}

					if ((strcmp(argv[0], "cd")) == 0){
						if(argv[1] != NULL){
							chdir(argv[1]);
						} else {
							chdir(getenv("HOME"));
						}
					} else if ((strcmp(argv[0], "history")) == 0){
						int i;
						for(i = 0; i < hislen; i++){
							printf("%d\t%s", i+1, history[i]);
						}
					}

					if(redi == NORMAL){
						background(argv);
					} else {
						if(redi == TOREDI){
							if(fork() == 0){
								int fd = open(argv[len-1], (O_WRONLY | O_TRUNC));
								dup2(fd, 1);
								close(fd);
								argv[len-2] = NULL;
								background(argv);
								wait(NULL);
								_exit(0);
							} 	
						} else if (redi == FROMREDI){
							if(fork() == 0){
								int fd = open(argv[len-1], O_RDONLY);
								dup2(fd, 0);
								close(fd);
								argv[len-2] = NULL;
								background(argv);
								wait(NULL);
								_exit(0);
							}
						} else if (redi == ATOREDI){
							if(fork() == 0){
								int fd = open(argv[len-1], (O_WRONLY | O_APPEND));
								dup2(fd, 1);
								close(fd);
								argv[len-2] = NULL;
								background(argv);
								wait(NULL);
								_exit(0);

							}
						} else if (redi == PIPEREDI){
							char* tok1 = strtok(tempcmd, "|");
							char* tok2 = strtok(NULL, "");
							int pipechild[2];
							pipe(pipechild);
							if(fork() == 0){
								close(pipechild[0]);
								dup2(pipechild[1], 1);
								close(pipechild[1]);
								tokenize(tok1, argv);
								background(argv);
								wait(NULL);
								_exit(0);
							}

							if(fork() == 0){
								close(pipechild[1]);
								dup2(pipechild[0], 0);
								close(pipechild[0]);
								tokenize(tok2, argv2);
								background(argv2);
								wait(NULL);
								_exit(0);
							}
							wait(NULL);
							close(pipechild[0]);
							close(pipechild[1]);
						}
					}
				}

				if(bg == 0){
					wait(NULL);
				}

			} else {
				fprintf(stderr, "More than Maxline of charaters\n");
				fgets(cmd, MAXLINE, stdin);
			}
		}
	}
}
