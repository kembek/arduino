from flask import Flask, render_template

app = Flask(__name__);

@app.route("/")
def main():
    
    templateData = {
        'userName': "Kembek",
        'currentTime': "12:05"       
    };
         
    return render_template('index.html', **templateData);

@app.route("/user")
def user():
    return "Kembek";



if __name__ == '__main__':
    app.run();