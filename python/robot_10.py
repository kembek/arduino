import bluetooth; # импортируем библиотеку для управления с помощью bluetooth

# mac addres robot and port
ADDR = "00:0E:0E:14:40:E0";
PORT = 1;

# 
socket = bluetooth.BluetoothSocket(bluetooth.RFCOMM);

#
socket.connect((ADDR, PORT));
socket.send("Hello word");

def switchMotorCommand(command):
    switcher = {
        "S": command,
        "G": command,
        "L": command,
        "R": command,
        "B": command
        };
    # print switcher.get(command, "NOT Valid")

while True:
    userInput = input("Input command: ");
    
    socket.send(userInput);  

socket.close();


