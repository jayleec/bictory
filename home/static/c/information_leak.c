void info_leak(int n){
  char *src = getenv("PARAMETER");
  char *dst = malloc(1000);
  snprintf(dst, 100, "sdjasljsadkl%djasldas%s", n, src);
  
  printf("aaaa%s", dst); //@violation INFORMATION_LEAK
  free(dst);
}
