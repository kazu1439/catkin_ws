#include "ros/ros.h"
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float32.h>

void chatterCallback(const std_msgs::Float32::ConstPtr& msg);

std_msgs::Float32MultiArray msg;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "comtest");
  ros::NodeHandle n;
  ros::NodeHandle pnh("~");
  double param_data=0;
  pnh.getParam("int_param", param_data);

  ros::Publisher chatter_pub = n.advertise<std_msgs::Float32MultiArray>("led", 1000);
  ros::Subscriber sub = n.subscribe("led2", 1000, chatterCallback);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    msg.data.resize(1);
    msg.data[0] = param_data;

    ROS_INFO("%f", msg.data[0]);
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}

void chatterCallback(const std_msgs::Float32::ConstPtr& msg)
{
  ROS_INFO("I heard: [%f]", msg->data);
}