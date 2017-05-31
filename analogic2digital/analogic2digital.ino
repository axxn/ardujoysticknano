const int XPin = A0;
const int YPin = A1;
const bool ACTIVE = HIGH;
const bool INACTIVE = LOW;

const int pinUP = 13;
const int pinDOWN = 12;
const int pinLEFT = 11;
const int pinRIGHT = 10;

int Xvalue;      //variable que almacena la lectura analógica raw
int Xposition;   //posicion del potenciometro en tanto por ciento
int XprevPosition = 50;

int Yvalue;      //variable que almacena la lectura analógica raw
int Yposition;   //posicion del potenciometro en tanto por ciento
int YprevPosition = 50;

void setup() {
  Serial.begin(9600);
  Serial.println("Go on, mate...");
  pinMode(pinUP, OUTPUT);
  pinMode(pinDOWN, OUTPUT);
  pinMode(pinLEFT, OUTPUT);
  pinMode(pinRIGHT, OUTPUT);
}

void loop() {
  bool changes = false;
  Xvalue = analogRead(XPin);
  Xposition = map(Xvalue, 0, 1023, 0, 100);  // convertir a porcentaje
  Yvalue = analogRead(YPin);
  Yposition = map(Yvalue, 0, 1023, 0, 100);  // convertir a porcentaje
  if (Xposition > 70) {
    digitalWrite(pinUP, ACTIVE);
    digitalWrite(pinDOWN, INACTIVE);
    Serial.println(Xposition);
  } else if (Xposition < 30) {
    digitalWrite(pinUP, INACTIVE);
    digitalWrite(pinDOWN, ACTIVE);
  } else {
    digitalWrite(pinUP, INACTIVE);
    digitalWrite(pinDOWN, INACTIVE);
  }
//  delay(20);
}

