int g = 0;

void *mymalloc(int size){
  void *x = malloc(size);
  if(x == 0) exit(1);
  return x;
}

void test_nd_aux1(int a, int* p) {
    if(a > 0) {
        *p = 0;
    }

    if(a > 10) {
	*p = 12;
    }
}

void test_nd(int a) {
    int *p = 0;

    if(a > 10) {
        p = &g;
    }

    test_nd_aux1(a, p); //@violation NULL_DEREF
}

typedef struct _Data {
    int num;
    char *d1;
    char *d2;
} Data;

Data* make_data(int num, int d1, int d2) {
    Data* d;
    d = (Data*)mymalloc(sizeof(Data));
    d->num = num; 
    d->d1 = (char*)mymalloc(d1);
    d->d2 = (char*)mymalloc(d2);

    return d;
}

void delete_data(Data *d) {
    if(d == 0) return;
    free(d->d1);
    free(d);
}

extern int g;
Data* test_memory_leak() {

    Data *d;

    d = make_data(1, 10, 10);
    if(g < -1) {
        delete_data(d);
        return -1; //@violation LEAK.MEMORY
    }

    return d;
}

typedef struct _Data2 {
    char buf[100];
} Data2;

int test_buffer_overrun_aux(char* buf, int n) {

    return buf[n];
}

int test_buffer_overrun() {
    Data2 d;

    int n;

    n = test_buffer_overrun_aux(d.buf, 200); //@violation TYPE_OVERRUN.STATIC

    return n;
}

void test_useafter_free_aux(int* p) {
    if(p == 0) return;

    *p = 2;
}

void test_useafter_free() {
    int *p;

    p = (int*)mymalloc(sizeof(int));

    *p = 1;

    free(p);

    test_useafter_free_aux(p); //@violation USE_AFTER_FREE 
}


void test_double_free_aux(int* p) {
    if(p == 0) return;

    *p = 2;
    free(p); 
}

void test_double_free() {
    int *p;

    p = (int*)mymalloc(sizeof(int));

    *p = 1;

    test_double_free_aux(p);

    free(p); //@violation DOUBLE_FREE
}

int make_num(int p) {
    switch(p) {
        case 1:
            return 10;
        case 2:
            return 25;
        case 3:
            return 40;
        case 4:
            return 0;
        default:
            return 1;
    }
}

int test_divide_by_zero_aux(int m) {
    return 100/m * 75;
}

int test_divide_by_zero(int p) {

    int m;

    m = make_num(p);

    return test_divide_by_zero_aux(m); //@violation DIV_BY_ZERO

}

char* test_free_nonheap_variable_aux() {
     char buf[100];

     return buf; //@violation RETURN_LOCAL
}

void test_free_nonheap_variable() {

    char* data;
    data = test_free_nonheap_variable_aux();

    if(data != 0) {
      free(data); //@violation FREE_NON_HEAP
    }

}

int test_uninitialized_aux(int m, int *n) {
    switch(m) {
        case 1:
            *n = 100;
            break;
        case 2:
            *n = 250;
            break;
        case 3:
            break;
        default:
            *n = 1;
            break;
    }

    return;
}

int test_uninitialized(int m) {
    int d;

    test_uninitialized_aux(m, &d);

    return d * 1000 - 20; //@violation UNINIT
}


