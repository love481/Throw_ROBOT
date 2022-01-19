#include"actuators/kinematics.h"
#include<geometry_msgs/Vector3.h>
#include<std_msgs/Float32MultiArray.h>
#include "actuators/Vector4.h"
actuators::Vector4 setpoint_base_omega;
/*static float inverseCouplingMatrix[4][3] =   
{   
	{-0.70711, 0.70711, 0.5  },
	{ -0.70711,-0.70711, 0.5 },
	{ 0.70711, -0.70711, 0.5 },
	{ 0.70711, 0.70711, 0.5 },
};*/
//based on direction of motion of robot for throw robot
const float inverseCouplingMatrix[4][3] =
{
	{-0.70711,-0.70711, bodyDiameter/2},
	{-0.70711, 0.70711, bodyDiameter/2},
	{ 0.70711, 0.70711, bodyDiameter/2},
	{ 0.70711,-0.70711,  bodyDiameter/2},
};
const float forwardCouplingMatrix[3][4] =
{
    {0.70711,0.70711,-0.70711,-0.70711},
	{0.70711,-0.70711,-0.70711,0.70711},
	{1/bodyDiameter,bodyDiameter,bodyDiameter,1/bodyDiameter}
};
void kinematics::set_motorOmegaFromInvKin()
{
	for (int i = 0; i < 4; i++)
	{
		motor_omega[i] = 0;
		for (int j = 0; j < 3; j++)
			motor_omega[i] += inverseCouplingMatrix[i][j] * robot_velocity[j];
		motor_omega[i] = (motor_omega[i]*2) / wheelDiameter;
	}
}
void kinematics::set_robotVelocity(float vel, float direction, float omega)
{
	robot_velocity[0] = vel * cos((PI/180) *direction);
	robot_velocity[1] = vel* sin((PI / 180) * direction);
	robot_velocity[2] = omega;
	set_motorOmegaFromInvKin();
}
float* kinematics::get_robotVelocityFromForKin()
{ 
	for (int i = 0; i < 3; i++)
	{
		robot_velocity[i] = 0;
		for (int j = 0; j < 4; j++)
			robot_velocity[i] += forwardCouplingMatrix[i][j] * motor_omega[j];
		robot_velocity[i] = (robot_velocity[i]*bodyDiameter)/4;
	}
   return robot_velocity;
}
void invKin_callback(const geometry_msgs::Vector3::ConstPtr& msg,kinematics invKin)
{ 
  invKin.set_robotVelocity(msg->x,msg->y,msg->z);
  //ROS_INFO("%f  %f  %f ",msg->x,msg->y,msg->z);
  for(int i=0;i<4;i++)
   setpoint_base_omega.quad[i]=invKin.get_motorOmegaFromInvKin(i);
}
int main(int argc, char **argv)
{
ros::init(argc, argv, "kinematics_node");
ros::NodeHandle nh;
kinematics invKin;
kinematics forKin;
ros::Subscriber sub = nh.subscribe<geometry_msgs::Vector3>("robot_vel_input", 1000, boost::bind(&invKin_callback,_1,invKin));
ros::Publisher  pub_set = nh.advertise<actuators::Vector4>("setpoint_base_omega", 1000);
ros::Publisher  pub_out = nh.advertise<geometry_msgs::Vector3>("robot_vel_output", 1000);
ros::Rate loop_rate(100);
geometry_msgs::Vector3 robot_vel_output;
float *robot_twist;
while(ros::ok())
{
pub_set.publish(setpoint_base_omega);
robot_twist=invKin.get_robotVelocityFromForKin();
robot_vel_output.x=robot_twist[0];
robot_vel_output.y=robot_twist[1];
robot_vel_output.z=robot_twist[2];
pub_out.publish(robot_vel_output);
//ROS_INFO("%f  %f %f  %f", setpoint_base_omega.quad[0],setpoint_base_omega.quad[1],setpoint_base_omega.quad[2],setpoint_base_omega.quad[3]);
ros::spinOnce();
loop_rate.sleep();
}
}
