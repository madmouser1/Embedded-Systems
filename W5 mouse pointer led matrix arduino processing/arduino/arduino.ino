int incomingByte = 0;
int x = 0;
int y = 0;
// Max7219 pins
int dataIn = 5;
int load = 3;
int clock = 4;

// define max7219 registers
byte max7219_reg_noop        = 0x00;
byte max7219_reg_digit0      = 0x01;
byte max7219_reg_digit1      = 0x02;
byte max7219_reg_digit2      = 0x03;
byte max7219_reg_digit3      = 0x04;
byte max7219_reg_digit4      = 0x05;
byte max7219_reg_digit5      = 0x06;
byte max7219_reg_digit6      = 0x07;
byte max7219_reg_digit7      = 0x08;
byte max7219_reg_decodeMode  = 0x09;
byte max7219_reg_intensity   = 0x0a;
byte max7219_reg_scanLimit   = 0x0b;
byte max7219_reg_shutdown    = 0x0c;
byte max7219_reg_displayTest = 0x0f;

void putByte(byte data)
{
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(clock, LOW);   // tick
    digitalWrite(dataIn, data & (1 << i)); // send bit
    digitalWrite(clock, HIGH);   // tock
  }  
}

void maxSingle( byte reg, byte col)
{
  digitalWrite(load, LOW);       // begin     
  putByte(reg);                  // specify register
  putByte(col);                  // put data
  digitalWrite(load,HIGH);       // end
}

void initMax7219()
{
  //initiation of the max 7219
  maxSingle(max7219_reg_scanLimit, 0x07);      
  maxSingle(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
  maxSingle(max7219_reg_shutdown, 0x01);    // not in shutdown mode
  maxSingle(max7219_reg_displayTest, 0x00); // no display test
  for (int e = 1; e <= 8; e++) maxSingle(e,0); // empty registers, turn all LEDs off 
  maxSingle(max7219_reg_intensity, 0x0f);    // range: 0x00 to 0x0f
}

void setup ()
{
  Serial.begin(9600);
  
  pinMode(dataIn, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(load,   OUTPUT);
 
  initMax7219();
}

void loop ()
{
  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read();
    x = incomingByte >> 4;
    y = incomingByte;
    
    for (int i = 0; i < 8; i++) 
    {
      maxSingle(i + 1, 0); 
    }
    maxSingle(y + 1, (128 >> x));
  }
}
