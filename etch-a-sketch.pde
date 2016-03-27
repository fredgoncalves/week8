// Etch-a-Sketch

import processing.serial.*;

Serial port;
int oldX = -1;
int oldY = -1;
int x = -1;
int y = -1;
int columnPosition = 0;

void setup() {
  size(512, 512);
  background(255);
  // make a new Serial object using the last entry in the Serial.list() list.
  port = new Serial(this, Serial.list()[Serial.list().length-1], 9600);
  port.bufferUntil('\n');
}

void drawNextLine() {
  if (oldX >= 0 && oldY >= 0 && (x != oldX || y != oldY)) {
    // draw a line from the old x,y coordinates to the new x,y coordinates
    stroke(255, 0, 0);
    line(columnPosition, y, columnPosition, oldY);
    stroke(0, 0, 255);
    line(x, columnPosition, oldX, columnPosition);
    columnPosition++;
  }

  // update the "old" x,y coordinates for the next frame
  oldX = x;
  oldY = y;
    if (columnPosition>height) {
    columnPosition = 0;
  }
}  

void draw() {
  drawNextLine();

}

void mouseClicked() {
  background(255);
}

void serialEvent(Serial p) {
  String s = p.readString();
  int commaPosition = s.indexOf(",");
  if (commaPosition > 0) {
    x = int(s.substring(0, commaPosition)) / 2;
    y = int(s.substring(commaPosition+1, s.length()-2)) / 2;
  }
}
