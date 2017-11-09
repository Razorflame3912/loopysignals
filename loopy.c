#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>


static void sighandler(int signo){

  if(signo == SIGINT){
    int f = open("log.txt", O_CREAT | O_APPEND, 0666);
    char *s = "program exited due to SIGINT!\n";
    write(f,s,strlen(s));
    close(f);

    exit(0);
  }

  if(signo == SIGUSR1){
    printf("%d\n",getpid());
  }

}

int main(){
  umask(0);
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);

  while(1){
    printf("I am %d!\n",getpid());
    sleep(1);
  }
  
  return 0;
}
