/* CERT EXP35-C Do not modify objects with temporary lifetime*/
#include <stdio.h>

struct X { int a[6]; };
struct Y { char a[8]; };

struct X get_x_struct(void) {
	struct X result = { 1, 2, 3, 4, 5, 6 };
	return result;
}

struct Y get_y_struct(void){
	struct Y result = { "Hello" };
	return result;
}

 
int foo(int bar) {

	//int d = (addressee().a[2])++;	
	printf("%x", ++(get_x_struct().a[0]));	//@violation	TEMP_LIFETIME_OBJ_MODIFICATION
	printf("%s, %s!\n", get_y_struct().a, get_y_struct().a);	//@violation	TEMP_LIFETIME_OBJ_MODIFICATION
	
	int c = get_x_struct().a[1] + (bar++);
	
	return 0;
}