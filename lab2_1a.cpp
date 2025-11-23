#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // for exit()
#include <wait.h>   // for wait()

int main(){
	pid_t  pid,pid2;

	pid = fork();  //Fork a child process

        if(pid < 0){ //Fork error
		fprintf(stderr,"Fork failed.\n");
                exit(-1);
        }
        else if(pid==0){ // This is the path of child process
/////////////////// Process B //////////////////////
            for(int i=0;i<10;i++){
                printf("J:%d\n",i);
                sleep(1);
            }
////////////////////////////////////////////////////
        }
	else { // This is the path of parent process
        pid2=fork();
        if(pid2==0){ // This is the path of second child process
/////////////////// Process C //////////////////////
            for(int i=0;i<10;i++){
                printf("K:%d\n",i);
                sleep(1);
            }
////////////////////////////////////////////////////
        }else{
//////////////////// Process A /////////////////////
            for(int i=0;i<10;i++){
                printf("I:%d\n",i);
                sleep(1);
            }
////////////////////////////////////////////////////
            waitpid(pid,NULL,0);
	        waitpid(pid2,NULL,0);
	        printf("Child processes have terminated\n");
            exit(0);
        }
    }
    return 0;
}
