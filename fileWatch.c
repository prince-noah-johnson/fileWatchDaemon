#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>


#define EXT_SUCCESS 0
#define EXT_ERR_TOO_FEW_ARGS 1

int main(int argc, char** argv) {

    char *basePath = NULL;
    char *token = NULL;

    if(argc < 2){
        fprintf(stderr, "USAGE: fileWatch PATH");
        exit(EXT_ERR_TOO_FEW_ARGS);
    }

    basePath = (char *)malloc(sizeof(char)*(strlen(argv[1]) + 1));
    strcpy(basePath, argv[1]);
    
    token = strtok(basePath, "/");

    
    exit(EXT_SUCCESS);
}