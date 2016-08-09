// @checker SECURITY_DECISION_ON_DNS_LOOKUP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <netdb.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

#define AF_INET      0

struct in_addr {
  int dummy;
};


struct hostent {
  char* h_name;
};

extern struct hostent * gethostbyaddr(char *, unsigned int, int);

int decision(char * ip_addr_string) {
	struct hostent * hp;
	struct hostent * hpClone;
	struct in_addr myaddr;	
	char * tHost = "trustme.trysty.com";
	
	hp = (struct hostent *)gethostbyaddr((char *)&myaddr, sizeof(struct in_addr), AF_INET);
	char * cloneName;
	hpClone = hp;
	cloneName = hp->h_name;
	if(hp && !strncmp(hp->h_name, tHost, sizeof(tHost))) { // @violation SECURITY_DECISION_ON_DNS_LOOKUP
		return 1;
	} else if(hp && !strncmp(cloneName, tHost, sizeof(tHost))) { // @violation SECURITY_DECISION_ON_DNS_LOOKUP
		return 0;
	} else if(hpClone && !strncmp(hpClone->h_name, tHost, sizeof(tHost))) { // @violation SECURITY_DECISION_ON_DNS_LOOKUP
		return -1;
	}
}

int decision2(char * ip_addr_string) {
	struct hostent * hp;
	struct hostent * hpClone;
	struct in_addr myaddr;	
	char * tHost = "trustme.trysty.com";
	
	hp = (struct hostent *)gethostbyaddr((char *)&myaddr, sizeof(struct in_addr), AF_INET);
	char * cloneName;
	
	hpClone = NULL;
	
	if(ip_addr_string == NULL) {
		hpClone = hp;
	} else {
		if(hpClone && !strncmp(hpClone->h_name, tHost, sizeof(tHost))) {
			return -1;
		}
	}
}

