from constants import *

speed = SPEED;

def rightRun(a, state = ""):
    if state == STOP:
        a.digitalWrite(leftBackPin, a.LOW);
        a.digitalWrite(leftForwardPin, a.LOW);
        return
    elif state == BACK:
        a.analogWrite(leftSpeedPin, speed);
        a.digitalWrite(leftBackPin, a.HIGH);
        a.digitalWrite(leftForwardPin, a.LOW);
        return
    
    a.analogWrite(leftSpeedPin, speed);
    a.digitalWrite(leftBackPin, a.LOW);
    a.digitalWrite(leftForwardPin, a.HIGH);
    
def leftRun(a, state = ""):
    if state == STOP:
        a.digitalWrite(rightBackPin, a.LOW);
        a.digitalWrite(rightForwardPin, a.LOW);
        return
    elif state == BACK:
        a.analogWrite(rightSpeedPin, speed);
        a.digitalWrite(rightBackPin, a.HIGH);
        a.digitalWrite(rightForwardPin, a.LOW);
        return
        
    a.analogWrite(rightSpeedPin, speed);
    a.digitalWrite(rightBackPin, a.LOW);
    a.digitalWrite(rightForwardPin, a.HIGH);
    
def speedUpdate(newSpeed):
    speed = newSpeed;
    print(speed);
