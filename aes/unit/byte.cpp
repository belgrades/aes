#include "byte.h"

typedef unsigned char byte;

Byte::Byte() : value(0x00){}
Byte::Byte(byte b) : value(b){}

ostream& operator<<(ostream& output, const Byte& b){
    output << "0x" << setfill('0') << setw(2) << right << uppercase << hex << (int) b.value;
    
    return output;
} 

Byte Byte::operator +(Byte const &in){
    Byte result;
    result.value = this->value^in.value; 

    return result;
}

Byte Byte::operator -(Byte const &obj){
    Byte result;
    result.value = this->value^obj.value; 

    return result;
}

Byte& Byte::operator +=(Byte const &in){
    this->value = this->value^in.value;

    return *this;
}

bool Byte::operator &(Byte const &obj){
    return this->value & obj.value;
}

Byte Byte::xtime(Byte b){
	Byte result, mask(0x80);
    
    if(b & mask){
        result.value = (b.value<<1)^0x1b;
        
        return result;	
	}

    result.value = b.value << 1;    
	
    return result;
}

Byte Byte::operator *(Byte const &obj){
    Byte mask(0x01), result, piv(this->value);
	
    for(int i=0; i<8; i++){
		if(mask & obj) result += piv;
		mask.value = mask.value << 1;
		piv = xtime(piv);
	}
	return result;
}