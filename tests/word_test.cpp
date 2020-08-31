#include "../aes/unit/byte.h"
#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    Byte a(0x57), b(0x83);
    Byte c, d;

    c = a + b;
    d = a * b;

    cout << c << endl;   
    cout << d << endl;
    return 0;
}