// @checker BAD_MALLOC

// Dummy types
typedef unsigned long wchar_t;
typedef wchar_t WCHAR;
typedef unsigned int size_t;

// Dummy functions
void * malloc(size_t);
size_t wcslen(const wchar_t *); 
void free(void *); 

void foo(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc(wcslen(str1) + 1); // @violation BAD_MALLOC 
    free(str2);
}

void bar(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc((wcslen(str1) + 1) * sizeof(wchar_t)); // Safe
    free(str2);
}

void zoo(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc((wcslen(str1) + 1) * sizeof(WCHAR)); // Safe
    free(str2);
}

void coo(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc((wcslen(str1) + 1) * sizeof(size_t)); // @violation BAD_MALLOC
    free(str2);
}

void tar(){
	wchar_t *str3 = (wchar_t *)malloc(50);
	free(str3);
}
