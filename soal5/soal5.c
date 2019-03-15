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

  while(1) {
    // main program here
     time_t t = time(NULL);
     struct tm tm = *localtime(&t);
     char nama[50];
     char direktori[50] = "/home/nanta/log/";
     char *namaFile  = "log";
     char *ekstensi = ".log";
     mkdir(direktori, 0777);
     // printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon +1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
     sprintf(nama, "%d:%d:%d-%d:%d/", tm.tm_mday, tm.tm_mon +1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
     //printf("%s\n", nama);
     strcat(direktori, nama);
     mkdir(direktori, 00777);

     int k = 1, count;
     FILE *log = NULL, *syslog;
     char name_buffer[100], ch;
     while(k < 31){
         sprintf(name_buffer, "%s%s%d%s", direktori, namaFile, k, ekstensi);
         log = fopen(name_buffer, "w");
         syslog = fopen("/var/log/syslog", "r");
         fseek(syslog, 0L, SEEK_END);
         count = ftell(syslog);
         fseek(syslog, 0L, SEEK_SET);
         while(count--){
           ch = fgetc(syslog);
           fputc(ch, log);
         }
         k++;
         fclose(log);
         fclose(syslog);
         sleep(60);
     }
  }
  
  exit(EXIT_SUCCESS);
}

