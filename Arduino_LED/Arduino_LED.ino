#include <Adafruit_NeoPixel.h>
//download Adafruit_Neopixel library to make it work

//works somewhat like c


#define PIN 11 //LED output pin
#define BLINK 4 //number of times to blink
#define PIXN 75 //pixel numer
#define IN 4 //input from robo rio
#define U 200 //200 ms per unit length of dot










#define MODE 1 //0 for morse code, 1 for color stuff 2 for red 3 for blue, 4 for orange, 5 for preprogrammed morse code.
#define MESSAGE "team pronto 3070   this robot is sponserd by  boeing  microsoft  mr proudlove   satrt of message from programmer  contact programmer to put your mesage here  end of message  programmed by corwin hansen"//message for mode 5









unsigned char index;
int volt;
int incomingByte;   // for incoming serial data
int i; //counter

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXN, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {//start stuff here
  strip.begin();//start strip
  strip.show(); // Initialize all pixels to 'off'
  index = 0;//reset index
  incomingByte = 0;//reset byte
  i = 0;//reset message pointer
   Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {//works like a endless main function



  
  if (MODE == 0 || MODE == 5){//for both morse code modes
  //USB Morse code
          if (Serial.available() > 0 || MODE == 5) {
                // read the incoming byte:
                incomingByte = Serial.read();//morse code U par unit
                 if (MODE == 5){//use code for input
                   char message[] = MESSAGE;//set array to MESSAGE macro
                   incomingByte = message[i%sizeof(message)];//Get character
                   i++;
                 }
                 
                 //if else ladder for each signal that can be sant through USB
                if((char)incomingByte == 'R'){//red
                   set(strip.Color(100, 0, 0), 0);
                }
                else if((char)incomingByte == 'B'){//blue
                  set(strip.Color(0, 0, 100), 0);
                }
                else if((char)incomingByte == ' '){//black, " "
                  set(strip.Color(0, 0, 0), 0);
                  delay(5*U);
                }
                 else if((char)incomingByte == 'G'){//green
                  set(strip.Color(0, 100, 0), 0);
                }
                 else if((char)incomingByte == 'W'){//wite
                  set(strip.Color(100, 100, 100), 0);
                }
                else if((char)incomingByte == 'O'){//orange
                  set(strip.Color(100, 30, 0), 0);
                }
                else if((char)incomingByte == 'a'){//a
                  dot();//dot in morse code
                  dash();//dash in morse code
                }
                else if((char)incomingByte == 'b'){//b
                  dash();
                  dot();
                  dot();
                  dot();
                }
                else if((char)incomingByte == 'c'){//c
                  dash();
                  dot();
                  dash();
                  dot();
                }
                else if((char)incomingByte == 'd'){//d
                  dash();
                  dot();
                  dot();
                }
                else if((char)incomingByte == 'e'){//e
                  dot();
                }
                else if((char)incomingByte == 'f'){//f
                  dot();
                  dot();
                  dash();
                  dot();
                }
                else if((char)incomingByte == 'g'){//g
                  dash();
                  dash();
                  dot();
                }
                else if((char)incomingByte == 'h'){//h
                  dot();
                  dot();
                  dot();
                  dot();
                }
                else if((char)incomingByte == 'i'){//i
                  dot();
                  dot();
                }
                else if((char)incomingByte == 'j'){//j
                  dot();
                  dash();
                  dash();
                  dash();
                }
                else if((char)incomingByte == 'k'){//k
                  dash();
                  dot();
                  dash();
                }
                else if((char)incomingByte == 'l'){//l
                  dot();
                  dash();
                  dot();
                  dot();
                }
                else if((char)incomingByte == 'm'){//m
                  dash();
                  dash();
                }
                else if((char)incomingByte == 'n'){//n
                  dash();
                  dot();
                }
                else if((char)incomingByte == 'o'){//o
                  dash();
                  dash();
                  dash();
                }
                else if((char)incomingByte == 'p'){//p
                  dot();
                  dash();
                  dash();
                  dot();
                }
                else if((char)incomingByte == 'q'){//q
                  dash();
                  dash();
                  dot();
                  dash();
                }
                else if((char)incomingByte == 'r'){//r
                  dot();
                  dash();
                  dot();
                }
                else if((char)incomingByte == 's'){//s
                  dot();
                  dot();
                  dot();
                }
                else if((char)incomingByte == 't'){//t
                  dash();
                }
                else if((char)incomingByte == 'u'){//u
                  dot();
                  dot();
                  dash();
                  dash();
                }
                else if((char)incomingByte == 'v'){//v
                  dot();
                  dot();
                  dot();
                  dash();
                }
                else if((char)incomingByte == 'w'){//w
                  dot();
                  dash();
                  dash();
                }
                else if((char)incomingByte == 'x'){//x
                  dash();
                  dot();
                  dot();
                  dash();
                }
                else if((char)incomingByte == 'y'){//y
                  dash();
                  dot();
                  dash();
                  dash();
                }
                else if((char)incomingByte == 'z'){//z
                  dash();
                  dash();
                  dot();
                  dot();
                }
                else if((char)incomingByte == '0'){//0
                  dash();
                  dash();
                  dash();
                  dash();
                  dash();
                }
                else if((char)incomingByte == '1'){//1
                  dot();
                  dash();
                  dash();
                  dash();
                  dash();
                }
                else if((char)incomingByte == '2'){//2
                   dot();
                  dot();
                  dash();
                  dash();
                  dash();
                }
                else if((char)incomingByte == '3'){//3
                  dot();
                  dot();
                  dot();
                  dash();
                  dash();
                }
                else if((char)incomingByte == '4'){//4
                  dot();
                  dot();
                  dot();
                  dot();
                  dash();
                }
                else if((char)incomingByte == '5'){//5
                  dot();
                  dot();
                  dot();
                  dot();
                  dot();
                }
                else if((char)incomingByte == '6'){//6
                  dash();
                  dot();
                  dot();
                  dot();
                  dot();
                }
                else if((char)incomingByte == '7'){//7
                  dash();
                  dash();
                  dot();
                  dot();
                  dot();
                }
                else if((char)incomingByte == '8'){//8
                  dash();
                  dash();
                  dash();
                  dot();
                  dot();
                }
                else if((char)incomingByte == '9'){//9
                  dash();
                  dash();
                  dash();
                  dash();
                  dot();
                }
          }
   //End Morse Code
  
  }
  
  if(MODE == 1){//if in Mode 1
  
  //do color wipe with 4 colors
    for(uint8_t i = 0; i < BLINK; i++){//ColorWipe BLINK times
      colorWipe(strip.Color(100, 30, 0), 50); // Orange
      colorWipe(strip.Color(100, 100, 100), 50); // White
      colorWipe(strip.Color(100, 0, 0), 50); // Red
      colorWipe(strip.Color(0, 0, 100), 50); // Blue
  }
   //blink with 4 colors
  for(uint8_t i = 0; i < BLINK; i++){//blink BLINK times
      set(strip.Color(0, 0, 0), 50); // Black
      set(strip.Color(100, 30, 0), 500); // Orange
      set(strip.Color(0, 0, 0), 50); // Black
      set(strip.Color(100, 100, 100), 500); // White
      set(strip.Color(0, 0, 0), 50); // Black
      set(strip.Color(100, 0, 0), 500); // Red
      set(strip.Color(0, 0, 0), 50); // Black
      set(strip.Color(0, 0, 100), 500); // Blue
  }
  }
  
  
  if (MODE == 2){//just red
    set(strip.Color(100, 0, 0), 0); // Red
  }
  
  if (MODE == 3){//just blue
    colorWipe(strip.Color(0, 0, 100), 0); // Blue
  }
  
  if (MODE == 4){//just orange
    set(strip.Color(100, 30, 0), 0);//orange
  }
  
  
  
  delay(U*2);//delay some time
}



void set(uint32_t color, uint8_t wait) {//set the whole strip on that color
    for(uint16_t i=0; i<strip.numPixels(); i++) {//loop for each pixel
    strip.setPixelColor(i, color);//set color for that pixel
  }
  strip.show();//show that strip
  delay(wait);//wait for some time
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {//for each pixel
      strip.setPixelColor(i, c);//set color for that bit
      strip.show();//show for each loop
      delay(wait);//wait some time
  }
}

void dot(void){//dot in morse code
    set(strip.Color(100, 100, 100), 0);//white
    delay(1*U);//1 space wait
    set(strip.Color(0, 0, 0), 0);//black
    delay(1*U);//1 space wait
}

void dash(void){//dash in morse code
    set(strip.Color(100, 100, 100), 0);//white
    delay(3*U);//3 space wait
    set(strip.Color(0, 0, 0), 0);//black
    delay(1*U);//3 space wait
}
