#include "ros/ros.h"
#include <roblab/timer.h>
#include <roblab/JoyJoy.h>
#include <vector>



int i = 1;

inline void joy_Callback( const roblab::JoyJoy::ConstPtr &joy_msg );

int main( int argc, char **argv ){
    ros::init( argc, argv, "libtest" );
    ros::NodeHandle nh;
    
    ros::Subscriber sub_ps4 = nh.subscribe( "joy0", 1, joy_Callback );
    ros::Rate loop_rate(1/0.02f);
    while (ros::ok()){

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}


inline void joy_Callback( const roblab::JoyJoy::ConstPtr &joy_msg ){
    ROS_INFO("I heared");
}