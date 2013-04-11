import processing.serial.*;
Serial myPort;
float value;

void setup() {
  // Declare Canvas
  size(800, 600);
  smooth();  
  myPort = new Serial(this, Serial.list()[0], 9600);
}


void printTemperature(float value) {
  textSize(250);
  text(value, 1, 400); 
}

void serialEvent(Serial p) {
  // get message till line break (ASCII > 13)
  String message = myPort.readStringUntil(13);
  if (message != null) {
    value = float(message);
    printTemperature(value);
  }
}

void draw() {
  //ellipse(mouseX, mouseY, 80, 80 );
  
}
