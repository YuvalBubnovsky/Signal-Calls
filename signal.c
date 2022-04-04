#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void sig_handler(int signum)
{
    int zero = 0;
    int number = 2;
	switch (signum) {

		case SIGCHLD:
			printf("Child Process Has Died! Oh No! Time To Raise Another Signal\n");
			raise(SIGUSR1); // raise a signal to the same proccess

		case SIGUSR1: 
			printf("Signal User 1! Oh No! Time For Division By Zero!\n");
			int k = number/zero; // trying to divide by zero
			printf("%d",k);

		case SIGFPE:
			printf("Floating Point Error Signal! Oh No! Well Anyway.. Try Abort!!\n");
            abort(); 

        case SIGABRT:
            printf("Abort Signal! Oh No! We're Almost Done! Time To Kill!!\n");
            kill(-1, SIGCONT); // raises a signal to a specific process

        case SIGCONT:
            printf("Aaaand We're Done!");
            exit(1);
			}
}


int main()
{
	int status;
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGFPE, sig_handler);
    signal (SIGABRT, sig_handler);
    signal (SIGCONT, sig_handler);
	if (!(fork())) {
		exit(1);
	}
	wait(&status);

}