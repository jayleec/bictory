typedef int S32;

void badParamProto(int badIndex, int badIndex2); /* Violation */
void goodParamProto(S32 index);

void badParam(int badIndex, int badIndex2) /* Violation */
{
    /* do something */
}

void goodParam(S32 index)
{
   /* do something */
}

