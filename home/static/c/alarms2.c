#include <stdlib.h> 

void *my_malloc(int n){
  void *ret = malloc(n);
  if (ret == 0) exit(0);
  return ret;
}

struct List {
  struct List * next;
  char * buf;
  int *a;
  char *x;
  char *y;
};

typedef struct _S {
	char *p1;
	char *p2;
} S;

int G = -1;

// overwriting
int foo1(int arg1)
{
	char *p1;
	char *p2;
	int y = 10;
	p1 = (char *)my_malloc(sizeof(char)*10); // memory leak - 1
	
	if( p1 == 0) 
	  return 1;
	
	p2 = (char *)my_malloc(sizeof(char)*10);
	if( p2 == 0)	{
	  if(p1 != 0){
	    free(p1);
	  }
	  return 2;
	}
	p1 = p2;
	free(p1);
	return 0; //@violation LEAK.MEMORY
}

void pointer(char **p, char* s)
{
	*p = s;
}

// interprocedural alias
int foo2 (int arg1)
{
	char str[10] ="STRING";
	char *p1;
	char *p2;
	p1 = (char *)my_malloc(sizeof(char)*10); // no leak
	if( p1 == 0) {
		return 1;
	}
	pointer(&p2,p1);
	free(p1);
	return 0;	
}

int foo3 (int arg1)
{
	S *p;
	char str1[10] = "STRING 1";
	char str2[10] = "STRING 2";

	p = (S*)my_malloc(sizeof(S));
	if( p == 0)
		return -1;

	p->p1 = (char *)my_malloc(sizeof(char)*10);
	if( p->p1 == 0) {
		free(p);
		return -1;
	}

	p->p2 = (char *)my_malloc(sizeof(char)*10); // memory leak - 2 
	if( p->p2 == 0){
		if( p->p1 != 0) 
			free(p->p1);
		free(p);
		return -1;
	}

	free(p->p1);	
	//free(p->p2);
	free(p);	
	return arg1; //@violation LEAK.MEMORY
}

struct List * make_list(int n) {
  int i;
  struct List* hd = (struct List*)my_malloc(sizeof(struct List));
  struct List* p = hd; 
  for (i=0; i<n; i++) {
    p->next = (struct List *)my_malloc(sizeof(struct List)); 
    p = p->next;
  }
  p->next = 0;
  return hd;
}

void free_list(struct List* hd) {
    free(hd);
}

// Free data structure
void foo4() {
  struct List* l = make_list(10); // memory leak - 3
  free_list(l); 
}

struct List * newNode(){
  struct List * node;
  node = (struct List *) my_malloc(sizeof(struct List));
  node->a = (int *) my_malloc(sizeof(int));
  return node;
}


int freeNode(struct List *node){
  free(node);
  //free(node->a);
  return 0;
}

// allocate and free structure
void foo5(){
  struct List *root;
  root = newNode();         // memory leak - 4 
  root->next = newNode();  // memory leak - 5 
  freeNode(root->next);
  freeNode(root);
  return; //@violation LEAK.MEMORY //@violation LEAK.MEMORY 
} 

// infinite loop 
void foo6(){
  int i, *p = my_malloc(100);   // memory leak - 6 
  for(i=0;i>0;i++){
    if(G){
      free(p);
      return;
    }
  }
  return; //@violation LEAK.MEMORY 
}

void buffer_free(struct List **m){
  free((*m)->buf);
  //free(*m);
}

void buffer_init(struct List **x){
  (*x)->buf = (char *) my_malloc(10);
}

// allocation to argument 
void foo7()
{
        struct List *m;
	m = (struct List *)my_malloc(sizeof(struct List)); // memory leak - 7
	buffer_init(&m);    
	buffer_free(&m); 
        return; //@violation LEAK.MEMORY 
}


struct List* ra(char * dst, char *src){
  struct List *p;
  p = (struct List *)my_malloc(sizeof(struct List));
  p->x = dst;
  //p->y = src;
  return p;
}

// interprocedural aliasing between argument and return address 
struct List * foo8(){
  char * p = my_malloc(10);
  char * q = my_malloc(10);  // memory leak - 8
  struct List * pp;
  pp = ra(p,q);
  return pp; //@violation LEAK.MEMORY 
}

// recursion
int * foo9(int n){
  int *y = my_malloc(10); // memory leak - 9
  if(n>0){
    //    free(y);
    return make(n-1); //@violation LEAK.MEMORY 
  } else {
    free(y);
    return my_malloc(10);
  }
}
 
