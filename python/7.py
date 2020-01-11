st = "Kyrgyz State University";
st1 = st[:6];
st2 = st[8:12];
st3 = st[13:50];
t = type(st);

print(t == type(st));

print(st1);
print(st3);

print(st1, st3);
print(" *** --- ***");
arr = st.split(" ");
print(arr[0]);
print(arr[2]);

print(arr[0], arr[2]);

st[100] = "some";
print(st);