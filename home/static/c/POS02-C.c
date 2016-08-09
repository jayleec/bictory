/*  Code with elevated privileges  */
 
int establish(void) {
  struct sockaddr_in sa; /* listening socket's address */
  int s = 100; /* listening socket */
 
  /* Fill up the structure with address and port number */
 
  sa.sin_port = htons(portnum);
 
  /* Other system calls like socket() */
 
  if (bind(s, (struct sockaddr *)&sa,
        sizeof(struct sockaddr_in)) < 0) {
    /* Perform cleanup */
  }
 
  /* Return */
  return 1;
}
 
int main(void) {
  int s = establish();
 
  /* Drop privileges permanently */
  if (setuid(getuid()) == -1) {
     /*  Handle the error  */
  }
 
  if (setuid(0) != -1) {
    /* Privileges can be restored, handle error */
  }
 
  /* Block with accept() until a client connects */
 
  switch (fork()) {
     case -1: /* Error, clean up and quit */
     case  0: /* Close all open file descriptors
               * This is the child, handle the client
               */
       return 0;
     default: /* This is the parent, continue blocking */
       return 1;
  }
}

/*  Code with elevated privileges  */
 
int establish_good(void) {
  struct sockaddr_in sa; /* listening socket's address */
  int s = 100; /* listening socket */
 
  /* Fill up the structure with address and port number */
 
  sa.sin_port = htons(portnum);
 
  /* Other system calls like socket() */
 
  if (bind(s, (struct sockaddr *)&sa,
        sizeof(struct sockaddr_in)) < 0) {
    /* Perform cleanup */
  }
 
  /* Return */
  return 1;
}
 
int main_good(void) {
  int s = establish_good();
 
  /* Drop privileges permanently */
  if (setuid(getuid()) == -1) {
     /*  Handle the error  */
  }
 
  if (setuid(0) != -1) {
    /* Privileges can be restored, handle error */
  }
 
  /* Block with accept() until a client connects */
 
  switch (fork()) {
    case -1: /* Error, clean up and quit */
    case  0: /* Close all open file descriptors
              * This is the child, handle the client
              */
      return 0;
    default: /* This is the parent, continue blocking */
      return 1;
  }
  return 0;
}
