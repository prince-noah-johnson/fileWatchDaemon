#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <sys/inotify.h>


#define EXT_SUCCESS 0
#define EXT_ERR_TOO_FEW_ARGS 1
#define EXT_ERR_INIT_INOTIFY 2

int IeventQueue = -1;

int main(int argc, char** argv) {

    char *basePath = NULL;
    char *token = NULL;

    if(argc < 2){
        fprintf(stderr, "USAGE: fileWatch PATH\n");
        exit(EXT_ERR_TOO_FEW_ARGS);
    }

    basePath = (char *)malloc(sizeof(char)*(strlen(argv[1]) + 1));
    strcpy(basePath, argv[1]);
    
    token = strtok(basePath, "/");

    while (token != NULL) {
        basePath = token;
        token = strtok(NULL, "/");
    }

    IeventQueue = inotify_init();
    if(IeventQueue == -1){
        fprintf(stderr, "Error initialising inotify instance\n");
        exit(EXT_ERR_INIT_INOTIFY);
    }

    while (true) {

    }

    

}