#include <Servo.h> 
 
Servo myservo;  
 
void setup() 
{ 
  myservo.attach(9); 
  Serial.begin(9600);
  Serial.println("START...");
  
  delay(1000);
} 
 
 
void loop() 
{  
  
  while(Serial.available() > 0 )
  {
    int throttle = Serial.parseInt();
    Serial.read();
    Serial.println(throttle);
    myservo.write(throttle);             
    delay(15); 
  }
} 
