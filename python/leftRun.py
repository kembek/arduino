from constants import *
    
def leftRun(a, state = ""):
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