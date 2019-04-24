/* Author(s): Hoat Vu.
 *
 * This is lab9.c the csc60mshell
 * This program serves as a skeleton for doing labs 9, 10, 11.
 * Student is required to use this program to build a mini shell
 * using the specification as documented in direction.
 * Date: Spring 2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* Define Section */
#define MAXLINE 80
#define MAXARGS 20
#define MAX_PATH_LENGTH 50
#define TRUE 1

/* function prototypes */
int parseline(char *cmdline, char **argv);

//The two function prototypes below will be needed in lab10. 
//Leave them here to be used later.
/* void process_input(int argc, char **argv); */
/* void handle_redir(int argc, char *argv[]); */

/* ----------------------------------------------------------------- */
/*                  The main program starts here                     */
/* ----------------------------------------------------------------- */
int main(void)
{
    char cmdline[MAXLINE];
    char *argv[MAXARGS];
    int argc;
    int status;
    pid_t pid;
	int i;

    /* Loop forever to wait and process commands */
    while (TRUE) {	
		/* Print your shell name: csc60msh (m for mini shell) */
		printf("HoatVu_csc60msh> ");

		/* Read the command line */
		fgets(cmdline, MAXLINE, stdin);

		/* Call parseline to build argc/argv */
		argc = parseline(cmdline, argv);

		//print out how many argc have entered
		printf("Argc = %i\n", argc);
		
		//list out the argv that the user entered
		for (i = 0; i < argc; i++)
		{
			printf("Argv %i = %s\n", i, argv[i]);
		}
		
		
		/* again at the beginning */
		/*  Hint: if argc is zero, no command declared */
		/*  Hint: look up for the keyword "continue" in C */

		/* Handle build-in command: exit, pwd, or cd  */
		/* Put the rest of your code here */
		
		/* If user hits enter or space key without a command, continue to loop */
		if (argc == 0)
		{
			continue;
		}
		
		//compare the hitting key with some default command using the strcmp() 
		//execute the the command and display the path 
		if (strcmp(argv[0], "exit") == 0) 
		{
			exit(EXIT_SUCCESS);//if the exit command hit, then execute exit_success
		} 
		else if (strcmp(argv[0], "pwd") == 0)
		{
			char path[MAX_PATH_LENGTH];
			
			//check if the getcwd null or a path 
			if (getcwd(path, MAX_PATH_LENGTH) == NULL)
			{
				perror("getcwd() error");//if null, then error message show up
			}

			printf("%s\n", path);//print the path that was saved in the the array path. 
			
			continue;//continue the loop
		}
		//changing directory usually combines with other command or directory, so when the key was hit
		//this script will check if cd is not the only key that was entered by the user. It will return
		//home if there is only cd, but it will change however it suppose to be if there is more than 
		//1 argc using the chdir()
		else if (strcmp(argv[0], "cd") == 0) 
		{
			char *dir;
			
			if (argc == 1)
			{
				dir = getenv("HOME");
			}
			else 
			{
				dir = argv[1];
			}
			
			
			//execute and checking error at the same time, can't do separately because
			//it will lead to execute the command two time. It's will give same result 
			//with many other command, but cd .. will give the wrong result when the 
			//cd .. was execute two time, lead to escape two time instead of one. 
			if (chdir(dir) != 0)
			{
				perror("Error changing directory\n");
			}
			continue;	
		}


	 
	//.......................IGNORE........................	
	//	/* Else, fork off a process */
	//      else {
	//	    pid = fork();
	//          switch(pid)
	//    	    {
	//	    	case -1:
	//		    perror("Shell Program fork error");
	//	            exit(EXIT_FAILURE);
	//	   	case 0:
	//		    /* I am child process. I will execute the command, */
	//		    /* and call: execvp */
	//		    process_input(argc, argv);
	//		    break;
	//	   	default:
	//		    /* I am parent process */
	//		    if (wait(&status) == -1)
	//		    	perror("Parent Process error");
	//		    else
	//		   	printf("Child returned status: %d\n",status);
	//		    break;
	//	    } 	/* end of the switch */
	//	}	/* end of the if-else-if */
	//...end of the IGNORE above.........................
    }		/* end of the while */
} 		/* end of main */

/* ----------------------------------------------------------------- */
/*                  parseline                                        */
/* ----------------------------------------------------------------- */
/* parse input line into argc/argv format */

int parseline(char *cmdline, char **argv)
{
    int count = 0;
    char *separator = " \n\t"; /* Includes space, Enter, Tab */
 
    /* strtok searches for the characters listed in separator */
    argv[count] = strtok(cmdline, separator);

    while ((argv[count] != NULL) && (count+1 < MAXARGS)) 
    	argv[++count] = strtok((char *) 0, separator);
     		
    return count;  //This becomes "argc" back in main.
}
/* ----------------------------------------------------------------- */
/*                  process_input                                    */
/* ----------------------------------------------------------------- */
/*void process_input(int argc, char **argv) {                       */

    /* Step 1: Call handle_redir to deal with operators:            */
    /* < , or  >, or both                                           */


    /* Step 2: perform system call execvp to execute command        */
    /* Hint: Please be sure to review execvp.c sample program       */
    /* if (........ == -1) {                                        */
    /*    fprintf(stderr, "Error on the exec call\n");              */
    /*    _exit(EXIT_FAILURE);                                      */
    /* }                                                            */
 
// }
/* ----------------------------------------------------------------- */
//void handle_redir(int count, char *argv[])
/* ----------------------------------------------------------------- */


/* ----------------------------------------------------------------- */
