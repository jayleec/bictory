void badFoo(void)
{
    unsigned char index = 0;
    int sum = 0;
    do {
        sum += index;
        index++; 
    } while (index < 1000); /* Violation */
}

void goodFoo(void)
{
    int index = 0;
    int sum = 0;
    while (index < 1000) { 
        sum += index;
        index++; 
    }
}    
