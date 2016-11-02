import random
p = 1000
w = 1000
for i in range(10):
    print w,p
    for i in range(w):
        a =  random.randint(-10000,10000)
        b =  random.randint(-10000,10000)
        print a,b
    for i in range(p):
        x = random.randint(1,w)
        a =  random.randint(-10000,10000)
        b =  random.randint(-10000,10000)
        print x,a,b
