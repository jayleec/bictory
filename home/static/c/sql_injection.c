/* SQL Injection */
void sql_injection_bad1(int sqlh) {
  char *query = getenv("query_string");
  SQLExecDirect(sqlh, query, SQL_NTS); //@violation SQL_INJECTION
}

/* SQL Injection */
void sql_injection_good1(int sqlh) {
  char *query = getenv("query_string");
  makeSecureString(query);
  SQLExecDirect(sqlh, query, SQL_NTS); 
}


void source_sink(int x){
  int y = source();
  int z = y + 10;

  if(x > 10){
    sink(z); // dangerous!
  }
}

/* SQL Injection */
char* bad_source(int sqlh) {
  char *query = getenv("query_string");
  return query;
}

void sql_injection_bad2(int sqlh) {
  char *x = bad_source(10);
  opus1_print(x);
  SQLExecDirect(sqlh, x, SQL_NTS); //@violation SQL_INJECTION
}
