/*/***************************************************
  Fuzzy Example

  by Tomás de Camino Beck
  www.funcostarica.org

  License:

  This example was created by Tomàs de Camino Beck (tomas@funcostarica.org)
  and is released under an open source MIT license.  See details at:
    http://opensource.org/licenses/MIT

 ****************************************************/

#include <Adafruit_NeoPixel.h>
#include <FuzzyControl.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, 9, NEO_GRB + NEO_KHZ800);



/********************************************************/
fuzzyDomain light;


void setup() {

  Serial.begin(9600);
  pixels.begin();
  pixels.show();

  light.nset = 3;
  light.fset = new fuzzyDef[3];

  //creates a standard domain with nset=3 fuzzy sets
  setDomain(&light, 1023);


  pinMode(A0, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  //calculates all membership degrees of the input
  truthDegree(&light, val);
  //use membership to weight colors
  int red = round(255 * light.fset[0].miu);
  int green = round(255 * light.fset[1].miu);
  int blue = round(255 * light.fset[2].miu);
  //set pixel color
  pixels.setPixelColor(0, pixels.Color(green, red,blue));
  pixels.show(); 

}


