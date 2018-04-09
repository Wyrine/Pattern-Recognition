#!/usr/local/bin/python3

class Pixel:
		def __init__(self, r=0, g=0, b=0):
				self.__mDict = {"r": r, "g": g, "b":b}
				self.__class = None
		def getRed(self):
				return self.__mDict["r"]
		def getGreen(self):
				return self.__mDict["g"]
		def getBlue(self):
				return self.__mDict["b"]
		def setClass(v):
				self.__class = v
		def getClass():
				return self.__class


