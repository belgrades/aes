#pragma once
class Byte {
    private:
        unsigned char byte;
    public:
        Byte(unsigned char b);
        Byte operator + (Byte const &obj);
        Byte operator * (Byte const &obj);
        void print();
}; 