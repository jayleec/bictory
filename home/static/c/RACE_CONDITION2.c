// @checker RACE_CONDITION
extern int access(char *, int);
extern int pthread_mutex_lock(void*);
extern int pthread_mutex_unlock(void*);
extern int fchmod(int, int);
extern char* fopen(char *, char *);
extern char* open(char *, char *);


void file_operation() {
  char* file = "myfile.txt";
  char* f;
  if(!access(file,0)) {
    f = fopen(file,"w+");
    // operate(f);
  }
  else {
    //Unable to open file
  }
}


void safe_file_operation() {
  char *file= "myfile.txt";
  int fd;

  fd = open( file, 0);
  if (fd == -1) {
  }

  if (fchmod(fd, 0) == -1) {
  }
}


void defected_mutex(void* mutex)
{
  pthread_mutex_lock(mutex);
  // doing somthing
  pthread_mutex_unlock(mutex);
}

int safe_mutex(void* mutex)
{
  int result;
  result = pthread_mutex_lock(mutex);
  if (0 != result)
    return result;
  return pthread_mutex_unlock(mutex);
}

