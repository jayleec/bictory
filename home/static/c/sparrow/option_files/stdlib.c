/******************************************************************************
*                                                                             *
* Sparrow Built-In Stub Functions of Standard Library                         *
*                                                                             *
* Copyright 2014 Fasoo.com Inc.                                               *
*                                                                             *
******************************************************************************/

typedef unsigned int size_t;
typedef unsigned int mode_t;
typedef void FILE;
typedef void DIR;
typedef int wchar_t;

int __sparrow_top;
/* exit */
void abort() {
  exit(1);
}

void fatal(){
  exit(1);
}

int raise(int sig) {
  exit(1);
}
void pthread_exit(void *retval) {
  exit(1);
}
void _exit(int status) {
  exit(status);
}
void _Exit(int status) {
  exit(status);
}
void DebugBreak() {
  exit(1);
}

/* exit, used by assert */
void _assert(void *msg, void *file, unsigned line) {
  /*
   * #define assert(exp) (void)( (exp) || (_assert(#exp, __FILE__, __LINE__), 0) )
   */
  exit(1);
}
void _wassert(const wchar_t *_Message, const wchar_t *_File, unsigned _Line) {
  /*
   * #define assert(_Expression) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )
   */
  exit(1);
}
int _CrtDbgReport(int reportType, const char *filename, int linenumber, const char *moduleName, const char *format, ...) {
  exit(1);
}
int _CrtDbgReportW(int reportType, const char *filename, int linenumber, const char *moduleName, const char *format, ...) {
  /*
   * We use !! below to ensure that any overloaded operators used to evaluate expr do not end up at operator ||
   * #define _ASSERT_EXPR(expr, msg) \
   *         (void) ((!!(expr)) || \
   *                 (1 != _CrtDbgReportW(_CRT_ASSERT, _CRT_WIDE(__FILE__), __LINE__, NULL, msg)) || \
   *                 (_CrtDbgBreak(), 0))
   *
   * #ifndef _ASSERT
   * #define _ASSERT(expr)   _ASSERT_EXPR((expr), NULL)
   * #endif
   *
   * #ifndef _ASSERTE
   * #define _ASSERTE(expr)  _ASSERT_EXPR((expr), _CRT_WIDE(#expr))
   * #endif
   */
  exit(1);
}

/* assert */
void assert(int expression) {
  ((expression) ? 0 : exit(1));
}

/* string */
void *memset(void *s, int c, int n) {
  if(n == 0) return s;
  __sparrow_memset(s);
  __sparrow_bufacc(s,n - 1); /* sizeof(s) >= n */
  return s;
}
void bzero(void *s, int n) {
  if(n == 0) return;
  __sparrow_memset(s);
  __sparrow_bufacc(s,n-1); /* sizeof(s) >= n */
}

void *memcpy(void *dest, void *src, size_t n) {
  if(n == 0) return dest;
  __sparrow_memset(dest);
  __sparrow_deref(src);
  __sparrow_bufacc(dest,n-1); /* sizeof(dest) >= n */
  __sparrow_bufacc(src,n-1);  /* sizeof(src) >= n */
  __sparrow_overlap(src,dest);
  __sparrow_unreasonable_length(n);
  return dest;
}

void *memccpy(void *dest, const void *src, int ch, size_t n) {
  __sparrow_unreasonable_length(n);
  __sparrow_overlap(src,dest);
}

