#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
using namespace std; 

int main(){
    char command[50]; 

    printf("Testing array in C\n");
    fflush(stdout);

    fgets(command, 50, stdin);

    char *token; 
    token = strtok(command, " ");

    while (token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return 0;
}
