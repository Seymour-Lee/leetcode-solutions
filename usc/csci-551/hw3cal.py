import os
import numpy as np
from scipy import stats

from scipy.stats import norm
import matplotlib.pyplot as plt




f_counter = 0
s_counter = 0

outfile = open('hw3_ori.txt', 'w')
sizes = []

for (path, dirs, files) in os.walk("/Users/SeymourLee", topdown=True):
    # print(path)
    for f in files:
        try:
            print(path+'/'+f)
            print(os.stat(path+'/'+f).st_size)
            # outfile.write(path+'/'+f + "," + str(os.stat(path+'/'+f).st_size) + '\n')
            f_counter += 1
            s_counter += os.stat(path+'/'+f).st_size
            sizes.append(1+os.stat(path+'/'+f).st_size)
        except:
            pass
sizes.sort()
print(f_counter, s_counter)

outfile.close()

# mean file size?
mean = np.mean(sizes)# float(s_counter) / float(f_counter)
print('mean', mean)

# standard deviation of file sizes?
standard = np.std(sizes)
print('std', standard)

# median file size?
median = sizes[f_counter/2]
print('median', median)

# mode of all file sizes, and how often does it occur?
mode = stats.mode(sizes)
print('mode', mode)


# PDF of file sizes? plot
# plt.plot(sizes, norm.pdf(sizes))

# plt.show()
x = np.log(sizes)
# y_pdf = norm.pdf(x, np.mean(x), np.std(x)) # the normal pdf
# y_cdf = norm.cdf(x, np.mean(x), np.std(x)) # the normal cdf
y_ccdf = norm.sf(x, np.mean(x), np.std(x)) # the normal cdf

# plt.plot(x, y_pdf, label='pdf')
plt.plot(x, np.log(y_ccdf), label='ccdf')
plt.legend()
plt.show()

# CDF of file sizes? plot the x-axis (file size) log scale and the y axis (CDF) linear scale
# print(norm.cdf(sizes, mean, standard))
# 