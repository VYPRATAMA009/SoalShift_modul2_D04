#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main(){
	pid_t child_id, child2_id, child3_id;
	int status, pipefd[4];
	char c[1000];

    	child_id = fork();

    	if(child_id == 0){
		char *argv[3] = {"unzip", "campur2.zip", NULL};
      		execv("/usr/bin/unzip", argv);
    	}else{
		while(wait(&status)>0);
        	pipe(pipefd);
       	 	pipe(pipefd+2);

        	child2_id = fork();

        	if(child2_id == 0){
          		close(pipefd[0]);
          		close(pipefd[2]);
          		close(pipefd[3]);
          		dup2(pipefd[1], STDOUT_FILENO);
          		close(pipefd[1]);

          		char *argv[3] = {"ls", "campur2", NULL};
	  		execv("/bin/ls", argv);
        	}else{

            		child3_id = fork();

            		if(child3_id == 0){
              			close(pipefd[1]);
              			dup2(pipefd[0],STDIN_FILENO);
              			close(pipefd[0]);
              			close(pipefd[2]);
              			dup2(pipefd[3],STDOUT_FILENO);
              			close(pipefd[3]);
	      			char *argv[3] = {"grep", ".txt$", NULL};
              			execv("/bin/grep", argv);
            		}else{
              			close(pipefd[1]);
              			close(pipefd[0]);
              			close(pipefd[3]);
              			int r = read(pipefd[2], c, sizeof(c));
              			close(pipefd[2]);

				FILE* fp;
              			fp = fopen("daftar.txt","w+");
              			fputs(c, fp);
              			fclose(fp);
            		}
        	}
    	}
}
