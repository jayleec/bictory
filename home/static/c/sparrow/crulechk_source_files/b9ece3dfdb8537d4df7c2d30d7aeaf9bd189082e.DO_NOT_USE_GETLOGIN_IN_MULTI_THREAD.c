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