void *memmove(void *dest, const void *src, size_t n) {
  if(n == 0) return dest;
  __sparrow_memset(dest);
  __sparrow_deref(src);
  __sparrow_bufacc(dest,n-1); /* sizeof(dest) >= n */
  __sparrow_bufacc(src,n-1);  /* sizeof(src) >= n */
  __sparrow_unreasonable_length(n);
  return dest;
}
wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n) {
  if(n == 0) return dest;
  __sparrow_memset(dest);
  __sparrow_deref(src);
  __sparrow_bufacc(dest,n-1); /* sizeof(dest) >= n */
  __sparrow_bufacc(src,n-1);  /* sizeof(src) >= n */
  __sparrow_unreasonable_length(n);
  return dest;
}
char *strcat(char *dest, const char *src) {
  __sparrow_memset(dest);
  __sparrow_strcpy(dest,src); /* sizeof(dest) >= sizeof(src) */
  __sparrow_unbounded_source(dest,src); /* src가 외부 입력이고 dest가 스택 배열 */
  //__sparrow_bufacc(dest,sizeof(src)-sizeof(dest)+strlen(dest));
  return dest;
}
wchar_t *wcscat(wchar_t *dest, const wchar_t *src) {
  __sparrow_memset(dest);
  __sparrow_deref(src);
  __sparrow_strcpy(dest,src); /* sizeof(dest) >= sizeof(src) */
  return dest;
}
char *strncat(char *dest, const char *src, size_t n) {
  __sparrow_memset(dest);
  __sparrow_bufacc(dest,n); /* sizeof(dest) >= (n+1) */
  __sparrow_unreasonable_length(n);
  return dest;
}
wchar_t *wcsncat(wchar_t *dest, const wchar_t *src, size_t n) {
  __sparrow_memset(dest);
  __sparrow_deref(src);
  __sparrow_bufacc(dest,n); /* sizeof(dest) >= (n+1) */
  __sparrow_unreasonable_length(n);
  return dest;
}
char *strcpy(char *dest, const char *src) {
  __sparrow_memset(dest);
  __sparrow_strcpy(dest,src); /* sizeof(dest) >= sizeof(src) */
  __sparrow_overlap(src,dest);
  return dest;
}
wchar_t *wcscpy(wchar_t *dest, const wchar_t *src) {
  __sparrow_memset(dest);
  __sparrow_deref(src);
  __sparrow_strcpy(dest,src); /* sizeof(dest) >= sizeof(src) */
  return dest;
}
char *strncpy(char *dest, const char *src, size_t n) {
  __sparrow_memset(dest);
  __sparrow_overlap(src,dest);
  __sparrow_unreasonable_length(n);
  __sparrow_strncpy(dest,src,n); /* Improper Null Termination alarm when sizeof(src) > n  */
  /* __sparrow_strncpy 내부에서 bufacc까지 처리하게 수정함. false alarm을 줄이기 위해서.
    이 경우 dest의 크기가 2이더라도 상수 string(크기가 2보다 작음)이
    사용되었으면 alarm을 내지 않도록 해야 할 것 같습니다. */
  return dest;
}
wchar_t *wcsncpy(wchar_t *dest, const wchar_t *src, size_t n) {
  if(n == 0) return src;
  __sparrow_memset(dest);
  __sparrow_deref(src);
  __sparrow_bufacc(dest,n-1); /* sizeof(dest) >= n */
  __sparrow_unreasonable_length(n);
  return dest;
}

char *strdup(const char *s) {
  char *ret = __sparrow_calloc();
  int i;
  for(i=0;i<strlen(s);i++){
    *ret = *(s+i);
    ret++;
  }
  *ret = '\0';
  return ret;
}

char *strndup(const char *s, size_t n) {
  char *ret = __sparrow_calloc();
  int i;
  __sparrow_unreasonable_length(n);

  for(i=0;i<n;i++){
    *ret = *(s+i);
    ret++;
  }
  *ret = '\0';
  return ret;
}

long strtol(const char *str, char **endptr, int base){
  if (__sparrow_top > 0){
    *endptr = '\0';
  } else {
    *endptr = str;
  }
  return __sparrow_top;
}

long long strtoll(const char *str, char **endptr, int base){
  if (__sparrow_top > 0){
    *endptr = '\0';
  } else {
    *endptr = str;
  }
  return __sparrow_top;
}

int snprintf(char *dst, size_t size, char*format, char *src){
  __sparrow_bufacc(dst,size-1);
  __sparrow_bufacc(src,size-1);
}
int _snprintf(char *dst, size_t size, char*format, char *src){
  __sparrow_bufacc(dst,size-1);
  __sparrow_bufacc(src,size-1);
}
int snwprintf(char *dst, size_t size, char*format, char *src){
  __sparrow_bufacc(dst,size-1);
  __sparrow_bufacc(src,size-1);
}
int _snwprintf(char *dst, size_t size, char*format, char *src){
  __sparrow_bufacc(dst,size-1);
  __sparrow_bufacc(src,size-1);
}

