// @checker BAD_CALL.FORBIDDEN.LIB.RESOURCE

// Dummy type
struct rlimit {
	int a;
	int b;
};

// Dummy function
void getrlimit_FB09(int, struct rlimit *);

void resource_limit(){  
	struct rlimit rlim;
	getrlimit_FB09(4354, &rlim); // @violation BAD_CALL.FORBIDDEN.LIB.RESOURCE
}
