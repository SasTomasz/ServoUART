#include <stdio.h>
#include <stdint.h>
#include <Servo.h>


#define SERVO 9 // signal for servomechanism

Servo servo;
uint8_t isFirstSentenceShowed = false;
long position = 0;

void setup() {
Serial.begin(9600);
servo.attach(SERVO);
}

void loop() {
 

if(!isFirstSentenceShowed) {
  Serial.println("Please write position number");
  isFirstSentenceShowed = true;
}
  
// Serial.println(position);  

while(Serial.available() > 0  ) { 
  
    position = Serial.parseInt(); 
    Serial.print("position = ");
    Serial.println(position);
  }
  
/*  It's working, now I have to work on read message from serial
 if(position <= 180) {
 servo.write(position);
 delay(1000);  
} else {
   Serial.println("Wrong position number");
   delay(1000);    
   Serial.println("Please chose number from 0 to 180");
   delay(1000);
   Serial.println("Please write position number");
   delay(1000);
}
*/

}
