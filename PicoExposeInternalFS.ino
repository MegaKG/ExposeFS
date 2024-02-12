#include "ExposeFS.h"
#include <LittleFS.h>
#include <Adafruit_TinyUSB.h>

void setup() {
 
  //Create some test files
  LittleFS.begin();

  

  File f;
  if (!LittleFS.exists("TEST.TXT")){
    //Serial.println("Making Test.txt");
    f = LittleFS.open("TEST.TXT", "w");
    f.print("Hello World!\n");
    f.close();
    //Serial.println("Make Test.txt");
  }
  if (!LittleFS.exists("TEST2.TXT")){
    //Serial.println("Making Test2.txt");
    f = LittleFS.open("TEST2.TXT", "w");
    f.print("ABC DEF GHI JKL!\n");
    f.close();
    //Serial.println("Make Test2.txt");
  }
  //Serial.println("Make Files");
  //delay(1000);

  //Enable the FS
  initExposedFS();

  //It is vital that serial is initialised AFTER the USB fs, otherwise things break
  Serial.begin(9600);
  while (!Serial){
    ;
  }


  Serial.println("Initialised!");
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
