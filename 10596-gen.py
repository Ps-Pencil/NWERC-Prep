import random
N = 10
M = 20
print N,M
for i in range(M):
    a = random.randint(0,N)
    b = random.randint(0,N)
    while(b==a):
        b = random.randint(0,N)
    print a,b
