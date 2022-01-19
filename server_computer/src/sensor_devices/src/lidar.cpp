#include "sensor_devices/lidar.h"
void lidar::initStep()
{
  pub_=nh_.advertise<geometry_msgs::Pose2D>("robot_pose",1000);
  sub_=nh_.subscribe("/slam_out_pose",1000,&lidar::lidar_callback,this);
  //sub_amcl=nh_.subscribe("/amcl_pose",1000,&lidar::amcl_callback,this);
  pose2d_.x=0;
  pose2d_.y=0;  
  pose2d_.theta=0;
}
void lidar::lidar_callback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    pose2d_.x=msg->pose.position.x;
    pose2d_.y=msg->pose.position.y;
    pose2d_.theta=tf::getYaw(msg->pose.orientation);
    pub_.publish(pose2d_);
}
void lidar::amcl_callback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    pose2d_.x=msg->pose.pose.position.x;
    pose2d_.y=msg->pose.pose.position.y;
    pose2d_.theta=tf::getYaw(msg->pose.pose.orientation);
    //ROS_INFO("inp_x inp_y inp_theta : %f  %f  %f\n",pose2d_.x,pose2d_.y,pose2d_.theta);
    pub_.publish(pose2d_);
}
int main(int argc,char** argv)
{
  ros::init(argc,argv,"lidar");
  lidar lidar_;
  ros::Rate loop_rate(10);
  while(ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
}