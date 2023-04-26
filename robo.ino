#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


int i1 = 8;
//int i2 = 9;
int i3 = 9;
//int i4 = 11;
const int trigPin = 10;
const int echoPin = 11;
int irsensor1 = 6; // Right one
int irsensor2 = 7;// Left one
long duration;
int distance;
int state=0;
void setup() {
  // put your setup code here, to run once:
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(irsensor1, INPUT); 
  pinMode(irsensor2, INPUT); 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(i1,OUTPUT);
//  pinMode(i2,OUTPUT);
  pinMode(i3,OUTPUT);
//  pinMode(i4,OUTPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("State: ");
  //Serial.println(state);
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);
  if(digitalRead(irsensor1) == 1){
    state=1;
  }
  if(digitalRead(irsensor2) == 1){
    state=2;
  }
  if(Serial.available()>0){    
      char input = Serial.read();
      Serial.println(input);
      if(input=='0'){state=0;
      }
      if(input=='1'){state=4;}
      if(input=='2'){state=4;
      }
    }
  if((distance<14 && distance!=0)){
    Stop();
    myDisplay("Stop");
  }
  else{
    if(state==0){
      forward();
      myDisplay("Moving Forward");
    }
    if(state==2){
      turnLeft();
      myDisplay("Turning Right");
    }
    if(state==1){
      turnRight();
      myDisplay("Turning Left");
    }
    if(state==4){
      Stop();
      myDisplay("Red Light/Stop Sign");
    }
    
    
  }

}

void forward(){
  //Serial.println("Forward");
 
              digitalWrite(i1,HIGH);
 //             digitalWrite(i2,LOW);
            digitalWrite(i3,HIGH);
 //           digitalWrite(i4,LOW);
}


void turnRight(){
    //Serial.println("Turn Right");
  
              digitalWrite(i1,LOW);
   //           digitalWrite(i2,LOW);
            digitalWrite(i3,HIGH);
   //         digitalWrite(i4,LOW);
}


void turnLeft(){
    //Serial.println("Turn Left");
    
              digitalWrite(i1,HIGH);
     //         digitalWrite(i2,LOW);
            digitalWrite(i3,LOW);
     //       digitalWrite(i4,LOW);
}
void Stop(){
    //Serial.println("Stop");
    
              digitalWrite(i1,LOW);
       //       digitalWrite(i2,LOW);
            digitalWrite(i3,LOW);
       //     digitalWrite(i4,LOW);
}

void myDisplay(char mystring[]){
display.clearDisplay();
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(mystring);
  display.display();
}
int calculateDistance(){ 
  
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
