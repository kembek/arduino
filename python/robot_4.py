from nanpy import ArduinoApi, SerialManager
from time import sleep

connection = SerialManager()
a = ArduinoApi(connection = connection)

BUTTON = 2
LED = 13

leftSpeedPin = 6;
leftBackPin = 15; 
leftForwardPin = 14;

rightSpeedPin = 5;
rightBackPin = 16;
rightForwardPin = 17;

SPEED = 100

a.pinMode(BUTTON, a.OUTPUT)
a.pinMode(LED, a.OUTPUT)

def rightRun(state = ""):
    if state == "STOP":
        a.digitalWrite(leftBackPin, a.LOW);
        a.digitalWrite(leftForwardPin, a.LOW);
        return
    elif state == "BACK":
        a.analogWrite(leftSpeedPin, SPEED);
        a.digitalWrite(leftBackPin, a.HIGH);
        a.digitalWrite(leftForwardPin, a.LOW);
        return
    
    a.analogWrite(leftSpeedPin, SPEED);
    a.digitalWrite(leftBackPin, a.LOW);
    a.digitalWrite(leftForwardPin, a.HIGH);
    
    
    
def leftRun(state = ""):
    if state == "STOP":
        a.digitalWrite(rightBackPin, a.LOW);
        a.digitalWrite(rightForwardPin, a.LOW);
        return
    elif state == "BACK":
        a.analogWrite(rightSpeedPin, SPEED);
        a.digitalWrite(rightBackPin, a.HIGH);
        a.digitalWrite(rightForwardPin, a.LOW);
        return
        
    a.analogWrite(rightSpeedPin, SPEED);
    a.digitalWrite(rightBackPin, a.LOW);
    a.digitalWrite(rightForwardPin, a.HIGH);

while True:
    state = a.digitalRead(BUTTON);
    print("Button state is", state);
    if state == 1:
        a.digitalWrite(LED, a.HIGH)
        rightRun();
        leftRun();
        sleep(3);
        rightRun("BACK");
        leftRun();
        sleep(3);
        rightRun();
        leftRun("BACK");
    else:
        a.digitalWrite(LED, a.LOW)
        rightRun("BACK");
        leftRun("BACK"); 

    





