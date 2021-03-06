#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<syslog.h>
#include<string.h>

int main(void)
{

	pid_t pid, sid;
	pid = fork();
	/* Forking current process and quiting parent process */
	if(pid<0)
	{
		exit(EXIT_FAILURE);
	}
	if(pid>0)
	{
		exit(EXIT_SUCCESS);
	}
	
	umask(0);
	/* Session Id from Kernel*/
	sid = setsid();
	if(sid <0)
	{
		exit(EXIT_FAILURE);
	}
	
	/* switching to root directory , using / since it is generic for almost all linux distros */
	if((chdir("/"))<0)
	{
		exit(EXIT_FAILURE);
	}
	
	/* closing all STDIN , STDOUT, STDERR to say to kernel that this piece of code is a daemon and doesnt have anything to do with User interaction */
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	/* Setting up log file  */
	
	setlogmask (LOG_UPTO (LOG_NOTICE));
	openlog ("keep_daemon", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	syslog (LOG_NOTICE, "Daemon started by User %d", getuid ());
	closelog ();
	
	while(1)
	{
	
	
		sleep(30);
	}
	
	/* When out of loop , things turn to be cool :P let the daemon sleep */ 
	exit(EXIT_SUCCESS);
	
}
