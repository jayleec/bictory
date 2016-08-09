# 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_GETLOGIN_IN_MULTI_THREAD.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_GETLOGIN_IN_MULTI_THREAD.c"
struct passwd {
 int pw_gid;
};
extern int getlogin();
extern struct passwd * getpwnam(int);
extern int isTrustedGroup(int);

int foo() {
  struct passwd * pwd = getpwnam(getlogin());
  if(isTrustedGroup(pwd->pw_gid))
    return 1;
  else
    return 0;
}
