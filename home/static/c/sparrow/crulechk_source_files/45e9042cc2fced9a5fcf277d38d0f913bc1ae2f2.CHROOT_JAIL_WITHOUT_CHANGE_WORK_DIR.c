#include <stdio.h>

void chroot_jail_without(FILE* network) {
  FILE *localfile;
  char filename[80], buf[80];
  int len;
  chroot("/var/ftproot"); //violation @CHROOT_JAIL_WITHOUT_CHANGE_WORK_DIR
  fgets(filename, sizeof(filename), network);
  
}
