#include "ros/ros.h"
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Bool.h>

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

  ros::Publisher int_pub = n.advertise<std_msgs::Int32>("test_int", 1);
  ros::Publisher intArray_pub = n.advertise<std_msgs::Int32MultiArray>("test_intArray", 1);
  ros::Publisher float_pub = n.advertise<std_msgs::Float32>("test_float", 1);
  ros::Publisher floatArray_pub = n.advertise<std_msgs::Float32MultiArray>("test_floatArray", 1);
  ros::Publisher bool_pub = n.advertise<std_msgs::Bool>("test_bool", 1);
  ros::Subscriber sub = n.subscribe("led2", 1000, chatterCallback);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    msg.data.resize(1);
    msg.data[0] = param_data;

    ROS_INFO("%f", msg.data[0]);
    chatter_pub.publish(msg);

    std_msgs::Int32 msg_int;
    msg_int.data = 777;
    int_pub.publish(msg_int);
    std_msgs::Int32MultiArray msg_intArray;
    msg_intArray.data.resize(3);
    msg_intArray.data[0] = 3;
    msg_intArray.data[1] = 0;
    msg_intArray.data[2] = 9;
    intArray_pub.publish(msg_intArray);
    std_msgs::Float32 msg_float;
    msg_float.data = 7.77;
    float_pub.publish(msg_float);
    std_msgs::Float32MultiArray msg_floatArray;
    msg_floatArray.data.resize(3);
    msg_floatArray.data[0] = 3.09;
    msg_floatArray.data[1] = 1.4;
    msg_floatArray.data[2] = 20.01;
    floatArray_pub.publish(msg_floatArray);
    std_msgs::Bool msg_bool;
    msg_bool.data = true;
    bool_pub.publish(msg_bool);


    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}

void chatterCallback(const std_msgs::Float32::ConstPtr& msg)
{
  ROS_INFO("I heard: [%f]", msg->data);
}