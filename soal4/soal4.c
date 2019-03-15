#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

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

    char *direktori = "/home/nanta/Documents/makanan/makan_enak.txt";
    int i=1;
    while(1) {
   //main program here
    time_t atimes;
    time_t t = time(NULL);
    char *direktori2 = "/home/nanta/Documents/makanan/";
    struct stat st;
    struct tm timeInfo;
    char *namaFile = "makan_sehat";
    char *ekstensi = ".txt";
    stat(direktori, &st);
    atimes = st.st_atime; //waktu akses

    if(difftime(t, atimes)<=30)
    { char buffer[100];
      FILE *fp = NULL;
      sprintf(buffer, "%s%s%d%s", direktori2, namaFile, i, ekstensi);
      fp = fopen(buffer, "w"); 
      i++;
      fclose(fp);
    }
    sleep(5);
  }
  
  exit(EXIT_SUCCESS);
}

