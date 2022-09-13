#!/home/roblab/.pyenv/shims/python

import rospy
import sys


print("Hello, World!")

print(sys.version)

if __name__ == '__main__':
    while True:
        a = rospy.get_param("samplec/int_param")
        print(a)
