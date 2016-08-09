// @checker BAD_PRIVILEGE_RELINQUISHMENT

#define RC_NRM 0 
#define RC_ERR -1 

int setuid(int);
int setgid(int);
int getuid();
int getgid();

void func() {
	if(setuid(getuid()) == -1){ 
	   /* error handling */ 
	} 
	if(setgid(getgid()) == -1){ // @violation BAD_PRIVILEGE_RELINQUISHMENT
	   /* error handling */ 
	}
}
