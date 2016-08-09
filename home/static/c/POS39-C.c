void pos39_bad(int sock){
  int num;
  if (recv(sock, (void *)&num, sizeof(int), 0) < 0) {
    /* Handle error */
    return;
  }
  /* num = ntohl(num); */
  printf("a",(unsigned int) num); //@violation INFORMATION_LEAK 
  return; //@violation USE_CORRECT_BYTE_ORDERING
}

void pos39_good(int sock){
  int num;
  if (recv(sock, (void *)&num, sizeof(int), 0) < 0) {
    /* Handle error */
    return;
  }
  num = ntohl(num);
  printf("a",(unsigned int) num); //@violation INFORMATION_LEAK 
  return; 
}
