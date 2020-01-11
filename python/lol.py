

def lol(isExit):
    
    x = int( input("x : "));
    y = int( input("y : "));
    oper = input("Operation (*, /, +, -, //, %, **, x(exit)): ");

    if oper== "*":
        print("x * y = ", x*y);
    elif oper=="/":
        print("x / y = ", x/y);
    elif oper=="+":
        print("x + y = ", x+y);
    elif oper=="-":
        print("x - y = ", x-y);
    elif oper=="//":
        print("x // y = ", x//y);
    elif oper=="%":
        print("x % y = ", x%y);
    elif oper=="**":
        print("x ** y = ", x**y);
    elif oper=="x":
        isExit = False;
    else:
        print("You stupid\n");
        
    return isExit;
