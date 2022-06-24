#!/home/roblab/.pyenv/shims/python

import hid

for device in hid.enumerate(0, 0):
    for k, v in device.items():
        print ('{} : {}'.format(k, v))
    print ('')
# print("Hello, World!")
# import sys

# print(sys.version)