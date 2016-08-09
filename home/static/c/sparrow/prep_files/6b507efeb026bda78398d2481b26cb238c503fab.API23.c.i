# 1 "/home/kskyj/sparrow4/util/testcode/c/API23.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API23.c"



void set_err(char * type, char * disc);

int badError() {

    return -1;
}

int goodError() {

    set_err("ERRORCode", "error number");
    return -1;
}

int goodError2() {

    set_err("ERRORCode", "error number");
}

int badError2() {

    return -1;
}
