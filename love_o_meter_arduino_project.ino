const int analog_input = A0;
const float baseline_temp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // opens a serial port
  for (int pin_number = 2; pin_number < 5; pin_number++) {
    pinMode(pin_number, OUTPUT);
    digitalWrite(pin_number, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_val = analogRead(analog_input);
  Serial.print("Sensor value: ");
  Serial.print(sensor_val);
  float voltage_val = sensor_val / 1024.0 * 5.0;
  Serial.print(" Voltage value: ");
  Serial.print(voltage_val);
  // every 10mV of change from the sensor is equivalent to 1 degree C change
  float temperature = (voltage_val - 0.5) * 100;
  Serial.println(temperature);
  if (temperature < baseline_temp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baseline_temp + 2 && temperature < baseline_temp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= (baseline_temp+4) && temperature < (baseline_temp + 6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baseline_temp + 6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
