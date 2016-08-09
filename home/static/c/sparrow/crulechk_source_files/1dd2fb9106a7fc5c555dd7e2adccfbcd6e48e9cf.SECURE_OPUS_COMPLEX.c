#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FIND_DN ""
#define SQL_NTS 0
#define LDAP_SCOPE_BASE 0
#define LDAP_NO_LIMIT 0
#define RTLD_LAZY 0
#define BUFSIZE 100

extern void SQLExecDirect(int a, char* b, int c){};
extern int ldap_search_ext_s(int *a, char *b, int c,char* d,void *e, int f, void *k, void *g, int h, int i, char **j){return *a;};
extern int *ldap_simple_bind_s(int *a, char *b, char *c){return 0;};
extern int *dlopen(char *a, int b){return 0;};
extern void SQLConnect(char*a){};
extern char *verify(char *a){return a;};
extern char *getpasswd(){return 'c';};
/* SQL Injection */
void U51000089_1(int sqlh) {
  char *query = getenv("query_string");
  char *tmp = "Safe";
  int result, i;
  if(sqlh > 100) {
    tmp = query;
    result = 0;
  } else {
    result = 50;
  }
  for (i=0;i<50;i++){
    result += i;
  }
  if(sqlh > 0){
    SQLExecDirect(sqlh,tmp,SQL_NTS); // alarm SQL_INJECTION
  }
}

char *global_pointer; 

void release(int a, char *buf){
  if (a > 100){
    free(buf);
  }
}

void memory_leak(int a) {
  char * buf;
  int result, i;
  if(a > 100){
    buf = (char *)malloc(sizeof(char) *10);
  } 
  *buf = 100;
  result = 1000;
  for (i=0;i<50;i++){
    result += i;
  }
  if(a > 100 && a < 200){
    global_pointer = buf;
  } else if (a > 200){
    release(a, buf);
  }
  // Memory Leak when the value of parameter "a" is 200 
}

char *ret_null(int a){
  if (a > 50){ return 0;}
  return "ABC";
}

void null_deref(int a) {
  char * p = ret_null(a);
  char cgi_home[BUFSIZE];
  if (a > 100){
    p = "SAFE";
  }
  
  if ( a > 50){
    strncpy(cgi_home, p, BUFSIZE-1);
  } 
  cgi_home[BUFSIZE-1] = '\0';
}

/* Relative Path Traversal */
void rpt(int a){
  char *rName = getenv("reportName");
  char buf[30];
  char result[100];
  strcpy(result,"ABCD");
  strncpy(buf,"/home/www/tmp/",20);
  if (a > 100){
    strncat(buf,rName,20);
  }
  strcat(result,"EFG");
  strncat(result,"ThisIsMeaninglessDontCare",3);
  if (a > 50){
    unlink(buf); // alarm PATH_TRAVERSAL
  }
}

int ldap_injection(int a)
{
  char* filter = getenv("filter_string");
  int rc;
  int *ld = NULL;
  char* result;
  if(a > 100) filter = "USER"; 
  rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE, filter, NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result); // alarm LDAP_INJECTION
  return 0;
}

#define MAX 100

int ldap_manipulation(int *ld, void *file, char *password, char *dn){
  char base[MAX];
  char manager[MAX-10];
  int rc,i,n;
  char* result;
  rc = 0;
  for(i=0;i<MAX/2;i++){
    rc += i + 1;
    manager[i] = 'a';
  }
  manager[i] = '0';
  if(rc > 10){
    n = fgets(manager,sizeof(manager),file);
  } 
  if (n == 0) return 0;
  n = snprintf(base, sizeof(base), "(user=%s)", manager);
  if (n < 0) return 0;
  ldap_simple_bind_s(ld, manager, password);
  rc = ldap_search_ext_s( ld, base, LDAP_SCOPE_BASE, "manager=m1", NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result); // alarm LDAP_INJECTION
  return rc;
}

int ldap_safe_manipulation(int *ld, char *username, char *password, char *dn) {
  int rc;
  char * result;
  if(*ld > 20){
    ldap_simple_bind_s(ld, username, password);
  }
  rc = ldap_search_ext_s( ld, "ou=NewHires", LDAP_SCOPE_BASE, "manager=m1", NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result);
  return rc;
}

int resource_injection()
{
  char* rPort = getenv("rPort");
  void * serv_addr; int sockfd = 0;
  char buf[25];
  strcpy(buf, rPort); // alarm DO_NOT_ASSUME_ENV
  if (connect(sockfd,&buf,sizeof(serv_addr)) < 0) {       // alarm RESOURCE_INJECTION
    exit(1);
  }
  return 0;
}

int process_control(int a)
{
  char *filename = "shared";
  int *handle;
  if (a > 0){
    filename = getenv("SHAREDFILE");
  }
  handle = dlopen(filename, RTLD_LAZY); // alarm PROCESS_CONTROL
  if (handle != NULL) {
    exit(1);
  }
  return 0;
}

int information_exposure(int a){
  char* path = getenv("MYPATH");
  char* new = malloc(100);
  if(new == 0) return 1;
  if(a > 100){
    sprintf(new,"%s\n",path);
  } else {
    memset(new,0,99);
  }
  if(2*a > 150){
    fprintf(stderr,new); // alarm Information Leak
  }
  free(new);
  return 0;
}

