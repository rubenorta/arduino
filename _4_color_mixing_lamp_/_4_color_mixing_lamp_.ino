const int greenL = 9;
const int redL = 11;
const int blueL = 10;

const int redS = A0;
const int greenS = A1;
const int blueS = A2;


int greenLV = 0;
int redLV = 0;
int blueLV = 0;

int redSV = 0;
int greenSV = 0;
int blueSV = 0;

void setup() {

  Serial.begin(9600);
  pinMode(greenL, OUTPUT);
  pinMode(redL, OUTPUT);
  pinMode(blueL, OUTPUT);
  
}

void loop() {
  int redSV = analogRead(redS);
  delay(5);
  int greenSV = analogRead(greenS);
  delay(5);
  int blueSV = analogRead(blueS);
  
  Serial.print("R: ");
  Serial.print(redSV);
  Serial.print(" G: ");
  Serial.print(greenSV);
  Serial.print(" B: ");
  Serial.println(blueSV);
  
  greenLV = greenSV / 4;
  redLV = redSV / 4;
  blueLV = blueSV / 4;
  
  Serial.print("LedR: ");
  Serial.print(redLV);
  Serial.print(" LedG: ");
  Serial.print(greenLV);
  Serial.print(" LedB: ");
  Serial.println(blueLV);
  
  analogWrite(greenL, greenLV);
  analogWrite(redL, redLV);
  //analogWrite(blueL, blueLV);
   
}
