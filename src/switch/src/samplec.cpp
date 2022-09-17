#include <ros/ros.h>
#include <roblab/timer.h>
#include <roblab/JoyJoy.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "param_sample");
  ros::NodeHandle nh;
  ros::NodeHandle pnh("~");
  int param_data=0;
  pnh.getParam("int_param", param_data);
  int p = 0;
  nh.getParam("samplec/int_param",p);
  ROS_INFO("[%s] param:%i", ros::this_node::getName().c_str(), p);
  Timer t(10); 

  ros::spin();
  return 0;
}