int main(int argc, char **argv) {
  char arg[80];
  char cat[] = "cat "; char *command;
  int commandLength;
  sethostid(atol(argv[2])); // alarm CONFIGURATION Setting

  fgets(arg,80,stdin);
  commandLength = strlen(cat) + strlen(arg) + 1;
  command = (char *) malloc(commandLength);
  if (command == 0) return 0;
  strncpy(command, cat, commandLength);
  strncat(command, argv[1], (commandLength - strlen(cat)) );
  system(command); // alarm OS_COMMAND_INJECTION
  free(command);
  printf("This is a debug code: %d", argc); // @violation LEFTOVER_DEBUG_CODE
  return 0;
}


int searchData2LDAP(void *ld, char *username){
  unsigned long rc;
  char filter[20];
  char *result;
  rc = 0;
  int i;
  for(i=0;i<MAX/2;i++){
    rc += i + 1;
  }

  snprintf(filter, sizeof(filter),"(name=%s)",username); // alarm IGNORED_RETURN VALUE
  rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE, filter, NULL, 0, NULL,
                         NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result);
  return rc;
}
/* CONFIGURATION_SETTING.0.0.4.0 1 */
/* LEAK.MEMORY.0.0.6.0 1 */
/* OS_COMMAND_INJECTION.0.0.5.0 1 */


void * integer_overflow(int reserve){
  void *rptr;
  int size = getenv("A");
  size += reserve;
  rptr = malloc(size * sizeof(int)); // Integer Overflow
  if(rptr == NULL)
    exit(1);
  return rptr;
}

void * safe_integer_overflow(int reserve){
  void *rptr;
  unsigned s;
  int size = getenv("B");
  size += reserve;
  s = size * sizeof(int);
  if (s<0) return NULL;
  rptr = malloc(s);
  if(rptr == NULL)
    exit(1);
  return rptr;
}

void safe_plaintext_passwd (){
  char passwd[20];
  char *verifiedPwd;
  void *fp = fopen("config","r");
  int i,n,result=0;
  for (i=0;i<10;i++){
    result += i;
  }
  if(fgets(passwd,sizeof(passwd),fp) == 0) return;
  fclose(fp);
  verifiedPwd = verify(passwd);
  SQLConnect(verifiedPwd);
}

void plaintext_passwd (){
  char passwd[20];
  char *verifiedPwd;
  void *fp = fopen("config","r");
  int i,n,result=0;
  for (i=0;i<10;i++){
    result += i;
  }
  n = fgets(passwd,sizeof(passwd),fp);
  if (n == 0) return;
  fclose(fp);
  verifiedPwd = passwd;
  SQLConnect(verifiedPwd); // alarm PLAINTEXT_PASSWORD
}

int hardcoded_crypt(char *passwd,int salt){
  char *cpasswd = crypt (passwd,salt);
  char *tmp = cpasswd; 
  char *str = "68af404n513073528n63c378";
  int i,result=0;
  for (i=0;i<10;i++){
    result += salt;
  }
  if(strcmp(tmp,str)!= 0 && result > salt * 2){  // alarm USE_OF_HARDCODED_CRYPTOGRAPHIC_KEY
    printf("Incorrect password \n");
    return -1;
  }
  return 0; 
}

int safe_hardcoded_crypt(char *passwd,int salt){
  char *cpasswd = crypt (passwd,salt);
  char *saved = getpasswd();
  int i,result=0;
  for (i=0;i<10;i++){
    result += salt;
  }
  if(strcmp(cpasswd,saved)!= 0 && result > salt * 5 ){
    printf("Incorrect password \n");
    return -1;
  }
  return 0;
}

void unexpected_sign_extension2( int __2354_37_size) {
auto char __2355_8_buf[10];
auto char *__2356_9_p;
auto unsigned __2357_16_x;
__2356_9_p = (__2355_8_buf);


if (__2354_37_size < 0) __2357_16_x = ((unsigned)__2354_37_size);

if (__2354_37_size > 10) {
__2356_9_p = ((char *)(malloc(((unsigned)__2354_37_size))));
free(((void *)__2356_9_p));
}

if (__2354_37_size < 10) {
__2356_9_p = ((char *)(malloc(((unsigned)__2354_37_size))));
free(((void *)__2356_9_p));
} 
}

void unexpected_sign_extension (int size) {
  char buf[10];
  char *p = buf;
  unsigned int x; 

  if(size < 0) x = size; // alarm Unexpected Sign Extension 

  if(size > 10){
    p = (char*) malloc((unsigned int) size);
    free(p);
  }

  if(size < 10){
    p = (char*) malloc((unsigned int) size);
    free(p);
  }
}

void test_strcpy() {
    char*a = malloc(5);
    if(a == 0) return;
 
    char buf[20];
    strcpy(a, buf); // alarm OVERRUN.DYNAMIC.STRCPY
    free(a);
    return;
}
 
void* aux_test_extreme(int* buf, char n) {
    buf[n+2] = 0;
 
    return buf;
}

void test_extreme() {
    char* a;
 
    a = malloc(12);
    if(a == 0) return;
 
    aux_test_extreme(a, 4); // alarm OVERRUN.DYNAMIC
    free(a);
    return 0;
}
