/* The solution to the deadlock problem is to use a predefined order for the locks in the deposit() function. In the following compliant solution, each thread will lock an the basis of the bank_account ID, defined in the struct initialization. This solution prevents the circular wait problem. */

typedef struct {
  int balance;
  pthread_mutex_t balance_mutex;
  unsigned int id; /* should never be changed after initialized */
} bank_account;
 
unsigned int global_id = 1;
 
void create_bank_account(bank_account **ba, int initial_amount) {
  int result;
  bank_account *nba = malloc(sizeof(bank_account));
  if (nba == NULL) {
    /* Handle Error */
  }
 
  nba->balance = initial_amount;
  result = pthread_mutex_init(&nba->balance_mutex, NULL);
  if (result != 0) {
    /* Handle Error */
  }
 
  nba->id = global_id++;
  *ba = nba;
}
 
 
void *deposit(void *ptr) {
  deposit_thr_args *args = (deposit_thr_args *)ptr;
  int result;
 
  if (args->from->id == args->to->id)
        return;
 
  /* ensure proper ordering for locking */
  if (args->from->id < args->to->id) {
    if ((result = pthread_mutex_lock(&(args->from->balance_mutex))) != 0) {
      /* Handle Error */
    }
    if ((result = pthread_mutex_lock(&(args->to->balance_mutex))) != 0) {
      /* Handle Error */
    }
  } else {
    if ((result = pthread_mutex_lock(&(args->to->balance_mutex))) != 0) {
      /* Handle Error */
    }
    if ((result = pthread_mutex_lock(&(args->from->balance_mutex))) != 0) {
      /* Handle Error */
    }
  }
 
  /* not enough balance to transfer */
  if (args->from->balance < args->amount) {
    if ((result = pthread_mutex_unlock(&(args->from->balance_mutex))) != 0) {
      /* Handle Error */
    }
    if ((result = pthread_mutex_unlock(&(args->to->balance_mutex))) != 0) {
      /* Handle Error */
    }
    return;
  }
 
  args->from->balance -= args->amount;
  args->to->balance += args->amount;
 
  if ((result = pthread_mutex_unlock(&(args->from->balance_mutex))) != 0) {
    /* Handle Error */
  }
  if ((result = pthread_mutex_unlock(&(args->to->balance_mutex))) != 0) {
    /* Handle Error */
  }
 
 
  free(ptr);
  return;
}
