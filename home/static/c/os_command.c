#include <stdio.h>

int main(int argc, char **argv){
    char arg[80];
    char cat[] = "cat";
    char *command;
    size_t commandLength;
    fgets(arg, 80, stdin);
    commandLength = strlen(cat) + strlen(arg) + 1;
    command = (char *) malloc(commandLength);
    strncpy(command, argv[1], (commandLength - strlen(cat)));
    system(command); // OS_COMMAND_INJECTION
    return 0;
}

