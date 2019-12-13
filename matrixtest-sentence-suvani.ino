// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
//#include <Fonts/FreeMono9pt7b.h>

#define PIN 3
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(144, 8, PIN,    // declare size here
                            NEO_MATRIX_TOP     + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.


const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 0, 0), matrix.Color(0, 0, 255)
};

void setup() {
  matrix.begin();
  matrix.setTextWrap(true);
  matrix.setBrightness(30);
  matrix.setTextColor(colors[0]);
 
}

int x    = matrix.width();
int pass = 0;
char message[27] = "abcdefghijklmnopqrstuvwxyz";
char c;

void loop()
{
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);

  //matrix.print(F("Pack my box with five dozen liquor jugs")); //234
 // matrix.print(F("I got a call from -ool-. It had me at hello. A sinister Californian number flashes at me with the promise to connect me to art (?). ok? sure, let’s connect? Connect. Connected. Connecting…Connected homes. Connected TV. Connected toaster. Connections all the way. Dial-up and wired. Wireless and floating. On cloud 404. Connected is how advertising should be, make way for Adobe Advertising cloud. To connect with customers, connect your strategy. Connect the dots. The way we once did. Connectedness. +1 415 980 2019 —— The digits lie at the edge of time. Producing, regenerating, calling, capitalizing. Streams of data that fall off the edges of the cliff of real time, only to surface again. Continually. Forever. On Repeat. Pick the call to meet at a fluid junction. An Alephian moment. A point in time that contains all other points. In this pool of addresses of hosts and guests, machines and servers laid out on the grid of common addresses, where are we located? Fragments of the map, here and now. The global electronic map bears uncanny resemblances to the exactitude of Borges’ map. A map on the same scale as the empire itself. The tattered ruins of the map are connected yet again, real time. For REAL this time.")); 
 matrix.print(F("Connect"));
 matrix.print(F("Pack"));
 
  if (--x < -100)
  {
    x = matrix.width(); 

    
  }

/*
for(int i=0;i<432;i++)
  {c = message[random(0,27)];
  matrix.drawChar(x+i*6,0,c, colors[0], colors[1], 1);
  }

*/

  matrix.show();
  //delay(100);
}
