void badFoo(void)
{
    double angle = 0.0;
    
    if (angle == 45.5) {
		/* do something */
    }
}

void goodFoo(void)
{
    double angle = 0.0;

    if ((int)angle == 45) {
        /* do something */
    }
}
