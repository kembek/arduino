from nanpy import ArduinoApi, SerialManager, Ultrasonic
from time import sleep
from constants import *
from run import leftRun, rightRun

connection = SerialManager()
a = ArduinoApi(connection = connection)

u = Ultrasonic(ECHO, TRIG, False)


while True:
    distance = u.get_distance()
    print("Distance", distance);
    if distance <= 5:
        print(STOP);
        leftRun(a, STOP);
        rightRun(a, STOP);
    elif distance > 5 and distance <= 20:
        print(GO);
        leftRun(a, GO);
        rightRun(a, GO);
    elif distance >= 20:
        print(FAST);
        leftRun(a, GO, 200);
        rightRun(a, GO, 200);
        
        
    