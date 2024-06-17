/*////////////////////////////////////////////////////////////////////////////////
 * Arduino code to display characters on a 8x5 LED matriz.
 * Designed for a Integrated Product Development project of the college FATEC Jessen Vidal.
 * Author: João Álvaro                                    
/*////////////////////////////////////////////////////////////////////////////////

#ifndef NextDisplay_h
#define NextDisplay_h

#include "Arduino.h"

extern bool font[42][8][5]; // Declaração externa da matriz para letras do alfabeto

class NextDisplay {
  public:
    NextDisplay(); // Construtor da classe
    void displayLetter(int letterIndex); // Exibe uma letra na matriz de LEDs
    void displayChosenLetter(char input); // Exibe a letra escolhida na matriz de LEDs
    void displayFont(); // Exibe todo o alfabeto na matriz de LEDs
  private:
    const int rows[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pin Linhas
    const int cols[5] = {10, 11, 12, A0, A1}; // Pin Colunas
};

#endif

