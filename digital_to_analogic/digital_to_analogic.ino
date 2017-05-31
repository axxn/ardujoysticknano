
bool debug = false;

const int XPin = A0;
const int YPin = A1;

int buttonUP = LOW;
int buttonDOWN = LOW;
int buttonLEFT = LOW;
int buttonRIGHT = LOW;

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
    if (debug) {
      Serial.print("X: ");
      Serial.print(Xposition);
    }
    changes = true;
  }
  XprevPosition = Xposition;


  if (Yposition != YprevPosition) {
    //...hacer lo que se quiera, con el valor de posición medido
    if (debug) {
      Serial.print("Y: ");
      Serial.print(Yposition);
    }
    changes = true;
  }
  YprevPosition = Yposition;
  if (changes) {
    if (debug) { Serial.println(); }

    if ((Xposition >= 70) && (XprevPosition <= 70)) {
      buttonRIGHT = HIGH;
      Serial.println("RIGHT");
    } else if ((Xposition <= 30) && (XprevPosition >= 30)) {
      buttonLEFT = HIGH;
      Serial.println("LEFT");
    } else if ((Xposition > 30) && (Xposition < 70)) {
      if ((buttonLEFT) || (buttonRIGHT)) {
        buttonLEFT = LOW;
        buttonRIGHT = LOW;
        Serial.println("-");
      }
    }

    if ((Yposition >= 70) && (YprevPosition <= 70)) {
      buttonUP = HIGH;
      Serial.println("UP");
    } else if ((Yposition <= 30) && (YprevPosition >= 30)) {
      buttonDOWN = HIGH;
      Serial.println("DOWN");
    } else if ((Yposition > 30) && (Yposition < 70)) {
      if ((buttonUP) || (buttonDOWN)) {
        buttonUP = LOW;
        buttonDOWN = LOW;
        Serial.println("|");
      }
    }


  }
  delay(10);
}

