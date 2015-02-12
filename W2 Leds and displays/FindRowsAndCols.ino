// Deze sketch kun je gebruiken om erachter te komen hoe
// de LED matrix is aangesloten aan je arduino

// Definieer welke range aan pinnen zijn aangesloten op je matrix
const int startPin = 2;
const int endPin = 17;

// verander deze waarde in true als je de rijen aan
// wilt zetten in plaats van de kolommen
boolean testColumns = true;

// De actieve pin wordt steeds veranderd
int activePin = startPin;

void setup()
{
  // Zet alle pinnen van de LED matrix op OUTPUT
  for (int iPin = startPin; iPin <= endPin; iPin++)
    pinMode(iPin, OUTPUT);

  // Via de USB poort kunnen we zien welke pin actief is en dit koppelen
  // aan onze waarnemingen van de LED matrix
  Serial.begin(9600);
    Serial.print("Enter active ");
}

// functie waarmee je snel alle pinnen HIGH of LOW kunt zetten
void digitalWriteAll(int mode)
{
  for (int iPin = startPin; iPin <= endPin; iPin++)
    digitalWrite(iPin, mode);
}

byte colPins [] = {255, 255, 255, 255, 255, 255, 255, 255, -1};
byte rowPins [] = {255, 255, 255, 255, 255, 255, 255, 255, -1};

void displayArray(byte array[], char *varName) {
  Serial.print("byte "); Serial.print(varName);
  Serial.print(" [] = {");
  for (int i = 0; i < 7; i++) {
    if (array[i] < 255)
      Serial.print(array[i]);
    Serial.print(",");
  }
  Serial.print(array[7]);
  Serial.println("};");
}

void loop()
{
  if (testColumns)
  {
    // de stroomrichting is bepalend voor welke LEDs er aan gaan
    // Alles staat HIGH en alleen de actieve pin staat LOW
    digitalWriteAll(HIGH); // zet alle pinnen HIGH
    digitalWrite(activePin, LOW); // zet activePin LOW
  }
  else
  {
    // de stroomrichting is bepalend voor welke LEDs er aan gaan
    // Alles staat LOW en alleen de actieve pin staat HIGH
    digitalWriteAll(LOW);
    digitalWrite(activePin, HIGH); // zet activePin LOW
  }

  Serial.print("Enter active ");
  Serial.print(testColumns ? "column" : "row");
  Serial.print(" (1-8) 0 or 9 nothing happens. Currently active pin:");
  Serial.println(activePin); // Schrijf welke pin actief is

  while (!Serial.available()) {}
  while (Serial.available()) {
    byte selectedRowCol = Serial.parseInt();

    if (selectedRowCol > 0 && selectedRowCol < 9) {
      selectedRowCol--;
      if (testColumns)
        colPins[selectedRowCol] = activePin;
      else
        rowPins[selectedRowCol] = activePin;
    }
  }

  displayArray(rowPins, "rowPins");
  displayArray(colPins, "colPins");

  if (++activePin > endPin){
    activePin = startPin;
    testColumns = !testColumns;
  }
}


