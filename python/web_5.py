from nanpy import ArduinoApi, SerialManager;
from flask import Flask, render_template, request;
from time import sleep;
from constants import *
from run import leftRun, rightRun, speedUpdate

app = Flask(__name__);

connection = SerialManager();
a = ArduinoApi(connection = connection);

LED = 13;
a.pinMode(LED, a.OUTPUT);

@app.route("/")
def main():
    return render_template("control.html");

@app.route("/<control>")
def ledControl(control):
    robotState = "OFF";
    if control=="ON":
        robotState = "ON"
        a.digitalWrite(LED, a.HIGH);
    elif control=="OFF":
        robotState="OFF"
        a.digitalWrite(LED, a.LOW);    
    elif control==GO:
        robotState=GO;
        leftRun(a, GO);
        rightRun(a, GO);
    elif control == STOP:
        robotState=STOP;
        leftRun(a, STOP);
        rightRun(a, STOP);
    elif control == RIGHT:
        robotState = RIGHT;
        leftRun(a, BACK);
        rightRun(a, GO);
    elif control == LEFT:
        robotState = LEFT;
        leftRun(a, GO);
        rightRun(a, BACK);
    elif control == SPEEDUP:
        speedUpdate(255);
    elif control == SPEEDLOW:
        speedUpdate(50);
        
        
    return render_template("control.html", robotState=robotState);


if __name__ == '__main__':
    app.run();


