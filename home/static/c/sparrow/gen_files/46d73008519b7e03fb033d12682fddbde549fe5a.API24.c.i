/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API24.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 2 "/home/kskyj/sparrow4/util/testcode/c/API24.c"
extern void strcpy(char *dest, char *src);



extern char *getSSS();



extern void badFoo(void);
#line 17
extern void goodFoo(void);
#line 2
void strcpy( char *__6_20_dest,  char *__6_33_src) {
return;
}

char *getSSS() {
return ((char *)0);
}

void badFoo(void) {
auto char *__15_9_TB_Feild;

strcpy(__15_9_TB_Feild, "SSS");
strcpy(__15_9_TB_Feild, "NOT_TARGET"); 
}

void goodFoo(void) {
auto char *__22_8_TB_Feild;

strcpy(__22_8_TB_Feild, (getSSS())); 
}
