# 1 "/home/kskyj/sparrow4/util/testcode/c/API43.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API43.c"

void pfmDbioCommit();
void pfmDbioRollback();

void badDBIOWithoutRollback(void)
{
    pfmDbioCommit();


}

void badDBIOWithoutCommit(void)
{
    pfmDbioRollback();


}

void goodDBIO(void)
{
    pfmDbioCommit();


    pfmDbioRollback();

}
