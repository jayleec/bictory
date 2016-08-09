#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE_1  5
#define BUFF_SIZE_2 10

struct List {
    char buf1[BUFF_SIZE_1];
    char buf2[BUFF_SIZE_2];
    int *ptr;
};

typedef struct Pair {
    char *x;
    char *y;
} S_RL03;

typedef struct Under {
   int buf[20];
}Under;
typedef struct List List;

//////////////////////////////////////////////////////////////////////
void buffer_overrun_01_sub(char *ptr, int size) {
    ptr[size]=0;
}
void buffer_overrun_01_main() {
    int i;
    char buf[BUFF_SIZE_1];
    buffer_overrun_01_sub(buf, BUFF_SIZE_1); /* BUG:OVERRUN.STATIC */
}

//////////////////////////////////////////////////////////////////////
int buffer_overrun_complex_01_sub() {
    return BUFF_SIZE_1;
}
void buffer_overrun_complex_01_main(char c) {
    char buf[BUFF_SIZE_1];
    buf[buffer_overrun_complex_01_sub()] = c; /* BUG:OVERRUN.STATIC.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
void buffer_overrun_02_main() {
    struct List str;
    char buff1[BUFF_SIZE_1];
    char buff2[BUFF_SIZE_2];
    strcpy(str.buf1, str.buf2); /* BUG:OVERRUN.STATIC.STRCPY */
    memcpy(buff1, buff2, sizeof(buff2)); /* BUG:OVERRUN.STATIC.MEMSET */
}

//////////////////////////////////////////////////////////////////////
int buffer_overrun_complex_02_sub() {
    return BUFF_SIZE_2;
}
void buffer_overrun_complex_02_main() {
    struct List str;
    char buff1[BUFF_SIZE_1];
    char buff2[BUFF_SIZE_2];
    strncpy(buff1, buff2, buffer_overrun_complex_02_sub()); /* BUG:OVERRUN.STATIC.MEMSET.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
void buffer_overrun_03(int index, char c) {
    char buf[10];
    if (index > /* >= */ 10) {
        return;
    }
    buf[index] = c; /* BUG:OVERRUN.STATIC.BAD_COND */
    memset(buf, 0, index + 1); /* BUG:OVERRUN.STATIC.MEMSET.BAD_COND */
}

//////////////////////////////////////////////////////////////////////
void buffer_overrun_complex_03_sub(int index) {
    if (index > /* >= */ 10) {
      exit(1);
    }
}
void buffer_overrun_complex_03(int index, char c) {
    char buf[10];
    buffer_overrun_complex_03_sub(index);
    buf[index] = c; /* BUG:OVERRUN.STATIC.BAD_COND.COMPLEX */
    memset(buf, 0, index + 1); /* BUG:OVERRUN.STATIC.MEMSET.BAD_COND.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
int memory_leak_01_sub(char **p, size_t n) {
    char *tmp;
    tmp = malloc(n);
    if (tmp != NULL) {
        *p = tmp;
        return 0;
    } else {
        return 1;
    }
}
int memory_leak_01_main(size_t size) {
    struct SRL01{
        char *p;
    } srl = { NULL };
    char *ptr;
    if (memory_leak_01_sub(&srl.p, size) /* != 0 */) {
        ptr = srl.p;
        free(ptr);
        return 2;
    }
    return 0; /* BUG:LEAK.MEMORY */
}

//////////////////////////////////////////////////////////////////////
int memory_leak_complex_01_sub(char **p, size_t n) {
    char *tmp;
    tmp = malloc(n);
    if (tmp != NULL) {
        *p = tmp;
        return 0;
    } else {
        return 1;
    }
}
void memory_leak_complex_01_sub_free(char *p) {
    if (unknown())
        free(p);
}
int memory_leak_complex_01_main(size_t size) {
    struct SRL01{
        char *p;
    } srl = { NULL };
    char *ptr;
    memory_leak_complex_01_sub(&srl.p, size);
    ptr = srl.p;
    memory_leak_complex_01_sub_free(ptr);
    return 0; /* BUG:LEAK.MEMORY.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
int resource_leak_01_sub(const char *name, FILE **pf) {
    FILE *f = fopen(name, "r");
    if (!f) {
        return -1;
    }
    *pf = f;
    return 0;
}
int resource_leak_01_main(const char *name) {
    FILE *dummy;
    if (resource_leak_01_sub(name, &dummy) == -1) {
        fprintf(stderr, "Problem with: %s\n", name);
        return 0;
    }
    return 1; /* BUG:LEAK.RESOURCE */
}

