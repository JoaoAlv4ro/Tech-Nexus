/*////////////////////////////////////////////////////////////////////////////////
 * Arduino code to display characters on a 8x5 LED matriz.
 * Designed for a Integrated Product Development project of the college FATEC Jessen Vidal.
 * Author: João Álvaro                                    
/*////////////////////////////////////////////////////////////////////////////////

#ifndef MATRIZ_8X5_H
#define MATRIZ_8X5_H

#include <Arduino.h>

class MATRIZ_8x5 {
    private:
        int _latchPin1;
        int _clockPin1;
        int _dataPin1;
        int _latchPin2;
        int _clockPin2;
        int _dataPin2;
    public:
    //Clock - Pino 11 do 74HC595 - Relogio Registrador de Deslocamento
    //Latch - Pino 12 do 74HC595 - Relogio Registrador de Saida
    //Data - Pino 14 do 74HC595 - Entrada
        MATRIZ_8x5(int latchPin1, int clockPin1, int dataPin1, int latchPin2, int clockPin2, int dataPin2);
        void matrizStart();
};

#endif  