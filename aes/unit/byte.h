#pragma once

#include<iostream>
#include <iomanip>

using namespace std;

class Byte {
    public:
        typedef unsigned char byte;
        byte value;
        Byte();    
        Byte(byte b);
        Byte operator + (Byte const &obj);
        Byte operator - (Byte const &obj);
        Byte operator * (Byte const &obj);
        bool operator & (Byte const &obj);
        Byte& operator += (Byte const &obj);
        friend ostream& operator<<(ostream& output, const Byte& b);

    private:
        Byte xtime(Byte b);
};    