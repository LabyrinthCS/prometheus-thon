import serial
import numpy as np
# from vpython import *
import matplotlib.pyplot as plt
from drawnow import *

arduinoDataStream = serial.Serial('/dev/ttyACM0',9600)
plt.ion() # indicate matplotlib that we are graphing live

tempc = []
humidity = []

count = 0

def makeLiveFigure():
    #plt.ylim(10,50)
    plt.title('Fluctuations in Humidity and Temperature')
    plt.grid(True)
    plt.plot(humidity,'o-',label='Humidity')
    #plt2 = plt.twinx()
    plt.plot(tempc,'o-',label='Temperature(C)')
    plt.legend() # dynamically changes the location

while True:
    if arduinoDataStream.inWaiting() > 0:
        fluctuations = arduinoDataStream.readline()
        #print(fluctuations)

        dataStream = fluctuations.split(',')

        hum = float(dataStream[0])
        humidity.append(hum)
        temp = float(dataStream[1])
        tempc.append(temp)

        drawnow(makeLiveFigure) # update the live graph
        plt.pause(.0001) # delays the process

        count += 1
        if count > 35:
            humidity.pop(0)
            tempc.pop(0)