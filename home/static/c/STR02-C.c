/* STR02-C. Sanitize data passed to complex subsystems */

void str02_bad1(){
  char *slavename = "slave";
  char *host = "host";
  char *pam_svc_name = "svc";
  char *src = getenv("USER");
  (void) execl(LOGIN_PROGRAM, "login",
               "-p",
               "-d", slavename,
               "-h", host,
               "-s", pam_svc_name,
               src,
               0); //@violation EXECL_REVEALS_DATA //@violation OS_COMMAND_INJECTION
}

void str02_good1(){
  char *dash = "--";
  char *slavename = "slave";
  char *host = "host";
  char *pam_svc_name = "svc";

  (void) execl(LOGIN_PROGRAM, "login",
               "-p",
               "-d", slavename,
               "-h", host,
               "-s", pam_svc_name,
               dash,
               AuthenticatingUser, 0); //@violation(NOT_EXPECTED) EXECL_REVEALS_DATA
}
