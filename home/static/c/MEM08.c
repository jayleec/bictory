#include <stdlib.h>
 
typedef struct gadget gadget;
struct gadget {
  int i;
  double d;
  char *p;
};
 
typedef struct widget widget;
struct widget {
  char *q;
  int j;
  double e;
};

void * returnRealloc(gadget *gp) {
	return realloc(gp, sizeof(widget));
}

void test() {
	gadget *gp;
	widget *wp;
	
	 
	wp = (widget *)returnRealloc(gp);			/* Violation */
}

int MEM08_main() { 
	gadget *gp;
	widget *wp;
	
	test();
	wp = (widget *)returnRealloc(gp);			/* Violation */
	
	/* ... */
	 
	gp = (gadget *)realloc(gp, 20 * sizeof(widget));	 
	
	return 0;
}
