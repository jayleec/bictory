// @checker BAD_CALL.TYPE_MISMATCH.SPRINTF

#include <stdio.h>

void func() {
	char dest[100];
	char src1[100];
	char src2[100];
	sprintf(dest, "%50s%100s", src1, src2); // @violation BAD_CALL.TYPE_MISMATCH.SPRINTF
}
