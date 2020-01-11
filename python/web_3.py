from flask import Flask, render_template, request

app = Flask(__name__);
webArg = "Kembek";

@app.route("/")
def main():
    
    templateData = {
        'userName': webArg,
        'currentTime': "12:05"       
    };
    userName = request.args.get("name");
    if userName:
        print(userName);
        return '''<h1>{}</h1>'''.format(userName);
         
    return render_template('index.html', **templateData);

@app.route("/user")
def user():
    userName = request.args.get("name");
    webArg = userName;
    return render_template('index.html', userName = userName);

@app.route("/send")
def sendHandler():
    return "lol";


if __name__ == '__main__':
    app.run();
