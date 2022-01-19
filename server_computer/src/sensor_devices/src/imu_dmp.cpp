#include<ros/ros.h>
#include<geometry_msgs/Vector3.h>
#include<std_msgs/Float32.h>
#include<geometry_msgs/Quaternion.h>
std_msgs::Float32 filtered_yaw;
geometry_msgs::Quaternion filtered_quat;
bool first_time=false;
float data_offset=0;
int count_data_nbr=0;
void ypr_callback(const geometry_msgs::Vector3::ConstPtr& msg)
{
// if(first_time==false && msg->x!=0)
// {   count_data_nbr++;
//     if(count_data_nbr>100)
//       {
//           data_offset=msg->x;
//           first_time=true;
//           count_data_nbr=0;
//       }
// }
    
// else
   filtered_yaw.data=msg->x;
    
}
void quaternion_callback(const geometry_msgs::Quaternion::ConstPtr& msg)
{
 filtered_quat=*msg;
}
int main(int argc, char **argv)
{
ros::init(argc, argv, "imu_node");
ros::NodeHandle nh;
ros::Publisher yaw_pub=nh.advertise<std_msgs::Float32>("IMU/yaw",1000);
ros::Subscriber ypr_sub = nh.subscribe<geometry_msgs::Vector3>("/IMU/ypr", 1000,&ypr_callback);
ros::Subscriber quat_sub = nh.subscribe<geometry_msgs::Quaternion>("/IMU/quaternion", 1000,&quaternion_callback);
ros::Rate loop_rate(100);
while(ros::ok())
{
ROS_INFO("filtered yaw:%f",filtered_yaw.data);
yaw_pub.publish(filtered_yaw);
loop_rate.sleep();
ros::spinOnce();
}
}