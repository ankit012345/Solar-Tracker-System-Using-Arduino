#include <Servo.h> 

Servo myservo;

#define ldr1 A0
#define ldr2 A1

int pos = 90; 
int tolerance = 30; 
   
void setup(){
myservo.attach(2);  
pinMode(ldr1, INPUT); 
pinMode(ldr2, INPUT);
myservo.write(pos);  
Serial.begin(9600);
    
delay(1000); 
}

void loop(){      
int val1 = analogRead(ldr1);
delay(10); 
int val2 = analogRead(ldr2); 
      
if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {

}
else {
if(val1 > val2)  
{
pos = pos+1; 
Serial.println(val1);
Serial.println(val2);
}
if(val1 < val2) 
{
pos = pos-1; 
Serial.println(val1);
Serial.println(val2);
 }
}
     
if(pos > 180) {pos = 180;}
if(pos < 0) {pos = 0;} 
myservo.write(pos); 
delay(50);

}