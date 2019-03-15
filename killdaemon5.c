#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

int main(){
  char temp[10] = {0};
  FILE *getPID;
  getPID = popen("pidof /home/nanta/Downloads/Sisop-modul2/Soal_Shift_Modul_2/daemon5", "r");
  fgets(temp, 10, getPID);
  pid_t pid = strtoul(temp, NULL, 10);
  kill(pid, SIGKILL);
  pclose(getPID);
return 0;  
}