//////////////////////////////////////////////////////////////////////
int resource_leak_complex_01_sub(const char *name, FILE **pf) {
    FILE *f = fopen(name, "r");
    if (!f) {
        return -1;
    }
    *pf = f;
    return 0;
}
void resource_leak_complex_01_sub_close(FILE *f) {
    if (unknown())
        close(f);
}
int resource_leak_complex_01_main(const char *name) {
    FILE *dummy;
	int a;
    if (resource_leak_complex_01_sub(name, &dummy) == -1) {
        fprintf(stderr, "Problem with: %s\n", name);
        return 0;
    }
    resource_leak_complex_01_sub_close(dummy);
    return 1; /* BUG:LEAK.RESOURCE.COMPLEX */
	if(a==1){
		return 2;
	}
}

//////////////////////////////////////////////////////////////////////
void null_deref_01_sub(char *p, char c) {
    p[0] = c;
}
void null_deref_01_main() {
    char *p = NULL;
    null_deref_01_sub(p, 'a'); /* BUG:NULL_DEREF */
}

//////////////////////////////////////////////////////////////////////
void null_deref_complex_01_sub(char *p, char c) {
    p[0] = c;
}
void *null_deref_complex_01_sub2() {
    return NULL;
}
void null_deref_complex_01_main() {
    char *p = null_deref_complex_01_sub2();
    null_deref_complex_01_sub(p, 'a'); /* BUG:NULL_DEREF.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
void null_deref_02_main(char *pstr) {
    if(pstr != NULL)
        pstr[0] = 'a';
        pstr[1] = 'b'; /* BUG:NULL_DEREF.MISSING_CHECK */
}

//////////////////////////////////////////////////////////////////////
void null_deref_complex_02_sub(char *pstr) {
    if(pstr != NULL) ;
}
void null_deref_complex_02_main(char *pstr) {
    null_deref_complex_02_sub(pstr);
    pstr[1] = 'b'; /* BUG:NULL_DEREF.MISSING_CHECK.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
void null_deref_03_main() {
    struct List *p;
    p = (struct List*)malloc(sizeof(struct List));
    p->ptr = NULL; /* BUG:NULL_DEREF.MALLOC_FAILED */
    free(p);
}

//////////////////////////////////////////////////////////////////////
void divide_by_zero_03(int i) {
    int a = 0, b;
    int cnt = 100;
    if(i > 10)
        a = random();
    b = cnt/a; /* BUG:DIV_BY_ZERO */
}

//////////////////////////////////////////////////////////////////////
int divide_by_zero_complex_03_sub() {
    return 0;
}
void divide_by_zero_complex_03(int i) {
    int a, b;
    int cnt = 100;
    a = divide_by_zero_complex_03_sub();
    b = cnt/a; /* BUG:DIV_BY_ZERO.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
void divide_by_zero_04(int x) {
    int r, cnt = 100;
    if(!x)
        r = cnt/x; /* BUG:DIV_BY_ZERO.MISSING_CHECK */
}

//////////////////////////////////////////////////////////////////////
void divide_by_zero_complex_04_sub(int x) {
    if(!x) ;
}
void divide_by_zero_complex_04(int x) {
    int r, cnt = 100;
    divide_by_zero_complex_04_sub(x);
    r = cnt/x; /* BUG:DIV_BY_ZERO.MISSING_CHECK.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
void double_free_sub(List *p) {
    free(p->ptr);
    free(p);
}
void double_free_main() {
    List *head;
    head = (List *)malloc(sizeof(List));
    if (!head) {
        exit(1);
    }
    head->ptr = (int *)malloc(sizeof(int) * 10);
    if (!head->ptr) {
        free(head);
        exit(1);
    }
    double_free_sub(head);
    free(head); /* BUG:DOUBLE_FREE */
}

//////////////////////////////////////////////////////////////////////
void double_free_complex_sub(List *p) {
    free(p->ptr);
    if (unknown()) {
        free(p);
    }
}
void double_free_complex_main() {
    List *head;
    head = (List *)malloc(sizeof(List));
    if (!head) {
        exit(1);
    }
    head->ptr = (int *)malloc(sizeof(int) * 10);
    if (!head->ptr) {
        free(head);
        exit(1);
    }
    double_free_complex_sub(head);
    free(head); /* BUG:DOUBLE_FREE */
}

//////////////////////////////////////////////////////////////////////
void use_after_free(List *p) {
    free(p);
    free(p->ptr); /* BUG:USE_AFTER_FREE */
}

