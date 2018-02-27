import serial
import numpy as np
import matplotlib.pyplot as plt
from drawnow import *

agricultureData = serial.Serial('/dev/ttyACM0',9600)
plt.ion()

humidity = []
tempf = []
moisture = []

count = 0

def makeLiveFigure():
	#plt.ylim(10,50)
	plt.title('Fluctuations in Humidity and Temperature')
	plt.grid(True)
	plt.plot(humidity,'o-',label='Humidity')
	#plt2 = plt.twinx()
	plt.plot(tempf,'o-',label='Temperature(C)')
	plt.plot(moisture,'o-',label='Moisture')
	plt.legend() # dynamically changes the location

while True:
	if agricultureData.inWaiting() > 0:
		mydata = agricultureData.readline()
		readings = mydata.split(",")

		hum = float(readings[0])
		humidity.append(hum)
		temp = float(readings[1])
		tempf.append(temp)
		moist = float(readings[2])
		moisture.append(moist)

		drawnow(makeLiveFigure)
		plt.pause(0.0001)

		count += 1
		if count > 35:
			humidity.pop(0)
			tempf.pop(0)
			moisture.pop(0)

