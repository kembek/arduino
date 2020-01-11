from checkUserNatGender import checkUserNatGender;

while True:
    userAge = int(input("Type you age: "));
    userGender = (input("Type you gender: "));
    userNat = (input("Type you national: "));
    print("");
    print("*** BEGIN ***");
    if userNat == "kyrgyz":
        print("You kyrgyz");
        checkUserNatGender(userGender, userAge);    
    else:
        print("You иностанец", userNat);
        checkUserNatGender(userGender, userAge);
    print("");
    print("*** END ***");
