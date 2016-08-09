void badLoop(void)
{
    int i = 0;
    for (i = 0; i < 10 ; ++i) {
        int k = i;    /*  Violation : shall not be declared */
        /* do something */
    }
        /* do something */
}

void goodLoop(void)
{
    int i = 0;
    int k;
    for (i = 0; i < 10 ; ++i) {
        k = i;
    }
        /* do something */
}
