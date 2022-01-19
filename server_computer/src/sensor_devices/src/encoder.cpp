#include "sensor_devices/encoder.h"
#include "actuators/Vector4.h"
#include <std_msgs/Float32.h>
#include"actuators/Vector2.h"
#include<std_msgs/Bool.h>
static actuators::Vector4 encoder_base_omega;
static std_msgs::Float32 encoder_upper_angle[2];
void encoder::encoderInitilize()
{
	prevAngle =((2 * PI * ((int16_t)cnt)) /ppr);
	angle=0;
    prevTime=ros::Time::now();
}
float encoder::get_omega(void)
{
    omega = (2 * PI * ((int16_t)cnt)) / (ppr * (ros::Time::now()-prevTime).toSec());
   // omega = (2 * PI * ((int16_t)cnt)) / (ppr * 0.01);
    count+=(int16_t)cnt;
    cnt=0;
    prevTime=ros::Time::now();
    return omega;
}
float encoder::get_angle(void)
{
    float newAngle = ((2 * PI * ((int16_t) cnt+count)) /ppr);
    count+=cnt;
	float dx=newAngle-prevAngle;
	dx = normalizeAngle(dx);
	angle+= dx;
	prevAngle = newAngle;
	return angle;

}
int16_t encoder::get_count(void)
{
	return count;
}
void encoder_init_base(encoder *enc)
{
enc[0].set_ppr(1000);
enc[0].encoderInitilize();
enc[1].set_ppr(1000);
enc[1].encoderInitilize();
enc[2].set_ppr(1000);
enc[2].encoderInitilize();
enc[3].set_ppr(1000);
enc[3].encoderInitilize();

}
void encoder_base_callback(const actuators::Vector4::ConstPtr& msg,encoder *enc_)
{ 
   for(int i=0;i<4;i++)
  {
  enc_[i].set_count(msg->quad[i]);
  }
 
 //ROS_INFO("cnt  %f\n",msg->quad[2]);
 

}
// void reset_enc_callback(const std_msgs::Bool::ConstPtr& msg,encoder *enc_)
// { 
//  if(msg->data==true)
//    enc_->reset_angle();

// }
int main(int argc, char **argv)
{
ros::init(argc, argv, "encoder_node");
ros::NodeHandle nh;
encoder encoder_base[4];
encoder_init_base(encoder_base);
//pulse count get from stm32f4discovery board
ros::Subscriber sub_base = nh.subscribe<actuators::Vector4>("encoder_base_count", 1000, boost::bind(&encoder_base_callback,_1,encoder_base));
// ros::Subscriber enc_reset= nh.subscribe<std_msgs::Bool>("reset_encoder", 1000, boost::bind(&reset_enc_callback,_1,&encoder_upper[0]));
//pulse count is converted to resp omega which is then published
ros::Publisher  pub_base = nh.advertise<actuators::Vector4>("encoder_base_omega", 1000);
ros::Rate loop_rate(100);
while(ros::ok())
{
for(int i=0;i<4;i++)
    encoder_base_omega.quad[i]=encoder_base[i].get_omega();
pub_base.publish(encoder_base_omega);
//ROS_INFO("%f  %f  %f  %f",encoder_base_omega.quad[0],encoder_base_omega.quad[1],encoder_base_omega.quad[2],encoder_base_omega.quad[3]);
//ROS_INFO("%f  %d",encoder_base_omega.quad[0],encoder_base[0].get_count());
ros::spinOnce();
loop_rate.sleep();
}
}
