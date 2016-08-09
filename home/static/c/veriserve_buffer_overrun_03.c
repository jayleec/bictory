#include <stdio.h>
#include <stdlib.h>

typedef struct SBufferOverrun03 {
	int i;
	char c;
	long l;
	char *buf;
} SBufOver03;

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_01_sub(SBufOver03 *ptr, int size){
    ptr->buf[size] = 0;  // defect
    return 0;
}

int buffer_overrun_03_01_main(){
    int i;
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    buffer_overrun_03_01_sub(&sb,256); //@violation OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_02_05(SBufOver03 *ptr, int size){
    ptr->buf[size] = 0;  // defect
    return 0;
}

void buffer_overrun_03_02_04(SBufOver03 *ptr, int size){
    int i;
    SBufOver03 *p;
    i = size;
    p = ptr;
    buffer_overrun_03_02_05(p,i);
}
void buffer_overrun_03_02_03(SBufOver03 *ptr, int size){
    int i;
    SBufOver03 *p;
    i = size;
    p = ptr;
    buffer_overrun_03_02_04(p,i);
}
void buffer_overrun_03_02_02(SBufOver03 *ptr, int size){
    int i;
    SBufOver03 *p;
    i = size;
    p = ptr;
    buffer_overrun_03_02_03(p,i);
}
void buffer_overrun_03_02_01(SBufOver03 *ptr, int size){
    int i;
    SBufOver03 *p;
    i = size;
    p = ptr;
    buffer_overrun_03_02_02(p,i);
}

int buffer_overrun_03_02_main(){
    int i;
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    buffer_overrun_03_02_01(&sb,256); //@violation OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_x2_05(SBufOver03 *ptr, int size){
    ptr->buf[size] = 0;  // defect
    return 0;
}

void buffer_overrun_03_x2_04(SBufOver03 *ptr, int size){
    buffer_overrun_03_x2_05(ptr,size);
}
void buffer_overrun_03_x2_03(SBufOver03 *ptr, int size){
    buffer_overrun_03_x2_04(ptr,size);
}
void buffer_overrun_03_x2_02(SBufOver03 *ptr, int size){
    buffer_overrun_03_x2_03(ptr,size);
}
void buffer_overrun_03_x2_01(SBufOver03 *ptr, int size){
    buffer_overrun_03_x2_02(ptr,size);
}
int buffer_overrun_03_x2_main(){
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    buffer_overrun_03_x2_01(&sb,256); //@violation OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void buffer_overrun_03_y2_03(SBufOver03 *ptr, int size){
    ptr->buf[size] = 0;  // defect
}
void buffer_overrun_03_y2_02(SBufOver03 *ptr, int size){
    int i;
    SBufOver03 *p;
    i = size;
    p = ptr;
    buffer_overrun_03_y2_03(p,i);
}
void buffer_overrun_03_y2_01(SBufOver03 *ptr, int size){
    int i;
    SBufOver03 *p;
    i = size;
    p = ptr;
    buffer_overrun_03_y2_02(p,i);
}

int buffer_overrun_03_y2_main(){
    int i;
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    buffer_overrun_03_y2_01(&sb,256); //@violation OVERRUN.STATIC
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_03_main(){
    int i;
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    for(i=0; i<256 ; i++ )
        sb.buf[i] = 'a';

    sb.buf[i] = 0;  //@violation OVERRUN.STATIC
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_04_sub(SBufOver03 *ptr, int size){
    ptr->buf[size] = 0;  // defect
    return 0;
}

int buffer_overrun_03_04_main(){
    int i;
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    for(i=0; i<256 ; i++ )
        sb.buf[i] = 'a';

    buffer_overrun_03_04_sub(&sb,i); //@violation OVERRUN.STATIC
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_05_01(int i){

    if(i == 0)
        return 1;
    else
        return 1000;
}

int buffer_overrun_03_05_main(int flg){
    int i;
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    i = buffer_overrun_03_05_01(flg);
    
    sb.buf[i] = 'a'; //@violation OVERRUN.STATIC
    // defect (if flg is not 0)
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_x5_01(int i){

    if(i == 0)
        return 1;
    else
        return -1;
}

int buffer_overrun_03_x5_main(int flg){
    int i;
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    i = buffer_overrun_03_x5_01(flg);
    
    sb.buf[i] = 'a'; //@violation UNDERRUN.STATIC
    // defect (if flg is not 0)
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_03_06_main(int i){
    SBufOver03 sb;
    char buf[256];
    sb.buf = buf;
    
    if( i > 256 )
        return -1;
    else
      sb.buf[i] = 'a'; //@violation OVERRUN.STATIC.BAD_COND
    // defect

    return 0;
}