/*
size_t strlen(const char *s) {
}
*/
/*
int bcmp(const void *s1, const void *s2, size_t n);
void bzero(void *s, size_t n);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
int strncasecmp(const char *s1, const char *s2, size_t n);
int strncmp(const char *s1, const char *s2, size_t n);
size_t wcslen(const wchar_t *s);
int wcsncasecmp(const wchar_t *s1, const wchar_t *s2, size_t n);
int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n);
wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n);
int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n);
wchar_t *wmemcpy(wchar_t *dest, const wchar_t *src, size_t n);
wchar_t *wmemset(wchar_t *wcs, wchar_t wc, size_t n);
*/

/* io */
char *fgets(char *s, int size, FILE *stream) {
  __sparrow_memset(s);
  __sparrow_bufacc(s,size-1); /* sizeof(s) >= size */
  if (s == 0) exit(); //NULL_DEREF.CHECK.AFTER_DEREF
  return s;
}

/* CERT: FIO01-C */
int stat(const char *path, struct stat *buf) {
  __sparrow_deref(path);
  __sparrow_memset(buf);
  __sparrow_open_later(path); // 나중에 열리면 에러 TOCTOU
  __sparrow_isopen(path);
  return __sparrow_unknown();
}

/* CERT: FIO01-C */
int _stat(const char *path, struct stat *buf) {
  __sparrow_deref(path);
  __sparrow_memset(buf);
  __sparrow_open_later(path); // 나중에 열리면 에러 TOCTOU
  __sparrow_isopen(path);
  return __sparrow_unknown();
}

/* CWE367 Time-of-check Time-of-use (TOCTOU) Race Condition */
int access(const char *path, int amode){
  __sparrow_open_later(path); // 나중에 열리면 에러 TOCTOU
  if (__sparrow_unknown()) {return 0;} else { return -1;}
}

int remove(const char *path){
  __sparrow_isopen(path);
  return __sparrow_unknown();
}

int chmod(const char *file, int mode){
  __sparrow_isopen(file);
  return __sparrow_unknown();
}

int chown(const char *path, int owner, int group){
  __sparrow_isopen(path);
  return __sparrow_unknown();
}

/* alloc */
void *malloc(size_t size) {
  __sparrow_unreasonable_length(size);
  return __sparrow_malloc(size);
}

void *new(size_t size){
  return __sparrow_new();
}
void *new_array(size_t size){
  return __sparrow_new_array();
}

void *calloc(size_t nmemb, size_t size) {
  __sparrow_unreasonable_length(size);
  __sparrow_unreasonable_length(nmemb);
  __sparrow_multiple_check(size,nmemb);
  return __sparrow_calloc();
}

void *realloc(void *ptr, size_t size) {
  __sparrow_realloc_free(ptr);
  __sparrow_unreasonable_length(size);
  return __sparrow_calloc();
}


/* aligned allocation */
int posix_memalign(void **memptr, size_t alignment, size_t size) {
  *memptr = __sparrow_memalign();
  return 0;
}
void _aligned_malloc(size_t size, size_t alignment){
  return __sparrow_memalign();
}
void aligned_alloc(size_t size, size_t alignment){
  return __sparrow_memalign();
}
void *memalign(size_t boundary, size_t size) {
  return __sparrow_memalign();
}


void *valloc(size_t size) {
  return __sparrow_malloc(size);
}
/* int cfree(void *ptr); */ /* In SunOS 4 */
void cfree(void *ptr) { /* In glibc or FreeBSD libcompat */
  __sparrow_free(ptr);
}

void delete(void *ptr){
  __sparrow_delete(ptr);
}

void delete_array(void *ptr){
  __sparrow_delete_array(ptr);
}

/* void cfree(char *ptr, unsigned num, unsigned size); */ /* In SCO OpenServer */
/* void cfree(void *ptr, size_t nelem, size_t elsize); */ /* In Solaris watchmalloc.so.1 */

/* system call */
void *kalloc(int type, size_t size) {
  return __sparrow_malloc(size);
}
void kfree(int type, void *ptr) {
  __sparrow_free(ptr);
}
void *vmalloc(unsigned long size) {
  return __sparrow_malloc(size);
}
void vfree(void *ptr) {
  __sparrow_free(ptr);
}