//////////////////////////////////////////////////////////////////////
void use_after_free_complex_sub(List *p) {
    if (unknown())
        free(p);
}
void use_after_free_complex(List *p) {
    use_after_free_complex_sub(p);
    free(p->ptr); /* BUG:USE_AFTER_FREE.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
char *return_pointer_to_freed() {
    char *p = (char *)malloc(1);
    free(p);
    return p; /* BUG:RETURN_FREE */
}

//////////////////////////////////////////////////////////////////////
void return_pointer_to_freed_complex_sub(List *p) {
    if (unknown())
        free(p);
}
char *return_pointer_to_freed_complex() {
    char *p = (char *)malloc(1);
    return_pointer_to_freed_complex_sub(p);
    return p; /* BUG:RETURN_FREE.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
int uninit(int mode) {
    int n;
    switch(mode) {
        case 1:
            n = 1;
            break;
        case 2:
            n = 2;
            break;
    }
    return n; /* BUG:UNINIT */
}

//////////////////////////////////////////////////////////////////////
void uninit_sub(int *p) {
    switch(rand()) {
        case 1:
            *p = 1;
            break;
        case 2:
            *p = 2;
            break;
    }
}
int uninit_main() {
    int n;
    uninit_sub(&n);
    return n; /* BUG:UNINIT.COMPLEX */
}

//////////////////////////////////////////////////////////////////////
char *return_pointer_to_local() {
    char buf[] = "abc";
    return buf; /* BUG:RETURN_LOCAL */
}

//////////////////////////////////////////////////////////////////////
void free_non_heap(int size) {
    char buf[10];
    char *p = buf;
    if (size > 10) {
        p = (char *)malloc(size);
    }
    if (!(size < /* <= */ 10)) {
        free(p); /* BUG:FREE_NON_HEAP */
    }
}

//////////////////////////////////////////////////////////////////////
struct big_number {
    char low[1024];
    char high[1024];
};
char pass_by_value(struct big_number b) { /* BUG:PASS_BY_VALUE */
    return b.low[0];
}

//////////////////////////////////////////////////////////////////////
int missing_return(unsigned int cnt, int sum) {
    if (cnt == 0) {
        return sum;
    }
    missing_return(cnt - 1, sum + cnt);
} /* BUG: MISSING_RETURN */


//////////////////////////////////////////////////////////////////////
int cast_alters_value() {
    int a = -2;
    unsigned int ua;
    /* simple */
    ua = (unsigned int) a;
    return 0;
} /* BUG: CAST_ALTERS_VALUE */

//////////////////////////////////////////////////////////////////////
void free_null_pointer_call(int *x){
   
  free(x); 
}
void free_null_pointer_main(){
  int *x = 0;
  free_null_pointer_call(x); 
} /* BUG: FREE_NULL_POINTER */

//////////////////////////////////////////////////////////////////////
void memcpy_with_overlapping_regions(){
  int *a = (int*)malloc(100);
  int *b = a;
  memcpy(a,b,10);    
  free(a);
}/* BUG: MEMCPY_WITH_OVERLAPPING_REGIONS */

//////////////////////////////////////////////////////////////////////
void null_check_after_dereference(){
  int *x;
  *x=100;
  if (x == 0){ 
    return;
  }
}/* BUG: NULL_CHECK_AFTER_DEREFERENCE */

//////////////////////////////////////////////////////////////////////
void shift_exceeds_bit_width(){

	int a=20,b=0;
	
	b=a<<9999999;
}/* BUG: SHIFT_EXCEEDS_BIT_WIDTH */

//////////////////////////////////////////////////////////////////////
void shift_negative(){

	int a=20,b=0;
	
	b=a<<-2;
}/* BUG: SHIFT_NEGATIVE */

//////////////////////////////////////////////////////////////////////
void underrun_static(){
  int b[100];
  b[7 * 8 - 57] = 0; 
}/* BUG: UNDERRUN.STATIC */ 


//////////////////////////////////////////////////////////////////////
void underrun_static_bad_condition(int index){
  int b[100];

  if(index<-5)
	b[index] = 0; 
}/* BUG: UNDERRUN.STATIC.BAD_COND */ 


//////////////////////////////////////////////////////////////////////
void type_underrun_static(){
  Under under;
  under.buf[-20]=5;
}/* BUG: TYPE_UNDERRUN.STATIC */ 

//////////////////////////////////////////////////////////////////////
void type_underrun_bad(int index){
  Under under;

  if(index<-5)
  under.buf[index]=5;
} /*BUG: TYPE_UNDERRUN_BAD_COND */ 

