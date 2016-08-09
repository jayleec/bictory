/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:58 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/EMPTY_BRANCH.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 2 "/home/kskyj/sparrow4/util/testcode/c/EMPTY_BRANCH.c"
extern void no_else_branch(int arg);




extern void empty_else_branch1(int arg);
#line 14
extern void empty_else_branch2(int arg);




extern void empty_else_branch3(int arg);
#line 27
extern void empty_else_branch_not_found(int arg);
#line 36
extern void empty_else_branch_not_found2(int arg);
#line 45
extern void no_cases(int arg);
#line 53
extern void empty_case(int arg);
#line 65
extern void no_default(int arg);
#line 74
extern void empty_default(int arg);
#line 2
void no_else_branch( int __6_25_arg) {
if (__6_25_arg) {
} 
}

void empty_else_branch1( int __11_29_arg) {
if (__11_29_arg) {
} else  {
} 
}


void empty_else_branch2( int __18_29_arg) {
if (__18_29_arg) {
} else  ; 
}

void empty_else_branch3( int __23_29_arg) {
if (__23_29_arg) {
} else  {
;
} 
}


void empty_else_branch_not_found( int __31_38_arg) {
if (__31_38_arg) {
} else  {
auto int __34_15_a;
__34_15_a = 0;
} 
}


void empty_else_branch_not_found2( int __40_39_arg) {
if (__40_39_arg) {
} else  {
while (0) {
}
} 
}


void no_cases( int __49_19_arg) {
auto int __50_6_a;
switch (__49_19_arg) {
default:
__50_6_a = 1;
} 
}

void empty_case( int __57_21_arg) {
auto int __58_6_a;
switch (__57_21_arg) {
case 1:
case 2:
__58_6_a = 1;
goto __T42317808;
default:
__58_6_a = 2;
} __T42317808:; 
}

void no_default( int __69_21_arg) {
auto int __70_6_a;
switch (__69_21_arg) {
case 1:
__70_6_a = 1;
goto __T42319512;
} __T42319512:; 
}

void empty_default( int __78_24_arg) {
auto int __79_6_a;
switch (__78_24_arg) {
case 1:
__79_6_a = 1;
goto __T42320872;
default:
;
} __T42320872:; 
}
