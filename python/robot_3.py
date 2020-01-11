from nanpy import ArduinoApi, SerialManager
from time import sleep

connection = SerialManager()
a = ArduinoApi(connection = connection)

BUTTON = 2
LED = 13
a.pinMode(BUTTON, a.OUTPUT)
a.pinMode(LED, a.OUTPUT)

while True:
    state = a.digitalRead(BUTTON);
    print("Button state is", state);
    if state == 1:
        a.digitalWrite(LED, a.HIGH)
        sleep(0.5)
    else:
        a.digitalWrite(LED, a.LOW)
        sleep(0.5)
    




