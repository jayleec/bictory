#include <stdio.h>
#include <unistd.h>

void bar(){
  char *longString = "String signifying nothing";
  char shortString[16];
  
  strncpy(shortString, longString, 16); // IMPROPER_NULL_TERMINATION 
  printf("The last character in shortString is: %c %1$x\n", shortString[15]);
  return (0);
}

int main(int argc,int argv[]){
  int *pp = malloc(argv[1]); // INTEGER_OVERFLOW
  char arg[80];
  char cat[] = "cat ";
  char *command;
  int commandLength;

  sethostid(argv[2]); // alarm CONFIGURATION Setting

  fgets(arg,80,stdin);
  commandLength = strlen(cat) + strlen(arg) + 1;
  command = (char *) malloc(commandLength);
  if (command == 0) return 0;
  strncpy(command, cat, commandLength);
  strncat(command, argv[1], (commandLength - strlen(cat)) );
  system(command); // alarm OS_COMMAND_INJECTION
  free(command);
  free(pp);
  return 0;

}

