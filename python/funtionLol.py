isTrue = True;

def lol():
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
        isTrue = False;
    else:
        print("You stupid\n");
