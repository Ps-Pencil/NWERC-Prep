import random
K = random.randint(5,10)
N = random.randint(10,20)
used = []
print N,K
for i in range(K):
    L = random.randint(5,100)
    P = random.randint(4,100)
    S = random.randint(1,N)
    while S in used:
        S = random.randint(1,N)
    used.append(S)
    print L,P,S
