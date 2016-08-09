/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API23.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/API23.c"
extern void set_err(char *type, char *disc);

extern int badError();




extern int goodError();
#line 17
extern int goodError2();




extern int badError2();
#line 6
int badError() {

return (-1);
}

int goodError() {

set_err("ERRORCode", "error number");
return (-1);
}

int goodError2() {

set_err("ERRORCode", "error number"); 
}

int badError2() {

return (-1);
}
