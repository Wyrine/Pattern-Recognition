#!/usr/local/bin/python3
import sys
import ppm as _ppm
import pixel as pix

def readImage():
		with open(sys.argv[1]) as f:
				#get the header
				f.readline()
				#get comments
				tmp = f.readline()
				while tmp[0] == '#':
						tmp = f.readline()
				#get width and height
				tmp = tmp.replace('\n', '').split(' ')
				w, h = int(tmp[0]), int(tmp[1])
				mI = int(f.readline().replace('\n', '').replace(' ', ''))
				ppm = _ppm.PPM(w,h,mI)
				data = f.read().replace('\n', ' ').split()
				for i in range(0, len(data), 3):
						r, g, b = data[i], data[i+1], data[i+2]
						ppm.addPixel(pix.Pixel(r,g,b))
		return ppm

def writeImage():
		pass



def main():
		ppm = readImage()
		return 0

if __name__ == "__main__":
		main()
