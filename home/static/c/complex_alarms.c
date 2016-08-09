#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern void SQLExecDirect(int a, char* b, int c){};
extern int ldap_search_ext_s(int *a, char *b, int c,char* d,void *e, int f, void *k, void *g, int h, int i, char **j){return *a;};
extern int *ldap_simple_bind_s(int *a, char *b, char *c){return 0;};
extern int *dlopen(char *a, int b){return 0;};
extern void SQLConnect(char*a){};
extern char *verify(char *a){return a;};
extern char *getpasswd(){return "aaa";};
extern void unlink(char *buf){};

struct node {
  int v;
};

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
    SQLExecDirect(sqlh,tmp,0); //@violation SQL_INJECTION
  }
}

char *global_pointer; 

void release(int a, char *buf){
  if (a > 100){
    free(buf);
  }
}

void memory_leak(int a) {
  char * buf ="";
  int result, i;
  if(a > 100){
    buf = (char *)malloc(sizeof(char) *10);
  } 
  if (buf == 0) return;
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
  return;   //@violation LEAK.MEMORY
}

char *ret_null(int a){
  if (a > 50){ return 0;}
  return "ABC";
}

void null_deref(int a) {
  char * p = ret_null(a);
  char cgi_home[100];
  if (a > 100){
    p = "SAFE";
  }
  
  if ( a > 50){
    strncpy(cgi_home, p, 100-1);
  } 
  cgi_home[100-1] = '\0';
}

void ignored_return_value() {
	char fromBuf[10], toBuf[10];
        int result, i; 
        result = 0;
        for (i=0;i<50;i++){
          result += i;
        }
        fgets(fromBuf, 10, stdin);
        strcpy(toBuf,fromBuf);  //@violation DO_NOT_ASSUME_ENV
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
    unlink(buf); //@violation PATH_TRAVERSAL
  }
}

int ldap_injection(int a)
{
  char* filter = getenv("filter_string");
  int rc;
  int *ld = 0;
  char* result;
  if(a > 100) filter = "USER"; 
  rc = ldap_search_ext_s(ld, "", 0, filter, 0, 0, 0, 0, 0, 0, &result); //@violation LDAP_INJECTION
  return 0;
}

int ldap_manipulation(int *ld, void *file, char *password, char *dn){
  char base[100];
  char manager[100-10];
  int rc,i;
  char* result;
  rc = 0;
  for(i=0;i<100/2;i++){
    rc += i + 1;
    manager[i] = 'a';
  }
  manager[i] = '0';
  if(rc > 10){
    fgets(manager,sizeof(manager),file);
  } 
  snprintf(base, sizeof(base), "(user=%s)", manager);
  ldap_simple_bind_s(ld, manager, password);
  rc = ldap_search_ext_s( ld, base, 0, "manager=m1", 0, 0, 0, 0, 0, 0, &result); //@violation LDAP_INJECTION
  return rc;
}

int ldap_safe_manipulation(int *ld, char *username, char *password, char *dn) {
  int rc;
  char * result;
  if(*ld > 20){
    ldap_simple_bind_s(ld, username, password);
  }
  rc = ldap_search_ext_s( ld, "ou=NewHires", 0, "manager=m1", 0, 0, 0, 0, 0, 0, &result);
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

int process_control(int a)
{
  char *filename = "shared";
  int *handle;
  if (a > 0){
    filename = getenv("SHAREDFILE");
  }
  handle = dlopen(filename, 0); //@violation PROCESS_CONTROL
  if (handle != 0) {
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
    fprintf(stderr,new); //@violation INFORMATION_LEAK
  }
  free(new);
  return 0;
}


int searchData2LDAP(void *ld, char *username){
  unsigned long rc;
  char filter[20];
  int manager[100];
  char *result;
  int i;
  rc = 0;
  for(i=0;i<100/2;i++){
    rc += i + 1;
    manager[i] = 'a';
  }

  snprintf(filter, sizeof(filter),"(name=%s)",username);
  rc = ldap_search_ext_s(ld, "", 0, filter, 0, 0, 0,
                         0, 0, 0, &result); //@violation IMPROPER_AUTHORIZATION
  return rc;
}
/* CONFIGURATION_SETTING.0.0.4.0 1 */
/* LEAK.MEMORY.0.0.6.0 1 */
/* OS_COMMAND_INJECTION.0.0.5.0 1 */


void * integer_overflow(int reserve){
  void *rptr;
  int size = getenv("A");
  int i=0;
  size += reserve; //@violation INTEGER_OVERFLOW
  rptr = malloc(size * sizeof(int)); //@violation UNREASONABLE_PARAMETER //@violation INTEGER_OVERFLOW
  if(rptr == 0)
    exit(1);
  return rptr;
}

void safe_plaintext_passwd (){
  char passwd[20];
  char *verifiedPwd;
  void *fp = fopen("config","r");
  int i,result=0;
  for (i=0;i<10;i++){
    result += i;
  }
  fgets(passwd,sizeof(passwd),fp);
  fclose(fp);
  verifiedPwd = verify(passwd);
  SQLConnect(verifiedPwd);
}

void plaintext_passwd (){
  char passwd[20];
  char *verifiedPwd;
  void *fp = fopen("config","r");
  int i,result=0;
  for (i=0;i<10;i++){
    result += i;
  }
  fgets(passwd,sizeof(passwd),fp);
  fclose(fp);
  verifiedPwd = passwd;
  SQLConnect(verifiedPwd); //@violation PLAINTEXT_PASSWORD
}

int hardcoded_crypt(char *passwd,int salt){
  char *cpasswd = crypt (passwd,salt);
  char *tmp = cpasswd; 
  char *str = "68af404n513073528n63c378";
  int i,result=0;
  for (i=0;i<10;i++){
    result += salt;
  }
  if(strcmp(tmp,str)!= 0 && result > salt * 2){  //@violation USE_OF_HARDCODED_CRYPTOGRAPHIC_KEY
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


int divide(int y, struct node *x){
  if(y > 0)
    return y/(x->v);
  else return 10;
}

void example1(){
  int a = 0, b = 1;
  struct node *x = malloc(sizeof(struct node));
  if(x == 0) return;
  x->v = b; 
  b = divide(a, x);
  a = b - 10;
  if(b > 0) x->v = a; 
  b = divide(b, x);  //@violation DIV_BY_ZERO 
  free(x);
  return; 
}

void buffer_access(int n, int m, int *p){
  int a;
  if (p == 0) return;
  a = n + m;

  if (a < 10){
    a = n - m;
  }
    
  p[a + n] = 10;
}

void example2(int x){
  int arr1[10];
  int arr2[20];
  int *p;
  if (x > 10){
    p = arr1;
  } else {
    p = arr2;
  }

  if (x < 10){
    buffer_access(10, -2, p);//@violation OVERRUN.STATIC
  }

  if (x > 20){
    buffer_access(10,10,p); //@violation OVERRUN.STATIC
  }
}

void os_command_injection(){
  char arg[80];
  char cat[] = "cat "; char *command;
  int commandLength;
  
  fgets(arg,80,stdin);
  commandLength = strlen(cat) + strlen(arg) + 1;
  command = (char *) malloc(commandLength);
  if (command == 0) return;
  strncpy(command, arg, commandLength);
  strncat(command, cat, (commandLength - strlen(cat)));
  system(command); //@violation OS_COMMAND_INJECTION
  free(command);
  return;
}

int main(int argc, char **argv) {
  char arg[80];
  char cat[] = "cat "; char *command;
  int commandLength;
  sethostid(atol(argv[2])); //@violation CONFIGURATION_SETTING

  return 0;
}

