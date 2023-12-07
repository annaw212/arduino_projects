const int green_LED_pin = 9;
const int red_LED_pin = 10;
const int blue_LED_pin = 11;

const int red_sensor_pin = A0;
const int green_sensor_pin = A1;
const int blue_sensor_pin = A2;

int red_value = 0;
int green_value = 0;
int blue_value = 0;

int red_sensor_value = 0;
int green_sensor_value = 0;
int blue_sensor_value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int pin = 9; pin < 12; pin++) {
    pinMode(pin, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  red_sensor_value = analogRead(red_sensor_pin);
  delay(5);
  green_sensor_value = analogRead(green_sensor_pin);
  delay(5);
  blue_sensor_value = analogRead(blue_sensor_pin);


  red_value = red_sensor_value / 4;
  green_value = green_sensor_value / 4;
  blue_value = blue_sensor_value / 4;

  Serial.print("Sensor values: red = ");
  Serial.print(red_value);
  Serial.print("\tgreen = ");
  Serial.print(green_value);
  Serial.print("\tblue = ");
  Serial.println(blue_value);


  analogWrite(red_LED_pin, red_value);
  analogWrite(green_LED_pin, green_value);
  analogWrite(blue_LED_pin, blue_value);

}
