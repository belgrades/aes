#pragma once

#include<iostream>
#include <iomanip>

using namespace std;

class Sbox{
    public:
        typedef unsigned char Sbox;
        Sbox value;
        Sbox();    
        Sbox(Sbox b);
        Sbox operator + (Sbox const &obj);
        Sbox operator - (Sbox const &obj);
        Sbox operator * (Sbox const &obj);
        bool operator & (Sbox const &obj);
        Sbox& operator += (Sbox const &obj);
        friend ostream& operator<<(ostream& output, const Sbox& b);

    private:
        Sbox xtime(Sbox b);
};    