const int sensorPin = A0;
const float baselineTemp = 23.0;

void setup() {
  Serial.begin(9600);
  
  for (int pinNumber = 3; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

int threeLeds(int a, int b, int c) {
    digitalWrite(3, a);
    digitalWrite(4, b);
    digitalWrite(5, c);  
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print(" Value Sensor: ");
  Serial.print(sensorValue);
  
  float voltage = ( sensorValue / 1024.0 ) * 5.0;
  Serial.print(" Volts, ");
  Serial.print(voltage);
  
  float temperature = ( voltage - .5 ) * 100;
  Serial.print(" degrees C, ");
  Serial.print(temperature);

  if (temperature < baselineTemp) {
    threeLeds(LOW,LOW,LOW);
  } 
  
  if ( temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    threeLeds(HIGH,LOW,LOW);
  } 
  
  if ( temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    threeLeds(HIGH,HIGH,LOW);
  } 
  
  if ( temperature >= baselineTemp+6) {
    threeLeds(HIGH,HIGH,HIGH);
  }
  
  delay(1);
}
