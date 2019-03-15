#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/nanta/Downloads/Sisop-modul2/Soal_Shift_Modul_2/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    // main program here
  char *temp;
  int length, length2, i;
  char *namaBaru = "_grey.png";
  char buffer[100] = "";
  char buffer2[100] = "";
  DIR *dir;
  struct dirent *rent;
  dir = opendir(".");
  if(dir != NULL){
        while((rent = readdir(dir)) != NULL){
                length = strlen(rent->d_name);
                if(rent->d_name[length-4] == '.' && rent->d_name[length-3] == 'p' && rent->d_name[length-2] == 'n' && rent->d_name[length-1] == 'g'){
                        strcpy(buffer, rent->d_name);
                        strcpy(buffer2, rent->d_name);
                        char direktori2[100] = "/home/nanta/modul2/gambar/";
                        length2 = strlen(buffer);
                        buffer[length2-4]='\0';
                        strcat(buffer, namaBaru);
                        strcat(direktori2, buffer);
                        rename(buffer2, direktori2);
                }
        }
        closedir(dir);
  }

    sleep(30);
  }
  
  exit(EXIT_SUCCESS);
}
