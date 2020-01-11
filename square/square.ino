int leftSpeedPin = 6;
int leftBackPin = 15; 
int leftForwardPin = 14;

int rightSpeedPin = 5;
int rightBackPin = 16;
int rightForwardPin = 17;

char STOP = 'S';
char GO = 'G';
char BACK = 'B';

String command = "stop";

String LEFT = "left";
String RIGHT = "right";
String BACK_W = "back";
String FORWARD = "forward";

int tempSquare = 0;

// **** UTILS BEGIN ****

void leftRun(char state, int __speed = 50) {
  if(state == STOP) {
    digitalWrite(leftBackPin, LOW);
    digitalWrite(leftForwardPin, LOW); 
    return;
  }

  if(state == BACK) {
     analogWrite(leftSpeedPin, __speed);
     digitalWrite(leftBackPin, LOW);
     digitalWrite(leftForwardPin, HIGH);  
     return;
  }
 
  analogWrite(leftSpeedPin, __speed = 50);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(leftForwardPin, HIGH);  
}

void rightRun(char state, int __speed=50) {
  if(state == STOP) {
    digitalWrite(rightBackPin, LOW);
    digitalWrite(rightForwardPin, LOW); 
    return;
  }

  if(state == BACK) { 
    analogWrite(rightSpeedPin, __speed);
    digitalWrite(rightBackPin, HIGH);
    digitalWrite(rightForwardPin, LOW);
    return;
  }
      
  analogWrite(rightSpeedPin, __speed);
  digitalWrite(rightBackPin, LOW);
  digitalWrite(rightForwardPin, HIGH);
}

void Run() {
  leftRun(GO);
  rightRun(GO);
}

void Stoping() {
  leftRun(STOP);
  rightRun(STOP);
}

void circle() {
  leftRun(GO, 65);
  rightRun(BACK); 
}

void square() {
  
  Run();

  delay(1000);
  
  Stoping();

  delay(500);
 
  
  circle();
  delay(250);
  Stoping(); 
}
// **** UTILS END ****



void setup() {
  Serial.begin(115200);

}

void loop() {

  if(Serial.available() > 0) {
    
  if(tempSquare < 4) {
    square();  
    ++tempSquare;
  } else {
    tempSquare = 0;  
  }
  }



  
//
//  delay(3000);
//
//  circle();
//
//  delay(3000);

//  switch(command) {
//    case LEFT: {
//      
//      return;  
//    }
//    
//  }

  
}
