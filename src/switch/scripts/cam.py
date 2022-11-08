#!/usr/bin/env python
import rospy
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image




pub_img = rospy.Publisher('afterImage', Image, queue_size=10)


def callback(msg):
    try:
        bridge = CvBridge()
        cv_array = bridge.imgmsg_to_cv2(msg,"mono8")
        cv_array = cv2.resize(cv_array,(100,100))
        image_message = bridge.cv2_to_imgmsg(cv_array.astype('u1'), encoding="mono8")
        pub_img.publish(image_message)

    except Exception as err:
        rospy.logerr(err)
    
def listener():
    rospy.init_node('cam', anonymous=True)
    rospy.Subscriber("/usb_cam/image_raw",Image , callback)
    rospy.spin()
        
if __name__ == '__main__':
    listener()
