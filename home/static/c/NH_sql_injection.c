void sql_injection1(char *x){
  char *str = malloc(200);
  char *s;
  fscanf(stdout, "%s",str); //Source 
  if (str == 0) return;
  sprintf(s, "%s", str ); //Tobe Event 
  SQLExecDirect(s); //@violation SQL_INJECTION SINK
  free(str);
}

void sql_injection2(char *x){ 
  char *str = x; //Source 
  char *s = malloc(200); //Appear
  if(s == 0) return;
  sprintf(s, "%s", str);  //Tobe Event 
  SQLExecDirect(s); //@when option is on = violation SQL_INJECTION  Sink
  free(s);
}

void sql_injection3(char *x){
  char *str = x; //Source 
  char *s = malloc(200); //appear
  if(s == 0) return;
  sprintf(s, "UPDATE %s", str ); //Tobe Event 
  SQLExecDirect(s); //@when option is on = violation SQL_INJECTION  Sink
  free(s);
}
