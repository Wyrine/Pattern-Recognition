#!/usr/local/bin/python3
import pixel

class PPM:
	def __init__(self, w, h, intensity):
		self.__mPix = []
		self.__maxIntensity = intensity
		self.__w = w
		self.__h = h
	def addPixel(self, pix):
		if len(self.__mPix) == self.__w * self.__h:
			raise IndexError
		self.__mPix.append(pix)
	def clearPixels(self):
		self.__mPix.clear()	
	def getPixel(self, x, y):
		if x >= self.__w or y >= self.__h: 
			raise KeyError
		return self.__mPix[y*self.__w + x]
	def setPixel(self, x, y, pix):
		if x >= self.__w or y >= self.__h:
			raise KeyError
		self.__mPix[y*self.__w + x] = pix
	def getHeight(self):
		return self.__h
	def getWidth(self):
		return self.__w
	def getMaxIntensity(self):
		return self.__maxIntensity
