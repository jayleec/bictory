#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_01_sub(char *ptr, int size){
    ptr[size] = 0;  // defect
    return 0;
}

int buffer_overrun_04_01_main(){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    buffer_overrun_04_01_sub(buf,256); //@violation OVERRUN.DYNAMIC
    
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_02_05(char *ptr, int size){
    ptr[size] = 0;  // defect
    return 0;
}

void buffer_overrun_04_02_04(char *ptr, int size){
    int i;
    char *p;
    i = size;
    p = ptr;
    buffer_overrun_04_02_05(p,i);
}
void buffer_overrun_04_02_03(char *ptr, int size){
    int i;
    char *p;
    i = size;
    p = ptr;
    buffer_overrun_04_02_04(p,i);
}
void buffer_overrun_04_02_02(char *ptr, int size){
    int i;
    char *p;
    i = size;
    p = ptr;
    buffer_overrun_04_02_03(p,i);
}
void buffer_overrun_04_02_01(char *ptr, int size){
    int i;
    char *p;
    i = size;
    p = ptr;
    buffer_overrun_04_02_02(p,i);
}

int buffer_overrun_04_02_main(){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    buffer_overrun_04_02_01(buf,256); //@violation OVERRUN.DYNAMIC
    
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_x2_05(char *ptr, int size){
    ptr[size] = 0;  // defect
    return 0;
}

void buffer_overrun_04_x2_04(char *ptr, int size){
    buffer_overrun_04_x2_05(ptr,size);
}
void buffer_overrun_04_x2_03(char *ptr, int size){
    buffer_overrun_04_x2_04(ptr,size);
}
void buffer_overrun_04_x2_02(char *ptr, int size){
    buffer_overrun_04_x2_03(ptr,size);
}
void buffer_overrun_04_x2_01(char *ptr, int size){
    buffer_overrun_04_x2_02(ptr,size);
}
int buffer_overrun_04_x2_main(){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    buffer_overrun_04_x2_01(buf,256); //@violation OVERRUN.DYNAMIC
    
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void buffer_overrun_04_y2_03(char *ptr, int size){
    ptr[size] = 0;  // defect
}
void buffer_overrun_04_y2_02(char *ptr, int size){
    int i;
    char *p;
    i = size;
    p = ptr;
    buffer_overrun_04_y2_03(p,i);
}
void buffer_overrun_04_y2_01(char *ptr, int size){
    int i;
    char *p;
    i = size;
    p = ptr;
    buffer_overrun_04_y2_02(p,i);
}

int buffer_overrun_04_y2_main(){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    buffer_overrun_04_y2_01(buf,256); //@violation OVERRUN.DYNAMIC
    
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_03_main(){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    for(i=0; i<256 ; i++ )
        buf[i] = 'a';

    buf[i] = 0;  //@violation OVERRUN.DYNAMIC
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_04_sub(char *ptr, int size){
    ptr[size] = 0;  // defect
    return 0;
}

int buffer_overrun_04_04_main(){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    for(i=0; i<256 ; i++ )
        buf[i] = 'a';

    buffer_overrun_04_04_sub(buf,i); //@violation OVERRUN.DYNAMIC
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_05_01(int i){

    if(i == 0)
        return 1;
    else
        return 1000;
}

int buffer_overrun_04_05_main(int flg){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    i = buffer_overrun_04_05_01(flg);
    
    buf[i] = 'a'; //@violation OVERRUN.DYNAMIC 
    // defect (if flg is not 0)
    
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_x5_01(int i){

    if(i == 0)
        return 1;
    else
        return -1;
}

int buffer_overrun_04_x5_main(int flg){
    int i;
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    i = buffer_overrun_04_x5_01(flg);
    
    buf[i] = 'a'; //@violation OVERRUN.DYNAMIC
    // defect (if flg is not 0)
    
    free(buf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int buffer_overrun_04_06_main(int i){
    char *buf;
    buf = malloc(256);
    if (buf == 0) return -1;
    
    if( i > 256 ){
        free(buf);
        return -1;
    }
    else
        buf[i] = 'a';  //@violation OVERRUN.DYNAMIC

    free(buf);
    return 0;
}