/* fopen */
FILE *fopen(const char *path, const char *mode) {
  return __sparrow_fopen(path);
}
FILE *fdopen(int fd, const char *mode) {
  __sparrow_negative_check(fd);
  return fd;
}
FILE *freopen(const char *path, const char *mode, FILE *stream) {
  __sparrow_close_file(stream);
  return __sparrow_fopen(path);
}
FILE *fopen64(const char *path, const char *mode) {
  return __sparrow_fopen(path);
}
FILE *freopen64(const char *path, const char *mode, FILE *stream) {
  __sparrow_close_file(stream);
  return __sparrow_fopen(path);
}
FILE *fmemopen(void *buf, size_t size, const char *mode) {
  return __sparrow_fopen();
}
FILE *open_memstream(char **ptr, size_t *sizeloc) {
  return __sparrow_fopen();
}
int fclose(FILE *fp) {
  __sparrow_close_file(fp);
  return 0;
}

int open(const char *pathname, int flags) {
  return __sparrow_fopen(pathname);
}

int _open(const char *pathname, int flags) {
  return __sparrow_fopen(pathname);
}

int creat(const char *pathname, mode_t mode) {
  return __sparrow_socket();
}

int open64(const char *pathname, int flags) {
  return __sparrow_fopen(pathname);
}

/* socket */
int socket(int domain, int type, int protocol) {
  return __sparrow_socket();
}

int close(int fd) {
  __sparrow_negative_check(fd);
  __sparrow_close_socket(fd);
  return 0;
}

int _close(int fd) {
  __sparrow_negative_check(fd);
  __sparrow_close_socket(fd);
  return 0;
}

int	accept(int s, void *addr, void *addrlen){
  __sparrow_negative_check(s);
  return __sparrow_socket();
}

int	closesocket(int fildes){
  __sparrow_negative_check(fildes);
  __sparrow_close_socket(fildes);
  return 0;
}

/* SQLAllocHandle, SQLFreeHandle */
void SQLAllocHandle(int type, void *input, int  *handle){
  *handle = __sparrow_socket();
}

void SQLFreeHandle(int type, int handle){
  __sparrow_close_socket(handle);
}


/* popen */
FILE *popen(const char *command, const char *type) {
  return __sparrow_fopen();
}
int pclose(FILE *stream) {
  __sparrow_close_file(stream);
  return 0; /* not -1 */
}

/* opendir */
DIR *opendir(const char *name) {
  return __sparrow_fopen(name);
}
DIR *fdopendir(int fd) {
  return __sparrow_fopen();
}
int closedir(DIR *dir) {
  __sparrow_close_file(dir);
  return 0;
}

/* Checking Unreasonable Length */
void *alloca(size_t size){
  __sparrow_unreasonable_length(size);
  return __sparrow_alloca(size);
}

void *ALLOCA(size_t size){
  __sparrow_unreasonable_length(size);
  return __sparrow_alloca(size);
}

void *__builtin_alloca(size_t _size){
  __sparrow_unreasonable_length(size);
  return __sparrow_alloca(size);
}

void bcopy(const void *src, void *dest, size_t n){
  __sparrow_deref(src);
  __sparrow_memset(dest);
  __sparrow_unreasonable_length(n);
}

/* int readlink(const char *path, char *buf, size_t bufsize){ */
/*   __sparrow_bufacc(buf,bufsize); */
/*   *buf = __sparrow_user_input();  */
/* } */

/* size_t read (int fd, void *buf, size_t nbytes){ */
/*   *buf = __sparrow_user_input(); */
/*   if(__sparrow_top > 0) return nbytes; */
/*   else return -1; */
/* } */

/* char * getenv(const char * name){ */
/*   return __sparrow_user_input(); */
/* } */

/* POS39-C */
int htonl(int hostlong){
  __sparrow_close_net(hostlong);
}

int htons(int x){
  __sparrow_close_net(x);
  return x;
}

int ntohl(int x){
  __sparrow_close_net(x);
}

int ntohs(int x){
  __sparrow_close_net(x);
}

int recv(int socket, void *buf, size_t len, int flags){
  __sparrow_memset(buf);
  __sparrow_negative_check(socket);
  if (__sparrow_top > 0){
    *buf = __sparrow_net(); // must be closed by __sparrow_close_net()
    return __sparrow_top;
  }
  return -1;
}

/* thread related functions */
int pthread_mutex_lock(void *mutex){
  __sparrow_lock(mutex);
  return 0;
}

int pthread_mutex_unlock(void *mutex){
  __sparrow_unlock(mutex);
  return 0;
}

int pthread_mutex_trylock(void *mutex){
  __sparrow_trylock(mutex);
  return 0;
}

