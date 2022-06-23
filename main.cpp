#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

unsigned char StringToBinary(const string& str);

int main() {
    unsigned char ab = 0xFF;

//    cout << dec << (unsigned short int)ab << endl;
//    cout << hex << (unsigned short int)ab << endl;
//
//    cout << dec << (unsigned short int)(ab >> 2) << endl;
//    cout << hex << (unsigned short int)(ab >> 2) << endl;
//
//    cout << dec << (unsigned short int)(ab << 2) << endl;
//    cout << hex << (unsigned short int)(ab << 2) << endl;

    unsigned char x = 0xAA;

//    cout << "----" << endl;
//    cout << hex << (ab & x) << endl;
//    cout << hex << (ab | x) << endl;

    const unsigned char BIT0 = 0x01;
    const unsigned char BIT1 = 0x02;
    const unsigned char BIT2 = 0x04;
    const unsigned char BIT3 = 0x08;
    const unsigned char BIT4 = 0x10;
    const unsigned char BIT5 = 0x20;
    const unsigned char BIT6 = 0x40;
    const unsigned char BIT7 = 0x80;

    unsigned char y = 0x0;

//    y = y | BIT0;
//    cout << hex << (unsigned short int)y << endl;
//    y = 0x0;
//    y = y | BIT1;
//    cout << hex << (unsigned short int)y << endl;
//    y = 0x0;
//    y = y | BIT0 | BIT2 | BIT7;
//    cout << hex << (unsigned short int)y << endl;

    string binary = "0000100011111";

    cout << hex << (unsigned short int)StringToBinary("00000000") << endl;
    cout << hex << (unsigned short int)StringToBinary("11111111") << endl;
    cout << hex << (unsigned short int)StringToBinary("10001000") << endl;
    cout << hex << (unsigned short int)StringToBinary("1111") << endl;

    unsigned int bytes = binary.length() % 8 == 0 ? binary.length() / 8 : binary.length() / 8 + 1;
    char* data = new char[bytes];

    data[0] = StringToBinary(binary.substr(0, 8));
    data[1] = StringToBinary(binary.substr(8, 8));

    cout << hex << (unsigned short int)data[0] << endl;
    cout << hex << (unsigned short int)data[1] << endl;

    delete[] data;
    return 0;
}


unsigned char StringToBinary(const string& str){
    // "00000001" --- > 1
    // "11111111" --- > 255
    assert(str.length() <= 8);
    unsigned char retVal = 0x0;
    for (int i = str.length() - 1; i >= 0; --i) {
        assert(str[i] == '0' || str[i] == '1');
        if (str[i] == '1')
            retVal += (unsigned char)pow(2, str.length() - i - 1);
    }
    return retVal;
}
