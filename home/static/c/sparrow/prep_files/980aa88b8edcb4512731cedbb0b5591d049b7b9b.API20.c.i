# 1 "/home/kskyj/sparrow4/util/testcode/c/API20.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API20.c"




void pfmInitError() {
 return;
}

void badError() {
 int rc = 0;

    if(rc != 0) {
        return -1;
    }
}

void goodError() {
    int rc = 0;

    if(rc != 0) {
        pfmInitError();
        return -1;
    }
}

void badError2() {
 int rc = 0;

    if(rc != 0) {
  if(rc > 1) {
   pfmInitError();
   return -1;
  } else {
   return -1;
  }
    }
}

void goodError2() {
 int rc = 0;
 if(rc != 0) {
        pfmInitError();
        return -1;
    }

 return -1;
}
