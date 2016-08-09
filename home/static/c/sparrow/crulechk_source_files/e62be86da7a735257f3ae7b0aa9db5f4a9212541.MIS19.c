typedef struct {		/* Violation : shall be divided by alignment(4). */          
	char    pymnt_yn  [  1 + 1];
} a_t;

struct st {				/* It's ok when use alignment: 4(1 + padding 3) + 4 + 4(1 + 1 + 2) + 4 */
	char a;
	int b;
	char c;
	char d;
	short e;
	int k;
};

void mis19() {
	struct st sk;
	char k;
	
	
}
