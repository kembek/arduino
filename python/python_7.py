from nanpy import ArduinoApi, SerialManager, W2812
from time import sleep
from constants import *

connection = SerialManager()
a = ArduinoApi(connection = connection)

w = W2812(NUM_RGB, RGB);

w.setColorRGB(0 ,255, 255, 0);
w.setColorRGB(1, 255, 255, 0);
w.setColorRGB(2, 0, 0, 0);
w.setColorRGB(3 ,255, 255, 255);
