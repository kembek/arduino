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

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_INPUT, OUTPUT);
}

void loop() {    
  
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = calcDistance(duration);
  
  showDistance(distance);
  
  if(distance <= 5) {
    Serial.println("OFF");
    ledShow(OFF);
  }

  if(2 < distance && distance <= 10) {
    Serial.println("ON");    
    ledShow(ON);
  }

  if(10 < distance && distance < 200) {
     Serial.println("blinking"); 
     ledShow(BLINKING, 1000);  
  }

  if(distance > 200) {
    Serial.println("OFF"); 
    ledShow(OFF);
  }

  delay(500);
  
}
