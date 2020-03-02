#include <Wire.h> 

#include "rgb_lcd.h"

rgb_lcd lcd;

int colorR = 0;
int colorG = 255;
int colorB = 0;

int num_Measure = 128 ; // Set the number of measurements   
int pinSignal = A0; // pin connected to pin O module sound sensor  
int redLed = 5; 
long Sound_signal;    // Store the value read Sound Sensor   
long sum = 0 ; // Store the total value of n measurements   
long level = 0 ; // Store the average value   
int soundlow = 40;
int soundmedium = 500;

void setup() 
{
  
    pinMode (pinSignal, INPUT); // Set the signal pin as input   
  Serial.begin (9600); 
  lcd.begin(16,2);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    

    delay(10);
}

void loop() 
{
    for ( int i = 0 ; i <num_Measure; i ++)  
  {  
   Sound_signal = analogRead (pinSignal);  
    sum =sum + Sound_signal;  
  }  
 
  level = sum / num_Measure; // Calculate the average value   
  Serial.print("Sound Level: ");
  lcd.print("Sound Level= ");
  Serial.println (level-33);  
  lcd.print(level-33);
  if(level-33<soundlow)
  {
    lcd.setCursor(0,2);
    lcd.print("Intensity= Low");
     digitalWrite(redLed,LOW);
     
  }
  if(level-33>soundlow && level-33<soundmedium)
  {
    lcd.setCursor(0,2);
    lcd.print("Intensity=normal"); 
     digitalWrite(redLed,LOW);
     int colorR = 0;
     int colorG = 255;
    int colorB = 0; 
    lcd.setRGB(colorR, colorG, colorB);
     
  }
  if(level-33>soundmedium)
  {
    lcd.setCursor(0,2);
    lcd.print("Intensity= High");   
    digitalWrite(redLed,HIGH);
    int colorR = 255;
     int colorG = 0;
    int colorB = 0; 
    lcd.setRGB(colorR, colorG, colorB);
  }
  sum = 0 ; // Reset the sum of the measurement values  
  delay(200);
  lcd.clear();
}// set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
//    rgb_lcdsetCursor(0, 1);
    // print the number of seconds since reset:
//    rgb_lcdprint(millis()/1000);

    //delay(100);
//}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
