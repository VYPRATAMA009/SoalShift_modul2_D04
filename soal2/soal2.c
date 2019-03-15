#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

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
    char *direktori="/home/nanta/Downloads/Sisop-modul2/Soal_Shift_Modul_2/hatiku/elen.ku";
    char *nama="www-data";
    struct stat info;
    chmod (direktori, 0777);
    //char *elen = "elen.ku";
    //strcat(direktori, elen);
    stat(direktori, &info);  // Error check omitted
    struct passwd *ow = getpwuid(info.st_uid);
    struct group  *gr = getgrgid(info.st_gid);
    if(strcmp(ow->pw_name,nama)==0 && strcmp(gr->gr_name,nama)==0)
      remove(direktori);
    sleep(3);
  }

  exit(EXIT_SUCCESS);
}

