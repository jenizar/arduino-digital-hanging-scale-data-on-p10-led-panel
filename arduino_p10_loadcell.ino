#include "HX711.h"
#include "SPI.h"      
#include "DMD.h" 
#include "TimerOne.h"
#include "Arial_black_16.h"
#include "ArialBlack14.h"

// you can remove the fonts if unused
#include "SystemFont5x7.h"
#define DISPLAYS_ACROSS 2   
#define DISPLAYS_DOWN 1       
/* change these values if you have more than one DMD connected */
DMD dmd(DISPLAYS_ACROSS,DISPLAYS_DOWN);

char arrText[5];

void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = A1;
const int LOADCELL_SCK_PIN = A0;  

HX711 scale;

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Pastikan Tidak Ada Beban");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(64);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
  Serial.println("Silahkan Untuk Menimbang");  
   Timer1.initialize( 5000 );           
/*period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.*/

   Timer1.attachInterrupt( ScanDMD );  
/*attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()*/

   dmd.clearScreen( true );            
/* true is normal (all pixels off), false is negative (all pixels on) */
}

void loop(void)
{
  Serial.print("Berat");
  float berat = scale.get_units(25);
  String berat2 = String (berat, 1);
  berat2.toCharArray(arrText, 5);
  if(berat<=0.1)
  {
    berat=0.0;
    String berat2 = String (berat, 1);
    berat2.toCharArray(arrText, 5);    
    berat2.toCharArray(arrText, 5);
  }
  Serial.println(berat,1);
  Serial.println(arrText);
  if(berat<1000)
  {  
   dmd.selectFont(ArialBlack14);
   dmd.drawString( 3,2, arrText, 5, GRAPHICS_NORMAL );
   dmd.drawString( 43,2, "Gr", 2, GRAPHICS_NORMAL );
  }
  if(berat>=1000)
  {
    float hasil=berat/1000;
    String hasil2 = String (hasil, 1);
    hasil2.toCharArray(arrText, 5);
   dmd.selectFont(ArialBlack14);
   dmd.drawString( 3,2, arrText, 5, GRAPHICS_NORMAL );
   dmd.drawString( 43,2, "Kg", 2, GRAPHICS_NORMAL );   
  }
  scale.power_down();
  delay(2000);
  scale.power_up();   
}
