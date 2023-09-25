#include<Servo.h>

#define outputA 6

#define outputB 7

Servo servo1;

int counter = 0; 

int aState;

int aLastState; 

void setup() { 

pinMode (outputA,INPUT);

pinMode (outputB,INPUT);
    
    servo1.attach(9);
    
    

Serial.begin (9600);

// Reads the initial state of the outputA

aLastState = digitalRead(outputA); 

} 

void loop() { 

aState = digitalRead(outputA); // Reads the "current" state of the outputA

// If the previous and the current state of the outputA are different, that means a Pulse has occured

if (aState != aLastState){ 

// If the outputB state is different to the outputA state, that means the encoder is rotating clockwise

if (digitalRead(outputB) != aState) { 

counter ++;

} else {

counter --;

}

Serial.print("Position: ");

Serial.println(counter);
        servo1.write(counter); 

} 

aLastState = aState; // Updates the previous state of the outputA with the current state

}

