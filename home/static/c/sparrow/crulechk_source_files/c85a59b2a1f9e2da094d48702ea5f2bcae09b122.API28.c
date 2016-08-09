#define PFM_TRY(X) X
#define PFM_CATCH catch

void funcOne(int o);
void funcTwo(int t);

extern void badUsage(void) {
    PFM_TRY(funcOne(1));
    PFM_CATCH :
    PFM_TRY(funcTwo(2)); 	/* Violation : out of block */
    /* do something */
}

extern void goodUsage(void) {
    PFM_TRY(funcOne(1));
    PFM_TRY(funcTwo(2));
    PFM_CATCH :
	  funcOne(1);
     /* do something */
}
