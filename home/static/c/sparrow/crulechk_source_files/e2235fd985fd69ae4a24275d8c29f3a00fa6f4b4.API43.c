// Prototype definition for the test
void pfmDbioCommit();
void pfmDbioRollback();

void badDBIOWithoutRollback(void)
{
    pfmDbioCommit();  /* Violation : without rollback function */
    /* do something */
    
}

void badDBIOWithoutCommit(void)
{
    pfmDbioRollback();  /* Violation : without rollback function */
    /* do something */
    
}

void goodDBIO(void)
{
    pfmDbioCommit();
    /* do something */
    
    pfmDbioRollback();
    /* do something */
}