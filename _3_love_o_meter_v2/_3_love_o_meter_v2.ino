const int sensorPin = A0;
const float baselineTemp = 23.0;

void setup() {
  Serial.begin(9600);
  
  for (int pinNumber = 3; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

int writeToLeds(int valueLed1, int valueLed2, int valueLed3) {
    digitalWrite(3, valueLed1);
    digitalWrite(4, valueLed2);
    digitalWrite(5, valueLed3);  
}

int calculateTemperature() {
  int sensorValue = analogRead(sensorPin);
  //Serial.print(" Value Sensor: ");
  //Serial.print(sensorValue);
  
  float voltage = ( sensorValue / 1024.0 ) * 5.0;
  //Serial.print(" Volts, ");
  //Serial.print(voltage);
  
  float temperature = ( voltage - .5 ) * 100;
  //Serial.print(" degrees C, ");
  
  Serial.println(temperature);
  
  return temperature;
} 

void loop() {
  int sensorValue = analogRead(sensorPin);
  float temperature = calculateTemperature();
    
  if (temperature < baselineTemp) {
    writeToLeds(LOW,LOW,LOW);
    Serial.print(".");
  } 
  
  if ( temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    writeToLeds(HIGH,LOW,LOW);
    Serial.print("_");
  } 
  
  if ( temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    writeToLeds(HIGH,HIGH,LOW);
    Serial.print("-");  
  } 
  
  if ( temperature >= baselineTemp+6) {
    writeToLeds(HIGH,HIGH,HIGH);
    Serial.print("*");  
  }
  
  delay(2000);
}
