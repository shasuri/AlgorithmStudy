N = int(input())

st = []

for i in range(N) :
    st.append(int(input()))

for i in range(N) :
    s = 0
    for j in range(N) :
        if st[i] % st[j] == 0 :
            s += 1
    print(s-1)
