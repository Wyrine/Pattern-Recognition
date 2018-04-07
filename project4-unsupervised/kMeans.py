#!/usr/local/bin/python3
import sys
import ppm as _ppm

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
				data = []
				for line in f:
						for ch in line:
								data.append(int(ch)) 
		print(data)



def main():
		readImage()
		return 0

if __name__ == "__main__":
		main()
