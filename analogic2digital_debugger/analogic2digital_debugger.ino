/*
 * 
 * Roberto Salgado <drober@gmail.com>
 * 
 * 
 * Based on basic arduino examples
 * Reads a digital input on pins 8, 7, 6 and 5, prints the result to the serial monitor
 * 
 * This is intended to be used to read data from an analogic joystick connected with 4 15K resistors making it digital
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 8;
int pushButton2 = 7;
int pushButton3 = 6;
int pushButton4 = 5;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
  pinMode(pushButton4, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  int buttonState2 = digitalRead(pushButton2);
  int buttonState3 = digitalRead(pushButton3);
  int buttonState4 = digitalRead(pushButton4);
  // print out the state of the button:
  Serial.print(buttonState);
  Serial.print(buttonState2);
  Serial.print(buttonState3);
  Serial.println(buttonState4);
  delay(1);        // delay in between reads for stability
}



