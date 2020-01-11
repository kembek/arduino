int leftSpeedPin = 6;
int leftBackPin = 15; 
int leftForwardPin = 14;

int rightSpeedPin = 5;
int rightBackPin = 16;
int rightForwardPin = 17;
char STOP = 'S';
char GO = 'G';

int _speed = 100;

int trigPin = 3;
int echoPin = 2;
int LED_INPUT = 13;
float duration, distance;
char OFF = 'F';
char ON = 'O';
char BLINKING = 'B';

void ledShow(char state = 'B' ,int second = 1000) {

  if(state == OFF) return;

  if(state == ON) return digitalWrite (LED_INPUT, HIGH);  
  
  digitalWrite (LED_INPUT, HIGH);
  delay(second);
  digitalWrite (LED_INPUT, LOW);
  delay(second);
}

void showDistance(int distance) {
  Serial.println(" ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println(" ");
}

int calcDistance(int duration) {
  Serial.print("duration");
  Serial.println(duration);
  return (duration) / 100;
}

//#define PWMA 6;
//#define AIN1 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_INPUT, OUTPUT);
}

void leftRun(char state, int __speed = 100) {
  if(state==STOP) {
      digitalWrite(leftBackPin, LOW);
    digitalWrite(leftForwardPin, LOW); 
    return;}

 
    analogWrite(leftSpeedPin, __speed);
    digitalWrite(leftBackPin, LOW);
    digitalWrite(leftForwardPin, HIGH);  
}

void rightRun(char state, int __speed=100) {
  if(state==STOP) {
    digitalWrite(rightBackPin, LOW);
    digitalWrite(rightForwardPin, LOW); 
    return;}
    
  analogWrite(rightSpeedPin, __speed);
  digitalWrite(rightBackPin, LOW);
  digitalWrite(rightForwardPin, HIGH);
}

int inputUser() {
  if(Serial.available() > 0) {
    int data = Serial.parseInt();
    
    Serial.println(data);

    return data;
  }

  
}

void loop() {
  // put your main code here, to run repeatedly:
  int userInput = inputUser();
Serial.println(data);
  if(userInput) {
    digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = calcDistance(duration);
  
  showDistance(distance);
  
  if(distance <= 5) {
    Serial.println("Stop");
    ledShow(OFF);
    leftRun(STOP);
    rightRun(STOP);
  }

  

  if(5 < distance && distance <= 20) {
    Serial.println("ON");    
    ledShow(ON);
    leftRun(GO, 255);
//    rightRun(GO, 100);
  }

  if(distance > 20) {
     Serial.println("blinking"); 
     ledShow(BLINKING, 1000);  
     leftRun(GO, 255);
     rightRun(GO, 255);
  }

  Serial.println("Go");
    }
  
  

}
