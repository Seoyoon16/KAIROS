import processing.serial.*;

Serial myPort;
String myString = null;
int angle = 0;
int distance = 0;

void setup() {
size(1200, 700);
background(0);
myPort = new Serial(this, "COM4", 9600);
}

void draw() {
noStroke();
fill(0, 7);
rect(0, 0, width, height);
drawRadar();
drawLine();
drawObject();
}

void serialEvent(Serial p) {
try {
myString = p.readStringUntil('.');
String[] list = split(myString, '\t');
angle = int(list[0]);
//distance = int(list[1]);
} catch (Exception e) {       //예외처리
print(e);
}
}

void drawRadar() {
pushMatrix();
translate(width / 2, height);         //좌표재정의(중앙으로 원점이동)
noFill();                             //면,채우지 않는다
strokeWeight(2);                      //두께
stroke(98, 245, 31);                  //초록색으로 선그리기

// draw the arc lines
arc(0, 0, width, width, 0, 180); //X,Y,호의가로너비,호의높이, 시작각도(180), 끝각도(360)
arc(0, 0, width * 2 / 3, width * 2 / 3, 0, 180);
arc(0, 0, width * 1 / 3, width * 1 / 3, 0, 180);

// draw the angle lines
line(0, 0, width / 2 * cos(radians(30)), -width / 2 * sin(radians(30)));  //시작좌표, 끝좌표
line(0, 0, width / 2 * cos(radians(60)), -width / 2 * sin(radians(60)));
line(0, 0, width / 2 * cos(radians(90)), -width / 2 * sin(radians(90)));
line(0, 0, width / 2 * cos(radians(120)), -width / 2 * sin(radians(120)));
line(0, 0, width / 2 * cos(radians(150)), -width / 2 * sin(radians(150)));

// draw text
textSize(15);
fill(98, 245, 31);
textAlign(RIGHT);
text("10cm", width * 1 / 6, 0);
text("20cm", width * 2 / 6, 0);
text("30cm", width * 3 / 6, 0);

popMatrix();
}

void drawLine() {
pushMatrix();
translate(width/2, height);
strokeWeight(4);
stroke(98, 245, 31);
line(0, 0, width / 2 * cos(radians(angle)), -width / 2 * sin(radians(angle)));
popMatrix();
}

void drawObject() {
pushMatrix();    //현재화면을불러와
translate(width / 2, height);  //원점 변경
strokeWeight(4);
stroke(255, 10, 10); // red color
float d = (width / 2.0 / 30.0) * (float) distance;

if (d < width / 2)
line(d * cos(radians(angle)), -d * sin(radians(angle)), width / 2 * cos(radians(angle)), -width / 2 * sin(radians(angle)));
popMatrix();    //표시하고 추가
}