int	__fxstat(int version, int fildes, struct stat *buf){
  __sparrow_memset(buf);
  __sparrow_negative_check(fildes);
}
int	_dup(int fd){ __sparrow_negative_check(fd);}
int	_dup2(int fd1, int fd2){  __sparrow_negative_check(fd1);}
int	_fstat(int fd, struct _stat *buffer){__sparrow_memset(buffer);__sparrow_negative_check(fd); return 0;}
int	_fstat32(int fd, struct _stat32 *buffer){__sparrow_memset(buffer);__sparrow_negative_check(fd); return 0;}
int	_fstat32i64(int fd, struct _stat32i64 *buffer){__sparrow_memset(buffer);__sparrow_negative_check(fd); return 0;}
int	_fstat64(int fd, struct _stat64 *buffer){__sparrow_memset(buffer);__sparrow_negative_check(fd); return 0;}
int	_fstat64i32(int fd, struct _stat64i32 *buffer){__sparrow_memset(buffer);__sparrow_negative_check(fd); return 0;} 
int	_fstati64(int fd, struct _stati64 *buffer){__sparrow_memset(buffer); __sparrow_negative_check(fd);return 0;}
long	_lseek(int fd, long offset, int origin){__sparrow_negative_check(fd);}
long	_lseeki64(int fd, __int64 offset, int origin){__sparrow_negative_check(fd);}
int	_read(int fd, void *buffer, unsigned int count){__sparrow_memset(buf); __sparrow_negative_check(fd); return 0;}

FILE *	_wfdopen(int fd, const wchar_t *mode){__sparrow_negative_check(fd);}
int	_write(int fd, const void *buffer, unsigned int count){__sparrow_negative_check(fd);*buffer = __sparrow_top; return 0;}
int	bind(int s, const void *name, int namelen){__sparrow_negative_check(s);*name = __sparrow_top; return 0;}
int	connect(int s, const void *name, int namelen){__sparrow_negative_check(s); *name = __sparrow_top; return 0; }
int	dup(int old){__sparrow_negative_check(old);}
int	dup2(int oldfd, int newfd){__sparrow_negative_check(oldfd);}
int	fcntl(int fildes, int cmd, ...){__sparrow_negative_check(fildes);}
long	fpathconf(int fildes, int name){__sparrow_negative_check(fildes);}
int	fstat(int fildes, struct stat *buf){__sparrow_negative_check(fildes); __sparrow_memset(buf); return 0;}
int	fstatfs(int fd, struct statfs *buf){__sparrow_negative_check(fd);  __sparrow_memset(buf); return 0;}
int	fsync(int fildes){__sparrow_negative_check(fildes);}
int	ftruncate(int fildes, int length){__sparrow_negative_check(fildes);}
int	ioctl(int fildes, int request, ... ){__sparrow_negative_check(fildes);}
int	ioctlsocket(int fildes, int request, ... ){__sparrow_negative_check(fildes);}
int	listen(int socket, int backlog){__sparrow_negative_check(socket);}
int	lseek(int fildes, int offset, int whence){__sparrow_negative_check(fildes);}
int	readv(int fildes, void *iov, int iovcnt){__sparrow_negative_check(fildes);}
int	recvfrom(int socket,void *buffer,size_t length,int flags,void * address,int *address_len ){
  __sparrow_negative_check(socket); *buffer = __sparrow_top; *address = __sparrow_top;
}

int	recvmsg(int socket, void *message, int flags){__sparrow_memset(message); __sparrow_negative_check(socket);}
int	send(int socket, const void *buffer, size_t length, int flags){__sparrow_negative_check(socket);}
int	sendmsg(int socket, const void *message, int flags){__sparrow_negative_check(socket);}
int	sendto(int socket,const void *message,size_t length,int flags,void *dest_addr,int dest_len ){
  __sparrow_memset(message);
  __sparrow_memset(dest_addr);
  __sparrow_negative_check(socket);
 }
int	unlinkat(int dirfd, const char *pathname, int flags){__sparrow_negative_check(dirfd);*pathname=__sparrow_top; return 0;}
int	write(int fildes, const void *buf, size_t nbyte){__sparrow_negative_check(fildes);*buf=__sparrow_top;}
int	writev(int fildes, const void *iov, int iovcnt){__sparrow_negative_check(fildes);*iov=__sparrow_top;}

