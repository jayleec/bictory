// @checker BAD_STRUCT_MEMBER_ACCESS

struct st {
	int a;
	int b;
};

void Func(int x) {
	struct st obj;
	int a;
	a = obj.a;
	a = obj.a;
	a = obj.a; // @violation BAD_STRUCT_MEMBER_ACCESS
}
