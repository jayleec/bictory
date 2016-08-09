// @checker EMPTY_BRANCH
void no_else_branch(int arg) {
	if (arg) { // @violation EMPTY_BRANCH
	}
}

void empty_else_branch1(int arg) {
	if (arg) { 
	} else { // @violation EMPTY_BRANCH
	}
}


void empty_else_branch2(int arg) {
	if (arg) {
	} else; // @violation EMPTY_BRANCH
}

void empty_else_branch3(int arg) {
	if (arg) { 
	} else { // @violation EMPTY_BRANCH
		;
	}
}


void empty_else_branch_not_found(int arg) {
	if (arg) { 
	} else {
          int a;
          a = 0;
	}
}


void empty_else_branch_not_found2(int arg) {
	if (arg) { 
	} else {
          while (0) {
          }
	}
}


void no_cases(int arg) {
	int a;
	switch (arg) { // @violation EMPTY_BRANCH
	default:
		a = 1;
	}
}

void empty_case(int arg) {
	int a;
	switch (arg) { 
	case 1: // @violation EMPTY_BRANCH
	case 2:
		a = 1;
	break;
	default:
		a = 2;
	}
}

void no_default(int arg) {
	int a;
	switch(arg) { // @violation EMPTY_BRANCH
	case 1:
		a = 1;
		break;
	}
}

void empty_default(int arg) {
	int a;
	switch (arg) {
	case 1:
		a = 1;
		break;
	default: // @violation EMPTY_BRANCH
		;
	}
}