void *gethostbyname(const char *name){
  if (__sparrow_top > 0){
    return __sparrow_top;
 }
  return 0;
}

void *gethostbyaddr(const void *addr, int len, int type){
  if (__sparrow_top > 0){
    return __sparrow_top;
  }
  return 0;
}

/* CWE404 Improper Resource Shutdown */

FILE *CreateFile(const char *path,int a,int b, void *c,int d, int e, void *f){
  return __sparrow_open_handle(path);
}

void CloseHandle(int data){
  __sparrow_close_handle(data);
}

/* 농협 중앙회에서 사용하는 함수들 */
char *fnMalloc(size_t iBuffSize){
  __sparrow_unreasonable_length(iBuffsize);
  return (char *) __sparrow_malloc(iBuffSize);
}

/* alloc */
char *tpalloc(char *type, char *subtype, long size) {
  __sparrow_unreasonable_length(size);
  return __sparrow_malloc(size);
}

char *tprealloc(void *ptr, size_t size) {
  __sparrow_realloc_free(ptr);
  __sparrow_unreasonable_length(size);
  return __sparrow_calloc();
}

void free(void *ptr){
  __sparrow_free(ptr);
}

void tpfree(char *ptr){
  __sparrow_free(ptr);
}

// 턱시도 관련 함수 시작
/* tpreturn */
void tpreturn(int rval, long rcode, char *data, long len, long flags){
  __sparrow_free(data);
  __sparrow_tpreturn();
}

void ji_tpsuccess(void *transf, char *mmsg){
  __sparrow_free(transf);
  __sparrow_tpreturn();
}

void ji_tpsyserr(void *transf, char *mmsg, int sql_code){
  __sparrow_free(transf);
  __sparrow_tpreturn();
}

void ji_tpusrerr(void *transf, char *mmsg){
  __sparrow_free(transf);
  __sparrow_tpreturn();
}

void returnStatus(int rval, int rcode, char *sndBuf, void *stMessage){
  __sparrow_free(sndBuf);
  /* __sparrow_tpreturn함수는 leak을 검사한 후에 프로그램을 종료시키는 함수이다. */
  __sparrow_tpreturn();
}

void returnDataLog(int rval, int rcode, char *sndBuf, void *stMessage){
  __sparrow_free(sndBuf);
  __sparrow_tpreturn();
}

void returnData(int rval, int rcode, char *sndBuf, void *stMessage){
  __sparrow_free(sndBuf);
  __sparrow_tpreturn();
}

void returnNoData(int rval, int rcode, char *sndBuf, void *stMessage){
  __sparrow_free(sndBuf);
  __sparrow_tpreturn();
}

void returnError(int rval, int rcode, char *sndBuf, void *stMessage){
  __sparrow_free(sndBuf);
  __sparrow_tpreturn();
}

void returnMsg(int rval, int rcode, char *sndBuf, void *stMessage, char *ioType, char *output){
  __sparrow_free(sndBuf);
  __sparrow_tpreturn();
}

void N_MCO_ERROR_RETURN(void *msg, void *comm, void *err_info, int errorLine){
__sparrow_tpreturn();
}

// 턱시도 관련 함수 끝


/* 미래에셋증권에서 쓰이는 프로그램 종료시키는 함수 */
int ZZBatDone(
    int     nRtnCode,
    long    nProcCount,
    char    *pszResult1,
    char    *pszResult2,
    char    *pszResult3,
    char    *pszResult4) {
  exit(1);
}
 
 
int ZZSvcDone(void *OutData, long nOutLen, int Flag, int nRtnCode) {
  __sparrow_memset(OutData);
  exit(1);
}
  
/* Oracle OCI API */
void OCIStringResize(void *env, void *err, int new_size, void **str){
  if(str == 0) *str = malloc(new_size);
  if (new_size == 0) __sparrow_free(*str);
}

void OCIStringAssignText(void *env, void *err, char *rhs, int rhs_len, void **lhs){
  *lhs = rhs;
}

int wcwidth(wchar_t c){
  if (c == L'\0') return 0;
  else return sparrow_top;
}

/* WIN32 API */

/* WIN32 Object*/
void* CreatePen(int fnPenStyle, int nWidth, unsigned int crColor){
	return __sparrow_new();
}

void* CreateSolidBrush(unsigned int color){
	return __sparrow_new();
}

