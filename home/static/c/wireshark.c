/*
  Potential DOS exploit
  Check: PTR-param-unchk-some
    
  This bug is inspired by one which Goanna found in Dovecot during the
  2010 SATE competition <http://samate.nist.gov/SATE2010Workshop.html>.
  
  s is a pointer to a struct, taken in as a parameter. It is not checked
  against 0 before it is dereferenced in line 32. This is is suspicious
  because in other paths (line 26 and 38), it is checked first. The warning
  calls the programmer's attention to the inconsistency, as found by Goanna's
  model-checking capabilities.
*/



struct S {
  int x;
};

int process(int num, struct S *s){
  int ret = 0;
  switch (num){

    case 0:
      if (s){
        ret = s->x;
      }
      break;

    case 1:
      switch(s->x){  //Here, s is not checked against 0 before it is dereferenced.
        /* ... */
      }
      break;

    case 2:
      if (s){
        switch(s->x){
          /* ... */
        }
      }
      break;

    default:
      ret = 5;
      break;
  }
  return ret;
}
