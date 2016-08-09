/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API16.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API16.c"
extern char *getSSS();




extern void strcpy(char *dest, char *src);



extern int badFoo(void);
#line 26
extern void goodFoo(void);
#line 1
char *getSSS() {
return ((char *)0);
}


void strcpy( char *__10_20_dest,  char *__10_33_src) {
return;
}

int badFoo(void) {
auto char *__15_9_TB_Feild;
auto int __16_6_var = 1;
auto const int __17_12_con = 1;

__15_9_TB_Feild = "SSS";

if (__16_6_var < 1) {
__16_6_var = (__16_6_var + 1);
}

strcpy(__15_9_TB_Feild, "SSS");

return 1;
}

void goodFoo(void) {
auto char *__31_8_TB_Feild;

strcpy(__31_8_TB_Feild, (getSSS())); 
}
