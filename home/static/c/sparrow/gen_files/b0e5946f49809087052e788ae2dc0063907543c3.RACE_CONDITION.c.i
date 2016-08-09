/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/RACE_CONDITION.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 2 "/home/kskyj/sparrow4/util/testcode/c/RACE_CONDITION.c"
extern int access(char *, int);
extern int pthread_mutex_lock(void *);
extern int pthread_mutex_unlock(void *);
extern int fchmod(int, int);
extern char *fopen(char *, char *);
extern char *open(char *, char *);


extern void file_operation();
#line 23
extern void safe_file_operation();
#line 36
extern void defected_mutex(void *mutex);
#line 43
extern int safe_mutex(void *mutex);
#line 10
void file_operation() {
auto char *__15_9_file = "myfile.txt";
auto char *__16_9_f;
if (!(access(__15_9_file, 0))) {
__16_9_f = (fopen(__15_9_file, "w+"));

}
else  {

} 
}


void safe_file_operation() {
auto char *__28_9_file = "myfile.txt";
auto int __29_7_fd;

__29_7_fd = ((int)(open(__28_9_file, ((char *)0))));
if (__29_7_fd == (-1)) {
}

if ((fchmod(__29_7_fd, 0)) == (-1)) {
} 
}


void defected_mutex( void *__40_27_mutex)
{
pthread_mutex_lock(__40_27_mutex);

pthread_mutex_unlock(__40_27_mutex); 
}

int safe_mutex( void *__47_22_mutex)
{
auto int __49_7_result;
__49_7_result = (pthread_mutex_lock(__47_22_mutex));
if (0 != __49_7_result)
return __49_7_result;
return pthread_mutex_unlock(__47_22_mutex);
}
