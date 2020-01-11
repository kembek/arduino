#include <Adafruit_NeoPixel.h>

/* Константы пиннов для управления  */
/** Левым мотором */
int leftSpeedPin = 6; /* для установки скорости в диапазоне от 0 до 255 */
int leftBackPin = 15; // для выхода
int leftForwardPin = 14; // для входа

/** Правым мотором */
int rightSpeedPin = 5; /* для установки скорости в диапазоне от 0 до 255 */
int rightBackPin = 16; // для выхода
int rightForwardPin = 17; // для входа

/** Датчиком */
int trigPin = 3; // для посылания ультра звука (output)
int echoPin = 2; // для получения обратно ультра звука (input)


float duration, distance;

/* Константы для управления (команды) */
char command = 'S'; // первоначальная комманда
char STOP = 'S'; // стоп
char GO = 'G'; // вперед
char LEFT = 'L'; // налево
char RIGHT = 'R'; // направо
char BACK = 'B'; // назад
int SPEED = 25;

Adafruit_NeoPixel RGB = Adafruit_NeoPixel(4, 7, NEO_RGB + NEO_KHZ800);

void leftRun(char state, int __speed = 50) {
  if(state == STOP) {
    digitalWrite(leftBackPin, LOW); // 
    digitalWrite(leftForwardPin, LOW); // 
    return;
  }

  if(state == BACK) {
     analogWrite(leftSpeedPin, __speed);
     digitalWrite(leftBackPin, HIGH);
     digitalWrite(leftForwardPin, LOW);  
     return;
  }
 
  analogWrite(leftSpeedPin, __speed);
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

void _run(int _speed = 100) {
  leftRun(GO, _speed);
  rightRun(GO, _speed);
}

void stoping() {
  leftRun(STOP);
  rightRun(STOP);
}

void back(int _speed = 100) {
  leftRun(BACK, _speed);
  rightRun(BACK, _speed);
  
}

void left() {
  leftRun(GO, 80);
  rightRun(BACK);
  delay(250);
  stoping();
}

void right() {
  leftRun(BACK);
  rightRun(GO, 80);
  delay(250);
  stoping();
}


void showDistance(int distance) {
  Serial.println(" ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println(" ");
}

int calcDistance(int duration) {
  return (duration) / 100;
}

void setColor() {

  for(int i = 0; i < 4; ++i) {
    RGB.setPixelColor(i, 0x00FF00);
  }
  RGB.show();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = calcDistance(duration);
  
//  showDistance(distance);
  RGB.setPixelColor(0, 0x00FF00);
  RGB.show();
  
  if(Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);    
  }

  switch(command) {
    case 'G': {
      if (distance < 5) {
        stoping();
        break;
      }
      setColor();
      _run(SPEED);
      
      break; }
    case 'S': { stoping(); break; }
    case 'B': { back(SPEED); break; }
    case 'L': { left(); break; }
    case 'R': { right(); break; }
    case '+': { 
      Serial.println(SPEED);
      
      if(SPEED >= 100) break; 
      SPEED += 50;
      command = 'S';
      Serial.println(SPEED);
    }
    case '-': {
      
      Serial.println(SPEED);
      if(SPEED <= 0) break;
      SPEED -= 25;
      command = 'S';
      break;
    }

    default: {
      stoping();
    }
  }
  
}

