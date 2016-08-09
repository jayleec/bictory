typedef struct bad {
  char a;
} bad_t;

void badFoo(bad_t badParam) { 	/* Violation: shall use the allowed typedef types. */
  bad_t badVar; 				/* Violation : shall use the allowed typedef types. */
}

typedef struct good {
  char a;
} good_t;

void goodFoo(good_t goodParam) {
  good_t goodVar;
}
