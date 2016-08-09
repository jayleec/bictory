// @checker BAD_ARGS.FORBIDDEN.AFTER_CALL

#define API07_TARGET_NAME "Running message"

void API07_FUNC();
void output(const char *);

void run_termnate() 
{ 
    API07_FUNC();
    output(API07_TARGET_NAME); // @violation BAD_ARGS.FORBIDDEN.AFTER_CALL
} 