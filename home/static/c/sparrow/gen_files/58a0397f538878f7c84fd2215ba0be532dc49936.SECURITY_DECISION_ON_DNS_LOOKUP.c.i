/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/SECURITY_DECISION_ON_DNS_LOOKUP.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 12 "/home/kskyj/sparrow4/util/testcode/c/SECURITY_DECISION_ON_DNS_LOOKUP.c"
struct in_addr;




struct hostent; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 12 "/home/kskyj/sparrow4/util/testcode/c/SECURITY_DECISION_ON_DNS_LOOKUP.c"
struct in_addr {
int dummy;};



struct hostent {
char *h_name;};
#line 145 "/usr/include/string.h"
extern int strncmp(const char *__s1, const char *__s2, size_t __n);
#line 21 "/home/kskyj/sparrow4/util/testcode/c/SECURITY_DECISION_ON_DNS_LOOKUP.c"
extern struct hostent *gethostbyaddr(char *, unsigned, int);

extern int decision(char *ip_addr_string);
#line 42
extern int decision2(char *ip_addr_string);
#line 23
int decision( char *__2067_21_ip_addr_string) {
auto struct hostent *__2068_19_hp;
auto struct hostent *__2069_19_hpClone;
auto struct in_addr __2070_17_myaddr;
auto char *__2071_9_tHost = "trustme.trysty.com";


auto char *__2074_9_cloneName;
#line 29
__2068_19_hp = ((struct hostent *)(gethostbyaddr(((char *)(&__2070_17_myaddr)), 4U, 0)));

__2069_19_hpClone = __2068_19_hp;
__2074_9_cloneName = (__2068_19_hp->h_name);
if ((__2068_19_hp) && (!(strncmp(((const char *)(__2068_19_hp->h_name)), ((const char *)__2071_9_tHost), 4U)))) {
return 1;
} else  if ((__2068_19_hp) && (!(strncmp(((const char *)__2074_9_cloneName), ((const char *)__2071_9_tHost), 4U)))) {
return 0;
} else  if ((__2069_19_hpClone) && (!(strncmp(((const char *)(__2069_19_hpClone->h_name)), ((const char *)__2071_9_tHost), 4U)))) {
return (-1);
} 
}

int decision2( char *__2086_22_ip_addr_string) {
auto struct hostent *__2087_19_hp;
auto struct hostent *__2088_19_hpClone;
auto struct in_addr __2089_17_myaddr;
auto char *__2090_9_tHost = "trustme.trysty.com";

__2087_19_hp = ((struct hostent *)(gethostbyaddr(((char *)(&__2089_17_myaddr)), 4U, 0)));


__2088_19_hpClone = ((struct hostent *)0);

if (__2086_22_ip_addr_string == ((char *)0)) {
__2088_19_hpClone = __2087_19_hp;
} else  {
if ((__2088_19_hpClone) && (!(strncmp(((const char *)(__2088_19_hpClone->h_name)), ((const char *)__2090_9_tHost), 4U)))) {
return (-1);
}
} 
}
