typedef int S32;

int badReturnProto(S32 index); /* Violation */
S32 goodReturnProto(int**);

int badReturn(S32 index) /* Violation */
{
    /* do something */
}

S32 goodReturn(S32 index)
{
   /* do something */
}

