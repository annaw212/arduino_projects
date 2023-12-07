int sensorValue;  // holds the incoming value from the transistor
int sensorHigh = 0;
int sensorLow = 1023;

const int ledPin = 13;  // on board LED pin 13

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  // map pitch value to sensorValue with values 50 - 4000, 3950 values for whatever the range is
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.print(sensorValue);

  tone(8, pitch, 20);
  delay(10);
}
