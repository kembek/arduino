def checkUserNatGender(gender, age):
    one = two = three = four ="";
    
    if gender == "male":
        print("You male");
        one = "мальчик";
        two = "Юноша";
        three = "Мужчина";
        four = "Пенсионер";
    else:
        print("You female");
        one = "девочка";
        two = "девушка";
        three = "женщина";
        four = "Пенсионерка";
        
    if age < 12:
        print(one);
    elif age >= 12 and age < 30:       
        print(two);
    elif age >= 30 and age < 60:
        print(three);
    else:
        print(four);