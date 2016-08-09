extern void *CreateFile(const char *path,int a,int b, void *c,int d, int e, void *f){
	  return c;
}

void foo(){
	  void * x = CreateFile("a",1,2,0,3,4,0);
	    fclose(x); // Mismatch.Resource 
}

void main(){
	  foo();
}