void* CreateHatchBrush(int fnStyle,unsigned int color){
	return __sparrow_new();
}

void* CreateFont( int nHeight, int nWidth, int nEscapement, int nOrientation, int fnWeight, 
				unsigned int fdwItalic, unsigned int fdwUnderline, unsigned int fdwStrikeOut, unsigned int fdwCharSet, 
				unsigned int fdwOutputPrecision, unsigned int fdwClipPrecision, unsigned int fdwQuality, 
				unsigned int fdwPitchAndFamily, char* lpszFace )
{
	return __sparrow_new();
}

void* CreateRectRgnIndirect(struct _RECT  *lprc)
{
  return __sparrow_new();
}

void* CreatePolygonRgn(struct tagPOINT *lppt, int cPoints, int fnPolyFillMode)
{
  return __sparrow_new();
}
void* CreatePolyPolygonRgn(struct tagPOINT *lppt, int *lpPolyCounts, int nCount, int fnPolyFillMode)
{
  return __sparrow_new();
}
void* CreateRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
{
  return __sparrow_new();
}

void* CreateRoundRectRgn( int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse)
{
  return __sparrow_new();
}

void* CreateCompatibleDC(void* hdc)
{
  return __sparrow_new();
}

void* LoadBitmap( void* hInstance,char* lpBitmapName)
{
  return __sparrow_new();
}

void* CreateBitmap( int nWidth, int nHeight, unsigned int cPlanes, unsigned int cBitsPerPel, void *lpvBits)
{
  return __sparrow_new();
}
void* CreateBitmapIndirect(void* lpbm)
{
  return __sparrow_new();
}

void* CreateCompatibleBitmap(void* hdc, int nWidth,int nHeight)
{
  return __sparrow_new();
}

void* CreateDIBitmap(void* hdc, void* lpbmih,unsigned int fdwInit, void* lpbInit, void* lpbmi,unsigned int fuUsage)
{
  return __sparrow_new();
}

void* CreateDIBSection(void* hdc, void* pbmi,unsigned int iUsage, void** ppvBits, void* hSection,unsigned int dwOffset)
{
  *ppvBits = __sparrow_new();
  return __sparrow_new();
}

void DeleteObject(void* obj){
  __sparrow_delete(obj);
}
/* WIN32 DC */

void* CreateDC(char* lpszDriver, char* lpszDevice, char* lpszOutput,void* lpInitData)
{
  return __sparrow_new();
}

void* GetDC(void* hWnd)
{
  return __sparrow_new();
}

void* GetDCEx(void* hWnd, void* hrgnClip, unsigned int flags)
{
  return __sparrow_new();
}

void* GetWindowDC(void* hWnd)
{
  return __sparrow_new();
}

int ReleaseDC(void* hWnd, void* hDC)
{
  __sparrow_delete(hDC);
}

int DeleteDC(void* hdc)
{
  __sparrow_delete(hdc);
}

void* HeapAlloc(void* hHeap, unsigned int dwFlags, unsigned int dwBytes)
{
  return __sparrow_malloc(dwBytes);
}

void* HeapReAlloc(void* hHeap,unsigned int dwFlags,void* lpMem,unsigned int dwBytes)
{
  __sparrow_realloc_free(hHeap);
  __sparrow_unreasonable_length(dwBytes);
  return __sparrow_calloc();
}

int HeapFree(void* hHeap, unsigned int dwFlags, void* lpMem)
{
  __sparrow_free(lpMem);
}

void* HeapCreate(unsigned int flOptions,unsigned int dwInitialSize, unsigned int dwMaximumSize)
{
  return __sparrow_malloc();
}

int HeapDestroy(void* hHeap)
{
  __sparrow_free(hHeap);
}

void* GlobalAlloc(unsigned int uFlags, unsigned int dwBytes)
{
  return __sparrow_malloc(dwBytes);
}

void* GlobalFree(void* hMem)
{
  __sparrow_free(hMem);
}

void* GlobalReAlloc(void* hMem, unsigned int dwBytes, unsigned int uFlags)
{
  __sparrow_realloc_free(hMem);
  __sparrow_unreasonable_length(dwBytes);
  return __sparrow_calloc();
}

void* LocalAlloc(unsigned int uFlags, unsigned int uBytes)
{
	return __sparrow_malloc(uBytes);
}

void* LocalFree(void* hMem)
{
  __sparrow_free(hMem);
}

