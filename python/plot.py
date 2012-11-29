import numpy
import matplotlib.pyplot as plt

f = open('../data/fb_pairs_1.dat')
fb_data = []
for line in f.readlines():
    fb_data.append(int(line))

#for i in range(1000, 1010):
#    print fb_data[i]

f = open('../data/points_pairs.dat')
coord_data = []
for line in f.readlines():
    coord_data.append(.1*float(line))
    
#for i in range(1000, 1010):
#    print coord_data[i]

l = 1000 #min(len(fb_data), len(coord_data))
fb_data = fb_data[:l]
coord_data = coord_data[:l]
x = range(0, l)

plt.plot(x, fb_data, 'b-', x, coord_data, 'r-')
plt.show()

