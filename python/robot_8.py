from nanpy import ArduinoApi, SerialManager, W2812
from time import sleep
from constants import *

connection = SerialManager()
a = ArduinoApi(connection = connection)

w = W2812(NUM_RGB, RGB);

def setColor(r,g,b):
    for i in range(NUM_RGB):
        w.setColorRGB(i, r, g, b);    

while True:
    userColor = input("Type color: ").upper();
    
    if userColor == RED:
        setColor(255, 0, 0)
    elif userColor == GREEN:
        setColor(0, 255, 0);
    elif userColor == BLUE:
        setColor(0, 0, 255);
    elif userColor == YELLOW:
        setColor(255, 255, 0);
    else:
        setColor(0, 0, 0);


