#include <stdio.h>
#include <stdlib.h>

typedef struct SBufferOverrun02 {
	int i;
	char c;
	long l;
	char buf[256];
} SBufOver02;

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_01_sub(SBufOver02 *ptr, int size){
    ptr->buf[size] = 0;  
    return 0;
}

int buffer_overrun_02_01_main(){
    int i;
    SBufOver02 sb;
    
    buffer_overrun_02_01_sub(&sb,256); //@violation TYPE_OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_02_05(SBufOver02 *ptr, int size){
    ptr->buf[size] = 0;  // defect
    return 0;
}

void buffer_overrun_02_02_04(SBufOver02 *ptr, int size){
    int i;
    SBufOver02 *p;
    i = size;
    p = ptr;
    buffer_overrun_02_02_05(p,i);
}
void buffer_overrun_02_02_03(SBufOver02 *ptr, int size){
    int i;
    SBufOver02 *p;
    i = size;
    p = ptr;
    buffer_overrun_02_02_04(p,i);
}
void buffer_overrun_02_02_02(SBufOver02 *ptr, int size){
    int i;
    SBufOver02 *p;
    i = size;
    p = ptr;
    buffer_overrun_02_02_03(p,i);
}
void buffer_overrun_02_02_01(SBufOver02 *ptr, int size){
    int i;
    SBufOver02 *p;
    i = size;
    p = ptr;
    buffer_overrun_02_02_02(p,i);
}

int buffer_overrun_02_02_main(){
    int i;
    SBufOver02 sb;
    
    buffer_overrun_02_02_01(&sb,256); //@violation TYPE_OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_x2_05(SBufOver02 *ptr, int size){
    ptr->buf[size] = 0;  // defect
    return 0;
}

void buffer_overrun_02_x2_04(SBufOver02 *ptr, int size){
    buffer_overrun_02_x2_05(ptr,size);
}
void buffer_overrun_02_x2_03(SBufOver02 *ptr, int size){
    buffer_overrun_02_x2_04(ptr,size);
}
void buffer_overrun_02_x2_02(SBufOver02 *ptr, int size){
    buffer_overrun_02_x2_03(ptr,size);
}
void buffer_overrun_02_x2_01(SBufOver02 *ptr, int size){
    buffer_overrun_02_x2_02(ptr,size);
}
int buffer_overrun_02_x2_main(){
    SBufOver02 sb;
    
    buffer_overrun_02_x2_01(&sb,256); //@violation TYPE_OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void buffer_overrun_02_y2_03(SBufOver02 *ptr, int size){
    ptr->buf[size] = 0;  // defect
}
void buffer_overrun_02_y2_02(SBufOver02 *ptr, int size){
    int i;
    SBufOver02 *p;
    i = size;
    p = ptr;
    buffer_overrun_02_y2_03(p,i);
}
void buffer_overrun_02_y2_01(SBufOver02 *ptr, int size){
    int i;
    SBufOver02 *p;
    i = size;
    p = ptr;
    buffer_overrun_02_y2_02(p,i);
}

int buffer_overrun_02_y2_main(){
    int i;
    SBufOver02 sb;
    
    buffer_overrun_02_y2_01(&sb,256); //@violation TYPE_OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_03_main(){
    int i;
    SBufOver02 sb;
    
    for(i=0; i<256 ; i++ )
        sb.buf[i] = 'a';

    sb.buf[i] = 0;  //@violation TYPE_OVERRUN.STATIC
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_04_sub(SBufOver02 *ptr, int size){
    ptr->buf[size] = 0; 
    return 0;
}

int buffer_overrun_02_04_main(){
    int i;
    SBufOver02 sb;
    
    for(i=0; i<256 ; i++ )
        sb.buf[i] = 'a';

    buffer_overrun_02_04_sub(&sb,i); //@violation TYPE_OVERRUN.STATIC
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_05_01(int i){

    if(i == 0)
        return 1;
    else
        return 1000;
}

int buffer_overrun_02_05_main(int flg){
    int i;
    SBufOver02 sb;
    
    i = buffer_overrun_02_05_01(flg);
    
    sb.buf[i] = 'a'; //@violation TYPE_OVERRUN.STATIC
    // defect (if flg is not 0)
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_x5_01(int i){

    if(i == 0)
        return 1;
    else
        return -1;
}

int buffer_overrun_02_x5_main(int flg){
    int i;
    SBufOver02 sb;
    
    i = buffer_overrun_02_x5_01(flg);
    
    sb.buf[i] = 'a'; //@violation TYPE_UNDERRUN.STATIC
    // defect (if flg is not 0)
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_02_06_main(int i){
    SBufOver02 sb;
    
    if( i > 256 )
        return -1;
    else
        sb.buf[i] = 'a';  //@violation TYPE_OVERRUN.BAD_COND

    return 0;
}

