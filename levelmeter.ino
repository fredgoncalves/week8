// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int pinLed2 = 10;
const int pinLed3 = 11;
const int pinLed4 = 6;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(analogOutPin, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 500, 800, 0, 255);
  // change the analog out value:
  if (outputValue > 50) {
    digitalWrite(analogOutPin, HIGH);
  } else {
    digitalWrite(analogOutPin, LOW);
  }

  if (outputValue > 100) {
    digitalWrite(pinLed2, HIGH);
  } else {
    digitalWrite(pinLed2, LOW);
  }

  if (outputValue > 150) {
    digitalWrite(pinLed3, HIGH);
  } else {
    digitalWrite(pinLed3, LOW);
  }

  if (outputValue > 200) {
    digitalWrite(pinLed4, HIGH);
  } else {
    digitalWrite(pinLed4, LOW);
  }

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
