import random
N = 200000
l = [str(i) for i in range(1,N+1)]
print N
random.shuffle(l)
print ' '.join(l)
random.shuffle(l)
print ' '.join(l)
random.shuffle(l)
print ' '.join(l)
