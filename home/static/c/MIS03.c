#define MAX 10
#define EXCLUDED 20

extern int getMax(void) {
	int a = MAX;
	int b = EXCLUDED;
	
#define MAX 20   /* Violation : duplicated macro */
#define EXCLUDED 40 /* Violation but excluded */
    // do something
    return MAX + EXCLUDED;
}
