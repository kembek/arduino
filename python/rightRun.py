from constants import *

def rightRun(a, state = ""):
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