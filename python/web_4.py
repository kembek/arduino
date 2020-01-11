from nanpy import ArduinoApi, SerialManager;
from flask import Flask, render_template, request;
from time import sleep;

app = Flask(__name__);

connection = SerialManager();
a = ArduinoApi(connection = connection);

LED = 13;
a.pinMode(LED, a.OUTPUT);

@app.route("/")
def main():
    return render_template("led-control.html");

@app.route("/<control>")
def ledControl(control):
    ledState = "OFF";
    if control=="ON":
        ledState = "ON"
        a.digitalWrite(LED, a.HIGH);
    elif control=="OFF":
        ledState="OFF"
        a.digitalWrite(LED, a.LOW);
        
    return render_template("led-control.html", LED=ledState);


if __name__ == '__main__':
    app.run();

