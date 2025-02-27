
/**
 * Assignment 2: Simple UNIX Shell
 * @file pcbtable.h
 * @author Jaiden Camp
 * @brief This is the main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

#define MAX_LINE 80 // The maximum length command

/**
 * @brief parse out the command and arguments from the input command separated by spaces
 *
 * @param command
 * @param args
 * @return int
 */
int parse_command(char command[], char *args[])
{
    int i = 0;
    char *token; 
    token = strtok(command, " "); //takes first part of the command

    while (token != NULL){
        args[i] = token; //stores token into args
        i++; 
        token = strtok(NULL, " "); 
    }
    args[i] = NULL; //sets last element to NULL
    return i; 
}

// TODO: Add additional functions if you need

/**
 * @brief The main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @param argc The number of arguments
 * @param argv The array of arguments
 * @return The exit status of the program
 */
int main(int argc, char *argv[])
{
    char command[MAX_LINE];       // the command that was entered
    char *args[MAX_LINE / 2 + 1]; // hold parsed out command line arguments
    int should_run = 1;           /* flag to determine when to exit program */

    // TODO: Add additional variables for the implementation.

    while (should_run)
    {
        printf("osh>"); //prints what shell is accessing
        fflush(stdout); //Ensures nothing is in the buffer
     
        fgets(command, MAX_LINE, stdin); //reads the command from the user input
     
        int num_args = parse_command(command, args); //Parses user command

        pid_t pid = fork(); //forks the process

        //ensuring fork was successful
        if (pid < 0){printf("Fork failed \n") ; return 1;}
        else {printf("Process ID is: %d", pid);}
        

        // TODO: Add your code for the implementation
        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) parent will invoke wait() unless command included &
         */
    }
    return 0;
}
