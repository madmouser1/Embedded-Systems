//Definieer de startpin en de eindpin
const int STARTPIN = 2;
const int ENDPIN = 17;  // pin HIGH9 staat gelijk aan pin A5

void setup()
{
  Serial.begin(9600);
  // zet alle pinnen op output
  for (int iPin = STARTPIN; iPin <= ENDPIN; iPin++)
    pinMode(iPin, OUTPUT);
}

//// setPins hulpfunctie
//// zet een aantal pinnen op HIGH of LOW
//// De indices van de pinnen zijn gedefinieerd in een array (pinArray) die eindigt met het getal -HIGH
//// Of een pin HIGH of LOW wordt gemaakt correspondeerd met de individuele bits in de parameter mode
//void setPins(int *pinArray, unsigned char mode)
//{
//  int iPin = 0;
//  while (pinArray[iPin] > 0)
//  {
//    digitalWrite(pinArray[iPin], (HIGH << iPin) & mode);
//    iPin++;
//  }
//}

void setPins(byte pinArray[], byte pins[]) {
  for (int iPin = 0; iPin < 8; iPin++)
    digitalWrite(pinArray[iPin], pins[iPin]);
}

//void setPins(byte pinArray[], int state) {
//  for (int iPin = 0; iPin < 8; iPin++)
//    digitalWrite(pinArray[iPin], state);
//}

const int NCOLPINS = 8; // aantal kolommen
const int NROWPINS = 8; // aantal rijen

// De actieve kolom wordt telkens gevarieerd
int iActiveCol = 0;
byte rowPins [] = {0,0,0,0,0,0,0,0};
byte colPins [] = {0,0,0,0,0,0,0,0};

// Het plaatje dat wordt getekend bestaat uit een array van 8 bytes
// De individuele bits worden geinterpreteerd als pixels
//unsigned char bitmap[] = {0x3C, 0x7E, 0xFC, 0xF8, 0xF8, 0xFC, 0x7E, 0x3C};

byte bitmap[8][8] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}
};

byte bitmap2[8][8] = {
  {HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW},
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW, LOW},
  {LOW, LOW, HIGH, LOW, LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, HIGH, LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW},
  {LOW, LOW, LOW, LOW, LOW, HIGH, LOW, LOW},
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW},
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH}
};

byte invader[8][8] = {
  {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, LOW},
  {LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, LOW},
  {LOW, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW},
  {LOW, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW},
  {LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
  {LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
  {HIGH, LOW, HIGH, LOW, LOW, HIGH, LOW, HIGH},
  {HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH}
};

byte heart[8][8]={ 
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0}
};


byte lowRow[8] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW };
byte highRow[8] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

void loop()
{
  // TODO:
  // zet alle rij-pinnen op LOW
  // zet alleen de actieve kolom-pin op LOW en alle andere kolom-pinnen op HIGH
  // selecteer een byte uit de bitmap array
  // zet alle rij-pinnen op HIGH, corresponderend met de bits van die byte
  // maak de volgende kolom actief en zorg ervoor dat die niet boven de 7 uitkomt (ons scherm heeft tenslote maar 8 by 8 pixels (0..8))
  // TIP: gebruik een delay om te zien wat er precies gebeurd

}
