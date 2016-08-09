/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/CHROOT_JAIL_WITHOUT_CHANGE_WORK_DIR.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 604 "/usr/include/stdio.h"
extern char *fgets(char *__s, int __n, FILE *__stream);
#line 3 "/home/kskyj/sparrow4/util/testcode/c/CHROOT_JAIL_WITHOUT_CHANGE_WORK_DIR.c"
extern void chroot_jail_without(FILE *network);



extern int chroot();
#line 3
void chroot_jail_without( FILE *__839_32_network) {

auto char __841_8_filename[80];

chroot(("/var/ftproot"));
fgets((__841_8_filename), 80, __839_32_network); 

}
