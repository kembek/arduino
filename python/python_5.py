from nanpy import ArduinoApi, SerialManager, Ultrasonic
from time import sleep

connection = SerialManager()
a = ArduinoApi(connection = connection)


ECHO = 2
TRIG = 3

u = Ultrasonic(ECHO, TRIG, False)


while True:
    distance = u.get_distance()
    print("Distance", distance);
    sleep(0.5);

    






