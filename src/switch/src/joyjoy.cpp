#include "ros/ros.h"
#include <sensor_msgs/Joy.h>
#include <vector>

sensor_msgs::Joy Message;
std::vector<std::string> ids;
std::vector<ros::Publisher> pubs;
int length = 1;


inline void joys_Callback( const sensor_msgs::Joy::ConstPtr &joy_msg );

int main( int argc, char **argv ){
    ros::init( argc, argv, "joyjoy" );
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    pnh.getParam("NumberOfJoy",length);
    for (int i=0; i<length; i++){
        std::string a = "joy" + std::to_string(i);
        std::string b;
        pnh.getParam(a, b);
        ROS_INFO("%s",b.c_str());
        ids.emplace_back(b);
    }

    ros::Subscriber sub_ps4 = nh.subscribe( "joy", 1, joys_Callback );
    for (int i=0; i<length; i++){
        std::string a = "joy" + std::to_string(i);
        ros::Publisher pub_joy = nh.advertise<sensor_msgs::Joy>(a, 1000);
        pubs.emplace_back(pub_joy);
    }

    ros::spin();
    return 0;
}


inline void joys_Callback( const sensor_msgs::Joy::ConstPtr &joy_msg ){
    Message.header = joy_msg->header;
    Message.axes = joy_msg->axes;
    Message.buttons = joy_msg->buttons;
    for (int i=0; i<length; i++){
        if(ids[i]==Message.header.frame_id){
            pubs[i].publish(Message);
        }
    }
}