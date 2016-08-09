// @checker DO_NOT_USE_SIZEOF_ON_PTR

void do_not_use_sizeof1(int * a){
	int i;
	for(i = 0; i< sizeof(a) / sizeof(a); i++) // @violation DO_NOT_USE_SIZEOF_ON_PTR
		a[i] = 0;
}

