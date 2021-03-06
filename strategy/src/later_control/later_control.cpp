#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "later_car_types.h"
#include "rt_nonfinite.h"
#include "later_car.h"
#include "later_car_terminate.h"
#include "later_car_initialize.h"
#include "iostream"
#include "vision_pro/line_inform.h"
#include "geometry_msgs/Pose2D.h"
#include <std_msgs/Float64MultiArray.h>
#include "geometry_msgs/TwistStamped.h"
using namespace std;
///function steerCmd = later_car(refPose, currPose, currVelocity, direction ,gain ,wheelbase,maxSteer)
// rosrun usb_cam usb_cam_node _video_device:=/dev/video0

  double refPose[3]={0,0,0};
  double headangle=0;
  double v=1;
  int state=0;
  ros::Publisher cmd_pub;
    geometry_msgs::Pose2D cmd_msg;
void line_callback(const vision_pro::line_inform::ConstPtr& msg)
{state=msg->state;
	if(state!=3){
refPose[0]=msg->mid_x[msg->dot_num-1]/100;
refPose[1]=msg->mid_y[msg->dot_num-1]/100;
headangle=msg->angle_re;

if(state==3){
	cmd_msg.x=0;
	cout<<"==baaaaaaaaaaaaaaaadddd============\n";
	return;
}

  bool direction =1;
  double gain =2.5;
  double wheelbase =2.15;
  double maxSteer=25;
  double currPose[3]={0};
  double currVelocity=10;
refPose[2]=headangle;
cout<<"REF_xy  "<<refPose[0]<<"  "<<refPose[1]<<"\nheading"<<refPose[2]<<endl;
if(refPose[1]>0.3){
	currVelocity=25;
	cmd_msg.x=3;
}else if(refPose[1]<-0.3){
	currVelocity=25;
	cmd_msg.x=5;
}else{
	currVelocity=25;
	cmd_msg.x=4.5;
}
cmd_msg.y=3;
  double steerCmd = -later_car(refPose, currPose , currVelocity, direction ,gain ,wheelbase,maxSteer );
  cmd_msg.theta=(steerCmd +40)* (720+ 720)/(40 +40) -720;
cout<<"wheel_angle"<<steerCmd<<endl<<"steer "<<cmd_msg.theta<<endl;
cout<<"============================\n";
cmd_pub.publish(cmd_msg);
}
}
void waypoint_callback(const std_msgs::Float64MultiArray::ConstPtr& msg){
	  bool direction =1;
  double gain =2.5;
  double wheelbase =2.15;
  double maxSteer=25;
  double currPose[3]={0};
  double currVelocity=v;
refPose[0]=msg->data[0];
refPose[1]=msg->data[1];
headangle=msg->data[8];
cmd_msg.y=3;
  double steerCmd = -later_car(refPose, currPose , currVelocity, direction ,gain ,wheelbase,maxSteer );
  cmd_msg.theta=(steerCmd +40)* (720+ 720)/(40 +40) -720;
cout<<"wheel_angle"<<steerCmd<<endl<<"steer "<<cmd_msg.theta<<endl;
cout<<"============================\n";
cmd_pub.publish(cmd_msg);
}
 void callback3(const geometry_msgs::TwistStamped::ConstPtr& msg)
{
	v=msg->twist.linear.x;
}
int main(int argc, char *argv[])
{

	ros::init(argc, argv, "later_control");

	ros::NodeHandle n;

	cmd_pub = n.advertise<geometry_msgs::Pose2D>("/cmd",1000);
	ros::Subscriber sub = n.subscribe("/line_info", 1000, line_callback);
	ros::Subscriber sub1 = n.subscribe("Do_you_like_ice_cream", 10, waypoint_callback);
  ros::Subscriber sub2 = n.subscribe("/current_velocity", 1000, callback3);

	ros::Rate loop_rate(30);
  later_car_initialize();



	ros::spin();

	

	return 0;
}