#include<stdio.h>
#include<iostream>
#include"../aes/unit/byte.h"

using namespace std;

typedef unsigned char byte; 

void hex(byte a){
	printf("0x%x ",a);
}

byte diff(byte in){
    int b = 1<<8;
    byte i=0;
    while(!(b&in)){
        b = b >> 1;
        i++;
    }
    return i;
}

byte shift(byte a, byte b){
    byte i = 0;
    byte j = 1<<(8-diff(a));

    while(!(j & b)) j = j >> 1;
    
    return j;
}

byte shift2(byte a, byte b){
    return diff(b) - diff(a);
}

byte division(byte a, byte b){
    byte i=0x00, j=0x00, s=0x00;
    
    // a is x^8 + x^4 + x^3 + x + 1
    if(a == 0x00)
        i = 0x00;
    else
        i = diff(a);
    j = diff(b);
   
    while(j >= i){
        s += 1<<(j-i);
        a = a ^ (b << (j-i));
        if (!a) return s;
        i = diff(a);
    }
    return s;
}

byte xtime(byte in){
	if(in & 0x80){
		return (in<<1)^0x1b;	
	}
	return in<<1;
}

byte mult(byte in_1, byte in_2){
	byte mask, result, piv;
	mask = 0x01;
	result = 0x00;
	piv = in_1;	
	for(int i=0; i<8; i++){
		if(in_2 & mask) result^=piv;
		mask = mask << 1;
		piv = xtime(piv);
	}
	return result;
}

byte suma(byte in_1, byte in_2){
    return in_1 ^ in_2;
}

byte affine(byte in){
    byte c=0x63, m=0x01, s=0x00, p=0x00;
    byte b_0, b_4, b_5, b_6, b_7;
    for(byte i=0; i<8; i++){
        b_0 = (in&(m<<i))>>i;
        b_4 = (in&(m<<((i+4)%8)))>>((i+4)%8);
        b_5 = (in&(m<<((i+5)%8)))>>((i+5)%8);
        b_6 = (in&(m<<((i+6)%8)))>>((i+6)%8);
        b_7 = (in&(m<<((i+7)%8)))>>((i+7)%8);
        s = (b_0^b_4^b_5^b_6^b_7^((c&(m<<i))>>i));
        p |= (s<<i);
    }

    return p;
}

byte xor_bits(byte x) {
    return __builtin_parity(x);
}

byte rotate(byte in){
    return (in<<1) | (in>>7 & 0x01); 
}

byte affine2(byte in){
    byte c=0x63, m=0x01, s=0x00, p=0x00, t=0xF1;
    for(byte i=0; i<8; i++){
        s = xor_bits(in & t)^((c&(m<<i))>>i);
        t = rotate(t);
        p |= (s<<i);
    }
    return p;
}

byte inv_affine(byte in){
    byte c=0x05, m=0x01, s=0x00, p=0x00, t=0xA4;
    for(byte i=0; i<8; i++){
        s = xor_bits(in & t)^((c&(m<<i))>>i);
        t = rotate(t);
        p |= (s<<i);
    }
    return p;
}

byte euclidean(byte r1){
    // r0 > r1
    if (r1 == 0x00) return 0x00;

    int r0 = 0x11b;

    byte t[3] = {0,  1,  0};
    byte s[3] = {1,  0,  0};
    byte r[3] = {0, r1,  1};

    int q;    

    while(r[2] != 0){
        q = division(r[0], r[1]);
        r[2] = suma(r[0], mult(q, r[1]));
        s[2] = suma(s[0], mult(q, s[1]));
        t[2] = suma(t[0], mult(q, t[1]));

        r[0] = r[1];
        s[0] = s[1];
        t[0] = t[1];
        r[1] = r[2];
        s[1] = s[2];
        t[1] = t[2];
    }
    return t[0];
}

int main(){
    Byte t;
    printf("Sbox(x) \n");
    for(int i=0; i<256; i++){
        t.value = affine(euclidean((byte)(i)));
        cout << t << " ";
		if((i+1) % 16 == 0) cout<<endl;
    }
    printf("\nInvSbox(x) \n");
    for(int i=0; i<256; i++){
        t.value = euclidean(inv_affine((byte)(i)));
        cout << t << " ";
		if((i+1) % 16 == 0) cout<<endl;
    }

    printf("\n F(E(E-1(F-1(x))))\n");
    for(int i=0; i<256; i++){
        t.value = affine(euclidean(euclidean(inv_affine((byte)(i)))));
        cout << t << " ";
		if((i+1) % 16 == 0) cout<<endl;
    }

    printf("\n E(E-1(x)) \n");
    for(int i=0; i<256; i++){
        t.value = euclidean(euclidean((byte)(i)));
        cout << t << " ";
		if((i+1) % 16 == 0) cout<<endl;
    }

    printf("\n F-1(F(x)) \n");
    for(int i=0; i<256; i++){
        t.value = inv_affine(affine((byte)(i)));
        cout << t << " ";
		if((i+1) % 16 == 0) cout<<endl;
    }

    printf("\n F(F-1(x)) \n");
    for(int i=0; i<256; i++){
        t.value = affine(inv_affine((byte)(i)));
        cout << t << " ";
		if((i+1) % 16 == 0) cout<<endl;
    }



    return 0;
}
