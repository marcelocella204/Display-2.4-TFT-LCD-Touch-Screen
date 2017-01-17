// Code provided by Smoke And Wires
// http://www.smokeandwires.co.nz
// This code has been taken from the Adafruit TFT Library and modified
//  by us for use with our TFT Shields / Modules
// For original code / licensing please refer to
// https://github.com/adafruit/TFTLCD-Library

//código adaptado e comentado por Marcelo Cella para o blog http://viciadosemarduino.blogspot.com.br/ com o apoio de
//http://sttamp.com/loja

#include <Adafruit_GFX.h>    // Core graphics library
#include "SWTFT.h" // Hardware-specific library

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
// #define LCD_CS A3 // Chip Select goes to Analog 3
// #define LCD_CD A2 // Command/Data goes to Analog 2
// #define LCD_WR A1 // LCD Write goes to Analog 1
// #define LCD_RD A0 // LCD Read goes to Analog 0

// #define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7
// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000 //use este site para gerar mais cores http://www.barth-dev.de/online/rgb565-color-picker/
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define PINK    0xE0F9
#define GREY    0x630C

SWTFT tft;
// If using the shield, all control and data lines are fixed, and
// a simpler declaration can optionally be used:
// SWTFT tft;

void setup(void) {
  Serial.begin(9600); // inicial comunicação serial
  Serial.println(F("TFT LCD test"));

  tft.reset(); // reinicia o display

  uint16_t identifier = tft.readID(); // identificador do chip do seu display

  Serial.print(F("LCD driver chip: "));
  Serial.println(identifier, HEX);

  tft.begin(identifier);

  Serial.println(F("Benchmark                Time (microseconds)"));

  Serial.print(F("Screen fill              "));
  delay(500);
  Serial.println(F("Done!"));
  delay(500);

  tft.setRotation(1); // seleciona rotação 1 (porta usb voltada para a esquerda)

  tft.fillScreen(BLUE); // preenche a tela inteira com uma cor
  tft.drawRect(0, 0, 320, 240, YELLOW); // desnha uma borda na tela
  tft.drawRect(1, 1, 318, 238, YELLOW); // desenha mais uma linha de borda
  tft.drawRect(10, 135, 300, 15, YELLOW); //desenha a barra em branco/estrutura: Coluna inicial, linha inicial, comprimento, altura
  tft.setCursor(30, 30); //define ponto inicial para o próximo texto/ estrutura: coluna e linha, 320x240 max
  tft.setTextColor(WHITE);  // define cor para o próximo texto
  tft.setTextSize(3);// define o tamanho para o próximo texto
  tft.println("Hello World!");
  tft.setTextSize(2);
  tft.setCursor(10, 190);
  tft.print(F("LCD driver chip: "));
  tft.println(identifier, HEX);
}

void loop(void) {

  for (int x = 0; x < 300; x++) { // exemplo de exibição de números
    tft.setCursor(30, 100); // primeiro exibimos o "texto", fundo azul com letras verdes
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.println(x);
    delay (200);
    tft.setCursor(30, 100); // depois exibimos novamente com "texto" e fundo azul
    tft.setTextColor(BLUE);  // ou seja, exibimos e apagamos para poder fazer o renew de forma simples
    tft.setTextSize(3);
    tft.println(x);

    tft.drawRect(10, 135, x, 15, YELLOW); // preenche a barra de acordo com o valor de x
  }
  tft.fillRect(11, 136, 298, 13, BLUE); // apagamos a barra para o próximo loop do for
}






