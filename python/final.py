import bluetooth; 
from flask import Flask, render_template, request;
from constants import *

ADDR = "00:0E:0E:14:40:E0";
PORT = 1;

socket = bluetooth.BluetoothSocket(bluetooth.RFCOMM);
#socket.connect((ADDR, PORT));
app = Flask(__name__);

@app.route("/")
def main():
    return render_template("control.html");


@app.route("/<control>")
def robot_control(control):
    
    bluetoothState = "ON";
    
    if control == GO:
        socket.send(GO);
    elif control == STOP:
        socket.send(STOP);
    elif control == BACK:
        socket.send(BACK);
    elif control == LEFT:
        socket.send(LEFT);
    elif control == RIGHT:
        socket.send(RIGHT);
    elif control == SPEEDLOW:
        socket.send(SPEEDLOW);
    elif control == SPEEDUP:
        socket.send(SPEEDUP);
    elif control == BT_ON:
        # socket.send(BT_ON);
        socket.connect((ADDR, PORT));
        bluetoothState = "ON";
    elif control == BT_OFF:
        # socket.send(BT_OFF);
        socket.close();
        bluetoothState = "OFF";
        
    
    return render_template("control.html", BT_STATE= bluetoothState);    
    

if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0");