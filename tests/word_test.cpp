#include "../aes/byte.h"
#include<stdio.h>


int main(){
    Byte a(0x57), b(0x83);
    Byte c;

    c = a + b;

    printf("0x%x ", c.value);        
    
    return 0;
}