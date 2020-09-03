#include "sbox.h"

typedef unsigned char Sbox;

Sbox::Sbox() : value(0x00){}
Sbox::Sbox(Sbox b) : value(b){}

ostream& operator<<(ostream& output, const Sbox& b){
    output << "0x" << setfill('0') << setw(2) << right << uppercase << hex << (int) b.value;
    
    return output;
} 

Sbox Sbox::operator +(Sbox const &in){
    Sbox result;
    result.value = this->value^in.value; 

    return result;
}

Sbox Sbox::operator -(Sbox const &obj){
    Sbox result;
    result.value = this->value^obj.value; 

    return result;
}

Sbox& Sbox::operator +=(Sbox const &in){
    this->value = this->value^in.value;

    return *this;
}

bool Sbox::operator &(Sbox const &obj){
    return this->value & obj.value;
}

Sbox Sbox::xtime(Sbox b){
	Sbox result, mask(0x80);
    
    if(b & mask){
        result.value = (b.value<<1)^0x1b;
        
        return result;	
	}

    result.value = b.value << 1;    
	
    return result;
}

Sbox Sbox::operator *(Sbox const &obj){
    Sbox mask(0x01), result, piv(this->value);
	
    for(int i=0; i<8; i++){
		if(mask & obj) result += piv;
		mask.value = mask.value << 1;
		piv = xtime(piv);
	}
	return result;
}