/*
       Morse Code Converter
          Final Version

                    -Domantas Lankutis
*/

#include <HashMap.h>
#include <LiquidCrystal.h>

const int buzzerPin = 9;
const int ledPin = 13;
const int DELAY = 200;
const int NOTE_DURATION = 100;
const int FREQUENCY = 1000;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char letter;

const byte HASH_SIZE = 27;
HashType<char,char*> hashRawArray[HASH_SIZE];
HashMap<char,char*> hashMorse = HashMap<char, char*>(hashRawArray, HASH_SIZE);

void setup() {
  Serial.begin(9600);
  
  hashMorse[0]('a',"cd");               // Circle = "c"
  hashMorse[1]('b',"dccc");             // Dash   = "d"
  hashMorse[2]('c',"cdcd");
  hashMorse[3]('d',"dcc");
  hashMorse[4]('e',"c");
  hashMorse[5]('f',"ccdc");
  hashMorse[6]('g',"ddc");
  hashMorse[7]('h',"cccc");
  hashMorse[8]('i',"cc");
  hashMorse[9]('j',"cddd");
  hashMorse[10]('k',"dcd");
  hashMorse[11]('l',"cdcc");
  hashMorse[12]('m',"dd");
  hashMorse[13]('n',"dc");
  hashMorse[14]('o',"ddd");
  hashMorse[15]('p',"cddc");
  hashMorse[16]('q',"ddcd");
  hashMorse[17]('r',"cdc");
  hashMorse[18]('s',"ccc");
  hashMorse[19]('t',"d");
  hashMorse[20]('u',"ccd");
  hashMorse[21]('v',"cccd");
  hashMorse[22]('w',"cdd");
  hashMorse[23]('x',"dccd");
  hashMorse[24]('y',"dcdd");
  hashMorse[25]('z',"ddcc");
  hashMorse[26](' ' ," "); 

  lcd.begin(16,2);
  Serial.println("Device ready...");
}

void loop() {

  lcd.begin(16,2);

  if (Serial.available() > 0){
    letter = Serial.read();
    String tempOut = hashMorse.getValueOf(letter);
    for(int i = 0; i < tempOut.length(); i++){
      Serial.println(tempOut[i]);
      if(tolower(tempOut[i]) == 'c'){
        tone(buzzerPin, FREQUENCY,NOTE_DURATION);
        digitalWrite(ledPin, HIGH);
        lcd.print(".");
        delay(DELAY);
        digitalWrite(ledPin, LOW);
      }
      if(tolower(tempOut[i]) == 'd'){
        tone(buzzerPin, FREQUENCY,NOTE_DURATION*3);
        digitalWrite(ledPin, HIGH);
        lcd.print("_");
        delay(DELAY*2);
        digitalWrite(ledPin, LOW);
      }
    }
    delay(DELAY/4);
  }
}
