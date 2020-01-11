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

int tempSquare = 0;

Adafruit_NeoPixel RGB = Adafruit_NeoPixel(4, 7, NEO_RGB + NEO_KHZ800);


// **** UTILS BEGIN ****

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

/* функция для управления левым мотором */
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

void logger(String state) {
  Serial.println("*** - ***");  
  Serial.println(state);  
  Serial.println("*** - ***");  
}

void _run() {
  leftRun(GO);
  rightRun(GO);
}

void stoping() {
  leftRun(STOP);
  rightRun(STOP);
}

void back() {
  leftRun(BACK);
  rightRun(BACK);
  
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


void circle() {
  leftRun(GO, 65);
  rightRun(BACK); 
}

void square() {
  
  _run();

  delay(1000);
  
  stoping();

  delay(500);
 
  
  circle();
  delay(250);
  stoping(); 
}

void setColor(byte color = 0x00FF00) {
  Serial.println(color);
  for(int i = 0; i < 4; ++i) {
    RGB.setPixelColor(i, 0x00FF00);
  }
//  RGB.show();
}
// **** UTILS END ****



void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//
//  duration = pulseIn(echoPin, HIGH);
//  distance = calcDistance(duration);
//  
//  showDistance(distance);

  if(Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    
  }
//  ++distance;
//  delay(500);
//  if(distance <= 5) {
//    stoping();
//    return;    
//  }

//  if(command == 'G' || com/
//
  switch(command) {
    case 'G': {
        _run();
        break;
    }

    case 'B': {
        back();
        break;
    }

    case 'S': {
        stoping();
        break;
    }

    case 'L': {
        left();
        command = STOP;
        break;
    }

    case 'R': {
        right();
        command = STOP;
        break;
    }

    case 'r': {
      Serial.println("Switch working");
      Serial.println(command); 

      setColor();
      break;
      }

    default: {
      Serial.println("com ");
      Serial.println(command);
      break;
    }
  }
//      
 



  
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
