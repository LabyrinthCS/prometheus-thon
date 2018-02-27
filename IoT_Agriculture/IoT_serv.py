from vpython import *
import serial
import numpy as np
import matplotlib.pyplot as plt
from drawnow import *
import time

agricultureData = serial.Serial('/dev/ttyACM0',9600)

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

humidity_graph = gcurve(color=color.blue)
tempf_graph = gcurve(color=color.orange)
moisture_graph = gcurve(color=color.green)

while True:
	rate(20)
	if agricultureData.inWaiting() > 0:
		mydata = agricultureData.readline()
		readings = mydata.split(b",")

		hum = float(readings[0])
		humidity.append(hum)
		temp = float(readings[1])
		tempf.append(temp)
		moist = float(readings[2])
		moisture.append(moist)
		for i in range(200):
			rate(30)
			#humidity_graph.plot((i,hum))
			tempf_graph.plot((i,temp))
			moisture_graph.plot((i,moist))
			time.sleep(2)
		#drawnow(makeLiveFigure)
