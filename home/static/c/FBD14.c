// Dummy function
void printf(char * msg) {
	return;
}

void badFunc()
{
    printf("Message");          /* Violation */
	/* do something */
}

void goodFunc()
{
	/* do something */
}