void* LocalReAlloc(void* hMem, unsigned int uBytes, unsigned int uFlags)
{
  __sparrow_realloc_free(hMem);
  __sparrow_unreasonable_length(uBytes);
  return __sparrow_calloc();
}

void* VirtualAlloc(void* lpAddress, unsigned int dwSize, unsigned int flAllocationType, unsigned int flProtect)
{
	return __sparrow_malloc(dwSize);
}

void* VirtualAllocEx(void* hProcess, void* lpAddress, unsigned int  dwSize,
  unsigned int  flAllocationType,unsigned int  flProtect)
{
	return __sparrow_malloc(dwSize);
}

void* VirtualAllocExNuma(void* hProcess, void* lpAddress, unsigned int dwSize, unsigned int flAllocationType,
  unsigned int flProtect,unsigned int nndPreferred)
{
	return __sparrow_malloc(dwSize);
}
  
int VirtualFree(void* lpAddress, unsigned int dwSize, unsigned int dwFreeType)
{
  __sparrow_free(lpAddress);
}
int VirtualFreeEx(void* hProcess, void* lpAddress, unsigned int dwSize,unsigned int dwFreeType)
{
  __sparrow_free(lpAddress);
}

/* WIN32 Winsock*/

int GetAddrInfoEx(  char* pName, char* pServiceName,unsigned int dwNameSpace,void* lpNspId,void* pHints, void** ppResult,
  void* timeout, void* lpOverlapped, void* lpCompletionRoutine, void* lpNameHandle)
{
  
  if (__sparrow_top > 0) {
    *ppResult = __sparrow_new();
    return 0;
  } else {
    return 1;
  }
}

void FreeAddrInfoEx(void* pAddrInfo)
{
  __sparrow_delete(pAddrInfo);
}

int GetAddrInfoW(int* pNodeName, int* pServiceName, void* pHints,void **ppResult)
{
  if (__sparrow_top > 0) {
    *ppResult = __sparrow_new();
    return 0;
  } else {
    return 1;
  }
}

void FreeAddrInfoW(void* pAddrInfo)
{
  __sparrow_delete(pAddrInfo);
}

int getaddrinfo(char* pNodeName, char* pServiceName, void* pHints, void** ppResult)
{
  if (__sparrow_top > 0) {
    *ppResult = __sparrow_new();
    return 0;
  } else {
    return 1;
  }
}

void freeaddrinfo(void *ai)
{
  __sparrow_delete(ai);
}

void* SysAllocString(void *psz)
{
  return __sparrow_new();
}

void* SysAllocStringByteLen(void* psz, unsigned int len)
{
  return __sparrow_malloc(len);
}

void* SysAllocStringLen(void* strIn,unsigned int ui)
{
  __sparrow_unreasonable_length(ui);
  return __sparrow_calloc();
}

int SysReAllocString(void* pbstr, void* psz)
{
  __sparrow_realloc_free(pbstr);
  return __sparrow_calloc();
}

int SysReAllocStringLen(void* pbstr, void* psz, unsigned int len)
{
   __sparrow_realloc_free(pbstr);
  __sparrow_unreasonable_length(len);
  return __sparrow_calloc();
}

void SysFreeString(void* bstrString)
{
  return __sparrow_delete(bstrString);
}

int pfmDbioGetError(){
  return 0;
}

char *ttyname(int fildes){
  if (__sparrow_top > 0){
    return __sparrow_top;
  } else {
    return 0;
  }
}
    
/* COM 은 본격 CLASS 객체를 사용해서 곤란함 */

/*
아래는 File 관련 나중에 넣기
CreateFileMapping

MapViewOfFile
UnmapViewOfFile
MapViewOfFile
UnmapViewOfFile
*/

/* AutoEver functions */
int AesOmac1_Init(void * omac1Ctx, void *vehicleKey){
  return __sparrow_top;
}
int AesOmac1_Update(void *omac1Ctx, void *msg, int x){
  return __sparrow_top;
}

int AesOmac1_Finish(void *omac1Ctx, void *cmac, int x){
  return __sparrow_top;
}

/* Openssl HeartBleed */
void *CRYPTO_malloc( int num,  const char *file,  int line){
  return __sparrow_malloc(num);
}

void CRYPTO_free( void * str){
  __sparrow_free(str);
}
  

