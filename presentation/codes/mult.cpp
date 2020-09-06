typedef unsigned char byte; 

byte mult(byte in_1, byte in_2){
	byte mask=0x01, result=0x00, piv=in_1;

	for(int i=0; i<8; i++){
		if(in_2 & mask) result^=piv;
		mask = mask << 1;
		piv = xtime(piv);
	}

	return result;
}