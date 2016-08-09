// @checker IMPROPER_RANDOM_USAGE
#include <time.h>
#include <stdlib.h>

int badRoleSRand() {
	int r;
	srand(10); // @violation IMPROPER_RANDOM_USAGE
	r = rand() % 1000; // @violation IMPROPER_RANDOM_USAGE
	return (r % 6) + 1;
}

int badRoleRand() {
	int r;
	srand((unsigned)time(NULL));
	r = rand() % 1000; // @violation IMPROPER_RANDOM_USAGE
	return (r % 6) + 1;
}

void seedRandom() {
	srandom(time(NULL));
}

int badRoleRandom() {
	int r;
	r = random() % 1000; // @violation IMPROPER_RANDOM_USAGE
	return (r % 6) + 1;	
}

int goodRoleRandom() {
	int r;
	seedRandom();
	r = random() % 1000;
	return (r % 6) + 1;
}

