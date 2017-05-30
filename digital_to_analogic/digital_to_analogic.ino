const int XPin = A0;
const int YPin = A1;

int Xvalue;      //variable que almacena la lectura analógica raw
int Xposition;   //posicion del potenciometro en tanto por ciento
int XprevPosition = 50;

int Yvalue;      //variable que almacena la lectura analógica raw
int Yposition;   //posicion del potenciometro en tanto por ciento
int YprevPosition = 50;

void setup() {
  Serial.begin(9600);
  Serial.println("Go on, mate...");
}

void loop() {
  bool changes = false;
  Xvalue = analogRead(XPin);
  Xposition = map(Xvalue, 0, 1023, 0, 100);  // convertir a porcentaje
  Yvalue = analogRead(YPin);
  Yposition = map(Yvalue, 0, 1023, 0, 100);  // convertir a porcentaje

  if (Xposition != XprevPosition) {
    //...hacer lo que se quiera, con el valor de posición medido
    Serial.print("X: ");
    Serial.print(Xposition);
    changes = true;
  }
  XprevPosition = Xposition;


  if (Yposition != YprevPosition) {
    //...hacer lo que se quiera, con el valor de posición medido
    Serial.print("Y: ");
    Serial.print(Yposition);
    changes = true;
  }
  YprevPosition = Yposition;
  if (changes) { Serial.println(); }
  delay(10);
}

