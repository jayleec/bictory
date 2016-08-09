# 1 "/home/kskyj/sparrow4/util/testcode/c/RACE_CONDITION.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/RACE_CONDITION.c"

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

  }
  else {

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
