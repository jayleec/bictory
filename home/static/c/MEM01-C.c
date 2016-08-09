/* MEM01-C. Store a new value in pointers immediately after free() */

char value_1 = 'a';
char value_2 = 'a';

void mem01_bad1(){
  char *message = malloc(100);
  int message_type;
  
  scanf("%d", &message_type);
  
  /* Initialize message and message_type */
 
  if (message_type == value_1) {
    /* Process message type 1 */
    free(message);
  }
  /* ...*/
  if (message_type == value_2) {
    /* Process message type 2 */
    free(message); //@violation DOUBLE_FREE
    return;
  }

  return; //@violation LEAK.MEMORY 
}

void mem01_good1(){
  char *message = malloc(100);
  int message_type;
  int n = 0;
  
  scanf("%d", &message_type);
  
  /* Initialize message and message_type */
  
  if (message_type == value_1) {
    /* Process message type 1 */
    free(message);
    message = 0;
  }
  /* ...*/
  if (message_type == value_2 && message != 0) {
  /* Process message type 2 */
    free(message); 
    message = 0;
  }

  if(message != 0) free(message);
}
