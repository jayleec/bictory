// @checker BAD_CALL.FORBIDDEN.LIB.TIMER

void sleep_FB13(unsigned int);

void set_sleep_func(){
   // Do something ...
   
   sleep_FB13(150); // @violation BAD_CALL.FORBIDDEN.LIB.TIMER
}
