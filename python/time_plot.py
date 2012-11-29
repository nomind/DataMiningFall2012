import numpy
import matplotlib.pyplot as plt
from math import log

x = [log(50), log(100), log(200), log(500), log(1000), log(2000), log(5000)]
y1 = [log(139), log(750), log(11127), log(1032904)]
y2 = [log(38), log(129), log(493), log(3185), log(13252), log(56208), log(394802)]

plt.plot(x[:4], y1, 'r^-', x, y2, 'bs-')
plt.show()

