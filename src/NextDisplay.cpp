#include "NextDisplay.h"
#include "NextDisplayFont.cpp" // Inclui a definição da matriz de dados das letras

// Construtor da classe
NextDisplay::NextDisplay() {
  // Configura os pinos das linhas como saída
  for (int i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH); // Inicializa em desligado (HIGH, porque estamos usando LOW para ligar)
  }
  // Configura os pinos das colunas como saída
  for (int i = 0; i < 5; i++) {
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], LOW); // Inicializa desligado (LOW)
  }
}

// Exibir uma letra na matriz de LEDs
void NextDisplay::displayLetter(int letterIndex) {
  for (int t = 0; t < 20; t++) { // Tempo que a letra ficará ativa 
    for (int i = 0; i < 8; i++) {
      digitalWrite(rows[i], LOW); // Liga a linha
      for (int j = 0; j < 5; j++) {
        if (font[letterIndex][i][j] == 1) {
          digitalWrite(cols[j], HIGH); // Liga a coluna
          }
        delay(1); // Pequena demora para que o LED acenda de uma forma visivel
        digitalWrite(cols[j], LOW); // Desliga a coluna
      }
      digitalWrite(rows[i], HIGH); // Desliga a linha
    }
  }
}

// Exibe a letra escolhida na matriz
void NextDisplay::displayChosenLetter(char input) {
 int index;
    
    if (input >= 'a' && input <= 'z') {
        index = input - 'a'; // Letras minúsculas
    } else if (input >= 'A' && input <= 'Z') {
        index = input - 'A'; // Letras maiúsculas
    } else if (input >= '0' && input <= '9') {
        index = input - '0' + 26; // Números de 0 a 9
    } else {
        switch(input) {
          case 'Ç': index = 36; break;
          case 'Ê': index = 37; break;
          case 'Á': index = 38; break;
          case 'É': index = 39; break;
          case 'Ã': index = 40; break;
          case 'Ó': index = 41; break;
          default: return; // Caractere não suportado
        }
    }
    
    displayLetter(index); // Exibe a letra ou número correspondente na matriz de LEDs
}

// Exibir todo o alfabeto na matriz
void NextDisplay::displayFont() {
  for (int k = 0; k < 42; k++) { // Loop para percorrer todas as letras do alfabeto
    for (int t = 0; t < 500; t++) { // Exibir cada letra por um tempo (ajuste conforme necessário)
      displayLetter(k);
    }
    delay(500); // Pequena pausa entre as letras
  }
}
