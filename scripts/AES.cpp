#include <stdio.h>

typedef unsigned char byte; 

struct word{
	byte w[4];
};

void hex(byte a){
	printf("0x%x ",a);
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

word operator +(word in_1,word in_2){
	word result;
	for(int i=0; i<4; i++) result.w[i] = in_1.w[i]^in_2.w[i];
	
	return result;
}

word operator *(word a,word b){
	word result;
	
	result.w[0] = (mult(a.w[0],b.w[0]))^(mult(a.w[3],b.w[1]))^(mult(a.w[2],b.w[2]))^(mult(a.w[1],b.w[3]));
	result.w[1] = (mult(a.w[1],b.w[0]))^(mult(a.w[0],b.w[1]))^(mult(a.w[3],b.w[2]))^(mult(a.w[2],b.w[3]));
	result.w[2] = (mult(a.w[2],b.w[0]))^(mult(a.w[1],b.w[1]))^(mult(a.w[0],b.w[2]))^(mult(a.w[3],b.w[3]));
	result.w[3] = (mult(a.w[3],b.w[0]))^(mult(a.w[2],b.w[1]))^(mult(a.w[1],b.w[2]))^(mult(a.w[0],b.w[3]));
	
	return result;
}
/**Cipher**/

void SubBytes(){
	
	}

void ShiftRows(){
	
	}

void MixColumns(){
	
	}

void AddRoundKey(){
	
	}

/**Key Expansion**/

void KeyExpansion(){

}
	
void SubWord(){

}

void RotWord (){
	
} 

/**Inverse Cipher**/

void InvSubBytes(){
	
}

void InvShiftRows(){
	
	}

void InvMixColumns(){

	
	}

int main(){
	byte a=0x57;
	byte b=0x13;
	hex(a);
	printf(" * ");
	hex(b);
	printf(" = ");	
	hex(mult(a,b));
	printf("\n");	
	
	word data1, data2, data3, prueba;
	data1.w[0]=data1.w[1]=data1.w[2]=data1.w[3]= 0x57;
	data2.w[0]=data2.w[1]=data2.w[2]=data2.w[3]= 0x83;
	
	prueba = data1 + data2;
	
	data3.w[0] = 0x00;
	data3.w[1] = 0x00;
	data3.w[2] = 0x00;
	data3.w[3] = 0x01; 
	
	data2.w[0] = 0x34;
	data2.w[1] = 0x67;
	data2.w[2] = 0x1a;
	data2.w[3] = 0x8b; 
	
	
	
	hex(prueba.w[0]);
	printf("\n");	
	
	prueba = data3 * data2;
	
	hex(prueba.w[0]);
	hex(prueba.w[1]);
	hex(prueba.w[2]);
	hex(prueba.w[3]);
	
	return 0;
}
