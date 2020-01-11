from nanpy import ArduinoApi, SerialManager
from time import sleep

connection = SerialManager()
a = ArduinoApi(connection = connection)

BUTTON = 2
LED = 13
a.pinMode(BUTTON, a.OUTPUT)
a.pinMode(LED, a.OUTPUT)

globalState = False;

while True:
    state = a.digitalRead(BUTTON);
    print("Button state is", state);
    
    if globalState:
        a.digitalWrite(LED, a.HIGH)
    else:
        a.digitalWrite(LED, a.LOW)
    
    if state == 1:
        if globalState:
            globalState = False;
        else:
            globalState = True;
        
    
    



