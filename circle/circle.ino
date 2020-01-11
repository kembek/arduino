int leftSpeedPin = 6;
int leftBackPin = 15; 
int leftForwardPin = 14;

int rightSpeedPin = 5;
int rightBackPin = 16;
int rightForwardPin = 17;

char STOP = 'S';
char GO = 'G';
char BACK = 'B';

//string command = "stop";

String LEFT = "left";
String RIGHT = "right";
String BACK_W = "back";
String FORWARD = "forward";

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
  leftRun(GO, 80);
  rightRun(BACK); 
}

void square() {
  
  Run();

  delay(1000);
  
  Stoping();

  delay(1000);
 
  
  circle();
  delay(1000);
  Stoping(); 
}
// **** UTILS END ****



void setup() {
  Serial.begin(9600);

}

void loop() {

  if(Serial.available() > 0) {
    
  }

  circle();

//  switch(command) {
//    case LEFT: {
//      
//      return;  
//    }
//    
//  }

  
}
