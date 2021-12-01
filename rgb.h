byte BLUE = D0;
byte GREEN = D1;
byte RED = D2;

const byte HSVlights[61] = 
{0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255};

void setRGB(int r, int g, int b){
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void HSV(int angle){
  byte red, green, blue;

  if (angle<60) {
      red = 255; green = HSVlights[angle]; blue = 0;
  } else if (angle<120) {
      red = HSVlights[120-angle]; green = 255; blue = 0;
  } else if (angle<180) {
      red = 0, green = 255; blue = HSVlights[angle-120];
  } else if (angle<240) {
      red = 0, green = HSVlights[240-angle]; blue = 255;
  } else if (angle<300) {
      red = HSVlights[angle-240], green = 0; blue = 255;
  } else {
      red = 255, green = 0; blue = HSVlights[360-angle];
  } 

  setRGB(red, green, blue);
}
