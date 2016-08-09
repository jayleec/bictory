/* MSC13-C. Detect and remove unused values */

int* foo();
int* bar();
int baz();

void func_msc13_c
{
	int *p1;
	int *p2;
	p1 = foo();
	p2 = bar();
	 
	if (baz()) {
	  return p1;
	}
	else {
	  p2 = p1;
	}
	return p2;

}
