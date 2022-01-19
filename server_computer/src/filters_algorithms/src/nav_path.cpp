#include<ros/ros.h>
#include"filters_algorithms/nav_path.h"
#include"std_msgs/Float32.h"
#include"std_msgs/Bool.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Pose2D.h"
#include "control/defines.h"
// std_msgs::Float32 IMU_YAW;
geometry_msgs::Pose2D setpoint_path_point;
geometry_msgs::Pose2D feedback_path_point;
geometry_msgs::Vector3 output_command;
pid_Algorithm _pid;
std_msgs::Bool get_start_cmd;
std_msgs::Bool send_manual;
std_msgs::Bool send_auto;
struct robot_twist nav_path::computeOmegaBasedOnPose_velocity()
{
  robot_twist output;
  pose_error.x=s_pose.x-crp->x;
  pose_error.y=s_pose.y-crp->y;
  pose_error.theta=atan2(pose_error.y,pose_error.y)-crp->theta;
  output.velocity=s_twist.velocity*cos(pose_error.theta);
  float phi=atan2(crp->y-prp->y,crp->x-prp->x);
  float cross_track_err=(crp->x-s_pose.x)*sin(phi)-(crp->y-s_pose.y)*cos(phi);
  float k1=0;
  float k2=0;
  output.omega=s_twist.omega+k1*s_twist.velocity*cross_track_err+k2*s_twist.velocity*sin(pose_error.theta);
  prp=crp;
  output.direction=pose_error.theta;
  return output;
}
struct robot_twist nav_path::computeOmegaBasedOnPose_velocityUsingPID(enum pid_Algorithm pid_)
{ 
  robot_twist output;
  pose_error.x=s_pose.x-crp->x;
  pose_error.y=s_pose.y-crp->y;
  pose_error.theta=atan2(pose_error.y,pose_error.x)-crp->theta;
  output.velocity=sqrt(pose_error.x*pose_error.x+pose_error.y*pose_error.y);
  output.omega=computeOmega(s_pose.theta,crp->theta,pid_);
  output.direction=pose_error.theta;
  return output;
}
float nav_path::computeOmega(float setpoint, float input,pid_Algorithm pid_)
{   
        //printf("tar:%f\n",setpoint);
        //printf("%f\n",input);
        if (pid_==pid_Algorithm::CONTINOUS)
           return c_pid.Compute(setpoint, input);  
        else if(pid_==pid_Algorithm::DISCRETE)
           return d_pid.Compute(setpoint, input); 
        else return setpoint;
}
void feedback_callback(const geometry_msgs::Pose2D::ConstPtr& msg,nav_path *obj)
{  
  feedback_path_point=*msg;
  obj->setRobotPositionState(feedback_path_point.x,feedback_path_point.y, normalizeAngle(feedback_path_point.theta));
  ROS_INFO("yes\n");
  ROS_INFO("inp_x inp_y inp_theta : %f  %f  %f\n",feedback_path_point.x,feedback_path_point.y,feedback_path_point.theta);

}
void pose_final_callback(const geometry_msgs::Pose2D::ConstPtr& msg,nav_path *obj)
{  
 obj->setTargetPositionFinal(msg->x,msg->y,msg->theta);
}
void setpoint_callback(const geometry_msgs::Pose2D::ConstPtr& msg,nav_path *obj)
{  
  setpoint_path_point=*msg;
  obj->setTargetPosition(setpoint_path_point.x,setpoint_path_point.y,setpoint_path_point.theta);
  ROS_INFO("set_x set_y set_theta : %f  %f  %f\n",setpoint_path_point.x,setpoint_path_point.y,setpoint_path_point.theta);
}
void start_nav(const std_msgs::Bool::ConstPtr& msg)
{  
  if(msg->data==true)
  {
    get_start_cmd.data=true;
  }
}
void send_manual_cmd_Callback(const std_msgs::Bool::ConstPtr& msg)
{  
  if(msg->data==true)
  {
     send_manual.data=true;
  }
}
void send_auto_cmd_Callback(const std_msgs::Bool::ConstPtr& msg)
{  
  if(msg->data==true)
  {
     send_auto.data=true;
  }
}
int main(int argc, char **argv)
{
ros::init(argc, argv, "nav_path_node");
ros::NodeHandle nh;
nav_path nav_path_obj;
nav_path_obj.setPIDConstrain(1,0.1,0,-2,2);
_pid=pid_Algorithm::CONTINOUS;
get_start_cmd.data=false;
send_auto.data=false;
send_manual.data=false;
feedback_path_point.x=0;
feedback_path_point.y=0;
feedback_path_point.theta=0;
ros::Subscriber sub[7];
//nav_path_obj.setFuzzyPIDConstrain(1,0,0,-1.5,1.5);
ros::Publisher pub=nh.advertise<geometry_msgs::Vector3>("robot_vel_input",1000);
sub[0] = nh.subscribe<geometry_msgs::Pose2D>("path_planning", 1000,boost::bind(&setpoint_callback,_1,&nav_path_obj));
sub[1]= nh.subscribe<geometry_msgs::Pose2D>("robot_pose", 1000,boost::bind(&feedback_callback,_1,&nav_path_obj));
sub[2]= nh.subscribe<std_msgs::Bool>("start_navigation", 1000,&start_nav);
sub[3]= nh.subscribe<geometry_msgs::Pose2D>("pose_final", 1000,boost::bind(&pose_final_callback,_1,&nav_path_obj));
sub[5]= nh.subscribe<std_msgs::Bool>("send_manual_cmd", 1000,&send_manual_cmd_Callback);
sub[6]= nh.subscribe<std_msgs::Bool>("send_auto_cmd", 1000,&send_auto_cmd_Callback);
ros::Rate loop_rate(5);
while(ros::ok())
{
// if(send_auto.data)
{
if(get_start_cmd.data)
{//nav_path_obj.setTargetPosition(setpoint_path_point.x,setpoint_path_point.y,setpoint_path_point.theta);
//nav_path_obj.setRobotPositionState(feedback_path_point.x,feedback_path_point.y, normalizeAngle(feedback_path_point.theta));
struct robot_twist cmd_input=nav_path_obj.computeOmegaBasedOnPose_velocityUsingPID(_pid);
output_command.x=cmd_input.velocity;
output_command.y= cmd_input.direction*(180/PI);
output_command.z=cmd_input.omega;
pub.publish(output_command);
 if(nav_path_obj.check_update_status())
{
  get_start_cmd.data=false;
  send_auto.data=false;
  setpoint_path_point.x=0;
  setpoint_path_point.y=0;
  setpoint_path_point.theta=0;
  output_command.x=0;
  output_command.y=0;
  output_command.z=0;
  pub.publish(output_command);
}
}
}
// else if(send_manual.data){
//   setpoint_path_point.x=0;
//   setpoint_path_point.y=0;
//   setpoint_path_point.theta=0;
//   output_command.x=0;
//   output_command.y=0;
//   output_command.z=0;
//   pub.publish(output_command);
// }
loop_rate.sleep();
ros::spinOnce();
}
}
