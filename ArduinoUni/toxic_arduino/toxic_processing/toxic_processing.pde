import processing.serial.*;
Serial myPort;

float xPos = 0; 
float yPos = 0; 
int  inByte =0;
void setup() {
  size(800, 260);
  background(#081640);
  println("Available serial ports:");
  myPort = new Serial(this, "COM4", 9600);
     background(#000000);
}

void serialEvent (Serial myPort) {
  inByte = myPort.read();
  println(inByte);
  yPos = height - inByte;

}

void draw() {
  stroke(#A8D9A7);
  line(xPos, height, xPos, yPos);
  fill(244,118,102); // 색 채우기
  if (xPos >= width) {
    xPos = 0;
    background(#f5f584);
  } 
  else {
    xPos++;
  }

}