//////////////////////////////////////////////////////////////////////
void unresonable_parameter(){
 int a=-20;
  void *z = malloc(a); 
  free(z);
}/* BUG: UNRESONABLE_PARAMETER */ 


void format_string(){
  int x=2;
  
  printf("%s",x);
}/* BUG: FORMAT_STRING */ 

void unreachable_code(){
    int x=1; 
    switch (x) {
        case 1:
        break;
        printf("aa\n"); /* BUG: UNREACHABLE_CODE */     
    }    

}

//////////////////////////////////////////////////////////////////////

void ignored_return_value(){
FILE *fd;
char buf[20];  
fwrite(buf,1,1,fd);
}


//////////////////////////////////////////////////////////////////////

int ignored_return_2_sub(int x){
   return x - 20;
}
void ignored_return_2_main(){
   int y = ignored_return_2_sub(10); // IGNORED RETURN VALUE
   return;
}

//////////////////////////////////////////////////////////////////////
void checked_return(){
   FILE *fp;
   int a=20;
   /* some codes here */
   if(fscanf(fp,"%d",&a)==EOF)
   printf("End of file\n");
   if(fscanf(fp,"%d",&a)==EOF)
   printf("End of file\n");
   if(fscanf(fp,"%d",&a)==EOF)
   printf("End of file\n");
   if(fscanf(fp,"%d",&a)==EOF)
   printf("End of file\n");
   if(fscanf(fp,"%d",&a)==EOF)
   printf("End of file\n");
   /* some codes here */
   fscanf(fp,"%d",&a);  // CHECKED RETURN
}

//////////////////////////////////////////////////////////////////////
char dangerous_func_cast_sub(){
return 'b';
}
void dangerous_func_cast_main(){
int(*fp_dangerous_func_cast_main)();
fp_dangerous_func_cast_main = (int(*)())dangerous_func_cast_sub;  // DANGEROUS FUNCTION CAST
}


//////////////////////////////////////////////////////////////////////
void varargs_func_cast_sub(int n){
    /* some codes here */
}
void varargs_func_cast_main(){
    void(*pt_varargs)(int, ...);  // VARARGS FUNCTION CAST
    pt_varargs = (void(*)(int, ...))varargs_func_cast_sub;
}

//////////////////////////////////////////////////////////////////////
int overrun_pf() {
	int i = 0;
	int buf[10];
	while(1) {
		i++;
		buf[i] = 0; // OVERRUN PF
		if(i >= 10) break;
		}
	return 0;
} 
//////////////////////////////////////////////////////////////////////
void information_leak(){
	char* path=getenv("PATH");// INFORMATION EXPOSURE
	fprintf(stderr,path); // INFORMATION LEAK
}
//////////////////////////////////////////////////////////////////////
void argument_number_mismatch1(int a){
  printf("a = %d\n", a);
}
void argument_number_mismatch2(){
  // argument_number_mismatch1(2,3); // ARGUMENT_NUMBER_MISMATCH
}
//////////////////////////////////////////////////////////////////////

void double_close(){
	FILE *fp=fopen("test.txt","r");
	
		fclose(fp);	// DOUBLE_CLOSE
	
		fclose(fp);
	
}
//////////////////////////////////////////////////////////////////////
int redundant_condition1(){
	return 1;
}
int redundant_condition2(){
	return 0;
}
void redundant_condition3(){
	int x = redundant_condition1();
	int y = redundant_condition2();
	if(x==0||y==0) // REDUNDANT CONDITION
		printf("hello");
}
//////////////////////////////////////////////////////////////////////
int a = 2; // MINIMAL_SCOPE
void minimal_scope(){
    if (a++ == 20)
        printf("a = %d\n",a);
}
//////////////////////////////////////////////////////////////////////

///// comment


/*                                  // 잘못된 주석 형식: /**로 교체 필요
  * Fasoo.com Sparrow 2011-12-01    // 잘못된 주석 형식: 날짜 형식 교체 필요
 */

/**
  * TestMethod
  * Test method for the application
  * @param number1 The first number
  * @param object2 The second number                          // 잘못된 인자명
  * @return char Difference between two numbers    // 잘못된 반환형
  */

/**
  * char testField;        // 잘못된 필드 타입명
  * Test field for the application
  */
int testField;
////////////////////////////////////////////////////////////////////////////

missing_function_return(float a){ // MISSING_FUNCTION_RETURN_TYPE
 float b = 2.1;
 b += a;
return b;
}

