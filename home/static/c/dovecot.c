/*
  Potential program crash
  Check: PTR-null-assign-fun-pos
    
  This bug is inspired by one which Goanna found in Dovecot during the
  2010 SATE competition <http://samate.nist.gov/SATE2010Workshop.html>.
  
  The warning identifies line 51, and states that the argument preferred_host
  may be 0, and is dereferenced.
  
  Goanna's inter-procedural analysis (IPA) and model-checking identify that the
  get_preferred_host function may return 0 on some paths. This value is
  stored in preferred_host in line 48. IPA and model-checking also identify that
  in connect_host, which is called on line 51, will dereference its parameter -
  preferred_host - without checking it against 0 first.
*/


#include <stdlib.h>

struct IP4{
  int a;
  int b;
  int c;
  int d;
};

void connect_host(struct IP4* host);

struct IP4* preferred_hosts;

struct IP4* get_preferred_host(int user){
  if (user < 10){
    return &(preferred_hosts[user]);
  } else {
    return 0;  // 1. get_preferred_host may return 0
  }
}

void connect(int a, int b, int c, int d){
  /*
    do stuff
  */
}

void organize_host(struct IP4* current_host, int user){

  struct IP4* preferred_host = get_preferred_host(user);  // 2. preferred_host may be 0 at this point
  
  if (current_host != preferred_host){
    connect_host(preferred_host);  // 3. connect_host is called with preferred_host as the argument
  }
}

void connect_host(struct IP4* host){
  connect(host->a, host->b, host->c, host->d);  // 4. Unconditional dereference of parameter.
}

void execute_server(int user){
  preferred_hosts = (struct IP4*)malloc(sizeof(struct IP4) * 10);
  organize_host(&preferred_hosts[0], user);
}
