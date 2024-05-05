#include <MATRIZ_8x5.h>

MATRIZ_8x5::MATRIZ_8x5(int latchPin1, int clockPin1, int dataPin1, int latchPin2, int clockPin2, int dataPin2) {
    pinMode(stcpPin1, OUTPUT);
    pinMode(shcpPin1, OUTPUT);   
    pinMode(dsPin1, OUTPUT);
    
    pinMode(stcpPin2, OUTPUT);
    pinMode(shcpPin2, OUTPUT);
    pinMode(dsPin2, OUTPUT);
};

void MATRIZ_8x5::matrizStart() {
    //Row
    digitalWrite(stcpPin1, LOW);
    shiftOut(dsPin1, shcpPin1, MSBFIRST, ROW);
    digitalWrite(stcpPin1, HIGH);
    
    //Column
    digitalWrite(stcpPin2, LOW);
    shiftOut(dsPin2, shcpPin2, MSBFIRST, COLUMN);
    digitalWrite(stcpPin2, HIGH);
    
    delay(15);
};