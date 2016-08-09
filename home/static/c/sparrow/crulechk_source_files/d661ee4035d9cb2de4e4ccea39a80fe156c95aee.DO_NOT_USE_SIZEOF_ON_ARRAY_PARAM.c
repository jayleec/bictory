// @checker DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM

void do_not_use_sizeof1(int a[]){
	int i;
	for(i = 0; i< sizeof(a) / sizeof(a[0]); i++) // @violation DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
		a[i] = 0;
}

