#include<stdio.h>
#include<stdlib.h>

struct node {
  struct node *next;
  int x;
}

int a,b;

/* void problem(){ */
/*   void *f = fopen("a.txt", "r"); */
/*   void *y; */
/*   char *x = 0; */
/*   if(f == 0) return; */
/*   fclose(f); */
/*   *f = 1; */
/* } */

void use_after_free(){
  int *x = (int*) malloc(10*sizeof(int));
  if(x ==0) return;
  *x = 10;
  free(x);
  *x = 1; //@violation USE_AFTER_FREE
}

void misuse_cursor(void *context){

  pfmDbioOpenCursor("queryname", context, 0, 10);

  pfmDbioFetchCursor("queryname", context);

  pfmDbioCloseCursor("queryname");

  pfmDbioFetchCursor("queryname", context); //@violation USE_AFTER_CLOSE
}

void nice_false_alarm(void *context){
  
  while(1){
    {
      
      pfmDbioFetchCursorArray("test_vf999",9, context);

      if(a && b == 0){
      } else if (!a && b){
	
	pfmDbioCloseCursorArray("test_vf999");
	return 1;
      }
    }
  }
  pfmDbioCloseCursorArray("test_vf999");
}

void mirae_asset_false_alarm(struct node *p){
  int rc;
  rc = unknown();
  while(p != 0){
    pfmDbioFetchCursor("BBBB");
    p = p->next;
    if (rc != 0){
      switch (rc){
      case 1:
	pfmDbioCloseCursor("BBBB");
	
	if (unknown())
	  return;
	else 
	  return;
      }
    }
  }
  return;
}
  
int main(){
  use_after_free();
  return 1;
}




