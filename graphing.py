from vpython import *
import random
import time
import matplotlib.pyplot as plt
from drawnow import *

anomalies = gcurve(color=color.blue)
plt.ion()

k = []

for i in range(200):
    k.append(i)

def makeLive():
    plt.title('Anomalies')
    plt.grid(True)
    plt.plot(k,'o-')


i = 0
while True:
    rate(20)
    
    rand_value = random.choice(range(200))
    anomalies.plot((i,rand_value))
    '''
    drawnow(makeLive)
    plt.pause(0.00001)
    '''
    i += 1
    time.sleep(10)