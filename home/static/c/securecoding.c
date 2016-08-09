#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FIND_DN ""
#define SQL_NTS 0
#define LDAP_SCOPE_BASE 0
#define LDAP_NO_LIMIT 0
#define RTLD_LAZY 0

extern void SQLExecDirect(int a, char* b, int c){};
extern int ldap_search_ext_s(int *a, char *b, int c,char* d,void *e, int f, void *k, void *g, int h, int i, char **j){return *a;};
extern int *ldap_simple_bind_s(int *a, char *b, char *c){return 0;};
extern int *dlopen(char *a, int b){return 0;};
extern void SQLConnect(char*a){};
extern char *verify(char *a){ return a;};
extern char *getpasswd(){return "password"; };
/* SQL Injection */
void U51000089_1(int sqlh) {
  char *query = getenv("query_string");
  SQLExecDirect(sqlh, query, SQL_NTS); //@violation SQL_INJECTION
}

/* Relative Path Traversal */
void rpt(){
  char *rName = getenv("reportName");
  char buf[30];
  char result[100];
  strcpy(result,"ABCD");
  strncpy(buf,"/home/www/tmp/",20);
  strncat(buf,rName,20);
  strcat(result,"EFG");
  strncat(result,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",3);
  unlink(buf); //@violation PATH_TRAVERSAL
}

int ldap_injection()
{
  char* filter = getenv("filter_string");
  int rc;
  int *ld = NULL;
  char* result;
  rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result); //@violation LDAP_INJECTION
  return 0;
}

#define MAX 100

int ldap_manipulation(int *ld, void *file, char *password, char *dn){
  char base[MAX];
  char manager[MAX-10];
  int rc;
  char* result;
  fgets(manager,sizeof(manager),file);
  snprintf(base, sizeof(base), "(user=%s)", manager);
  ldap_simple_bind_s(ld, manager, password);
  rc = ldap_search_ext_s( ld, base, LDAP_SCOPE_BASE, "manager=m1", NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result); //@violation LDAP_INJECTION
  return rc;
}

int ldap_safe_manipulation(int *ld, char *username, char *password, char *dn) {
  int rc;
  char * result;
  ldap_simple_bind_s(ld, username, password);
  rc = ldap_search_ext_s( ld, "ou=NewHires", LDAP_SCOPE_BASE, "manager=m1", NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result);
  return rc;
}

int resource_injection()
{
  char* rPort = getenv("rPort");
  void * serv_addr; int sockfd = 0;
  char buf[25];
  strcpy(buf, rPort); //@violation DO_NOT_ASSUME_ENV
  if (connect(sockfd,&buf,sizeof(serv_addr)) < 0) {       //@violation RESOURCE_INJECTION
    exit(1);
  }
  return 0;
}

int process_control()
{
  char *filename;
  int *handle;
  filename = getenv("SHAREDFILE");
  handle = dlopen(filename, RTLD_LAZY); //@violation PROCESS_CONTROL
  if (handle != NULL) {
    exit(1);
  }
  return 0;
}

int information_exposure(){
  char* path = getenv("MYPATH");
  char* new = malloc(100);
  sprintf(new,"%s\n",path);
  fprintf(stderr,new); //@violation INFORMATION_LEAK
  free(new);
  return 0;
}

int main(int argc, char **argv) {
  char arg[80];
  char cat[] = "cat "; char *command;
  int commandLength;
  sethostid(atol(argv[2])); //@violation CONFIGURATION_SETTING

  fgets(arg,80,stdin);
  commandLength = strlen(cat) + strlen(arg) + 1;
  command = (char *) malloc(commandLength);
  if (command == 0) return 0;
  strncpy(command, cat, commandLength);
  strncat(command, argv[1], (commandLength - strlen(cat)) );
  system(command);
  free(command);
  return 0;
}


int searchData2LDAP(void *ld, char *username){
  unsigned long rc;
  char filter[20];
  char *result;
  snprintf(filter, sizeof(filter),"(name=%s)",username);
  rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE, filter, NULL, 0, NULL,
                         NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result); //@violation IMPROPER_AUTHORIZATION
  return rc;
}
/* CONFIGURATION_SETTING.0.0.4.0 1 */
/* LEAK.MEMORY.0.0.6.0 1 */
/* OS_COMMAND_INJECTION.0.0.5.0 1 */


void * integer_overflow(int reserve){
  void *rptr;
  int size = getenv("A");
  size += reserve; //@violation INTEGER_OVERFLOW
  rptr = malloc(size * sizeof(int)); //@violation UNREASONABLE_PARAMETER //@violation INTEGER_OVERFLOW
  if(rptr == NULL)
    exit(1);
  return rptr;
}

void safe_plaintext_passwd (){
  char passwd[20];
  char *verifiedPwd;
  void *fp = fopen("config","r");
  fgets(passwd,sizeof(passwd),fp);
  fclose(fp);
  verifiedPwd = verify(passwd);
  SQLConnect(verifiedPwd);
}

void plaintext_passwd (){
  char passwd[20];
  char *verifiedPwd;
  void *fp = fopen("config","r");
  fgets(passwd,sizeof(passwd),fp);
  fclose(fp);
  verifiedPwd = passwd;
  SQLConnect(verifiedPwd); //@violation PLAINTEXT_PASSWORD
}

int hardcoded_crypt(char *passwd,int salt){
  char *cpasswd = crypt (passwd,salt);
  char *str = "68af404n513073528n63c378";
  if(strcmp(cpasswd,"68af404n513073528n63c378" )!= 0){  //@violation USE_OF_HARDCODED_CRYPTOGRAPHIC_KEY
    printf("Incorrect password \n");
    return -1;
  }
  return 0; 
}

int safe_hardcoded_crypt(char *passwd,int salt){
  char *cpasswd = crypt (passwd,salt);
  char *saved = getpasswd();
  if(strcmp(cpasswd,saved)!= 0){
    printf("Incorrect password \n");
    return -1;
  }
  return 0;
}

void ignored_return_value1() {
	char fromBuf[10], toBuf[10];
        int result, i; 
        result = 0;
        for (i=0;i<50;i++){
          result += i;
        }
        i = fgets(fromBuf, 10, stdin);
        strcpy(toBuf,fromBuf);  //@violation DO_NOT_ASSUME_ENV
}
