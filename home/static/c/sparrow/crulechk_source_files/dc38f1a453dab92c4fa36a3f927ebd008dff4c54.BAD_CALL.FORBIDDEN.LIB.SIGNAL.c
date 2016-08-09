// @checker BAD_CALL.FORBIDDEN.LIB.SIGNAL

#define SIGINT 0
// Dummy function
void signal_FB10(int, void(*)());
void handler();

void signal_handler(){
	signal_FB10(SIGINT, handler); // @violation BAD_CALL.FORBIDDEN.LIB.SIGNAL
}
