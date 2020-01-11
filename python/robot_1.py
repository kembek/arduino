from nanpy import ArduinoApi, SerialManager
from time import sleep

connection = SerialManager()
a = ArduinoApi(connection = connection)

LED = 13
a.pinMode(LED, a.OUTPUT)

while True:
    a.digitalWrite(LED, a.HIGH)
    sleep(0.5)
    a.digitalWrite(LED, a.LOW)
    sleep(0.5)


