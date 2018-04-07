#!/usr/local/bin/python3

class Pixel:
	def __init__(self, r=0, g=0, b=0):
		self.__mDict = {"r": r, "g": g, "b":b}
	def getRed(self):
		return self.__mDict["r"]
	def getGreen(self):
		return self.__mDict["g"]
	def getBlue(self):
		return self.__mDict["b"]
