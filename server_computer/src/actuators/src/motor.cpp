#include "actuators/motor.h"
#include "actuators/Vector4.h"
#include "actuators/Vector3.h"
#include <std_msgs/Float32.h>
static actuators::Vector4 encoder_base_omega;
static actuators::Vector4  setpoint_base_omega;
static uint16_t time_period(uint16_t PWM_frequency)
{
        return ((168000000 / 2) / PWM_frequency) - 1; // In Center aligned mode period doubles hence we divide by 2
}
/* SET DUTYCYCLE primary function */
static void set_DutyCycle_Primary(Motor_config *m,uint16_t dutyCycle)
{
        uint16_t mapped_value;
        mapped_value = (time_period(8000) * dutyCycle) / 65535;
        m->motor_param.pwm=mapped_value;
}
static void set_motorDirection(Motor_config *m, Direction d)
{     
        if (d == Direction::CLOCKWISE)
        {       
                m->motor_param.dir1=1;
                m->motor_param.dir2=0;
        }
        else if (d == Direction::ANTICLOCKWISE)
        {
                m->motor_param.dir1=0;
                m->motor_param.dir2=1;
        }
        else
        {
                m->motor_param.dir1=0;
                m->motor_param.dir2=0;
        }
}
static void set_motorOmega(Motor_config *m, float omega)
{
        uint16_t new_omega = (65535.0 / m->max_omega) * (omega);
        set_DutyCycle_Primary(m,new_omega);
}
float motor::computeOmega(float setpoint, float input,pid_Algorithm pid)
{   
        //printf("tar:%f\n",setpoint);
        //printf("%f\n",input);
        if (pid==pid_Algorithm::CONTINOUS)
           return c_pid.Compute(setpoint, input);  
        else if(pid==pid_Algorithm::DISCRETE)
           return d_pid.Compute(setpoint, input); 
         else if(pid==pid_Algorithm::FUZZY)
           return f_pid.compute_fuzzy_selfTuning_PID(setpoint,input);; 
        else return setpoint;
}
void motor::set_omega(float omega)
{
        if (omega > _motor->max_omega)
        {
                omega = _motor->max_omega;
        }
        else if (omega < -_motor->max_omega)
        {
                omega = -_motor->max_omega;
        }
        if (omega < -_motor->tolerance)
        {
                set_motorDirection(_motor, Direction::ANTICLOCKWISE);
                set_motorOmega(_motor, fabs(omega));
        }
        else if (omega > _motor->tolerance)
        {
                set_motorDirection(_motor, Direction::CLOCKWISE);
                set_motorOmega(_motor, fabs(omega));
        }
        else
        {
                set_motorDirection(_motor, Direction::STOP);
                set_motorOmega(_motor, 0);
        }
}
void motor_init_base(Motor_config *m)
{
 m[0].max_omega=77.28;
 m[0].tolerance=1;
 m[0].motor_param.id=0;
 m[0].motor_param.dir1=0;
 m[0].motor_param.dir2=0;
 m[0].motor_param.pwm=0;
 m[1].max_omega=75;
 m[1].tolerance=1;
 m[1].motor_param.id=1;
 m[1].motor_param.dir1=0;
 m[1].motor_param.dir2=0;
 m[1].motor_param.pwm=0;
 m[2].max_omega=79.165;
 m[2].tolerance=1;
 m[2].motor_param.id=2;
 m[2].motor_param.dir1=0;
 m[2].motor_param.dir2=0;
 m[2].motor_param.pwm=0;
 m[3].max_omega=72.882;
 m[3].tolerance=1;
 m[3].motor_param.id=3;
 m[3].motor_param.dir1=0;
 m[3].motor_param.dir2=0;
 m[3].motor_param.pwm=0;
}
void pid_init_base(motor *m,pid_Algorithm *pid_Algorithm_)
{
 /* pid_Algorithm_[0]=CONTINOUS;
  m[0].setContinousPIDConstrain(1,20,0,-20,20);
  pid_Algorithm_[1]=CONTINOUS;
  m[1].setContinousPIDConstrain(1,20,0,-20,20);
  pid_Algorithm_[2]=CONTINOUS;
  m[2].setContinousPIDConstrain(1,20,0,-20,20);
  pid_Algorithm_[3]=CONTINOUS;
  m[3].setContinousPIDConstrain(1,20,0,-20,20);*/
  
   pid_Algorithm_[0]=FUZZY;
  m[0].setfuzzyPIDConstrain(1,20,0,-20,20);
  pid_Algorithm_[1]=FUZZY;
  m[1].setfuzzyPIDConstrain(1,20,0,-20,20);
  pid_Algorithm_[2]=FUZZY;
  m[2].fuzzyPIDConstrain(1,20,0,-20,20);
  pid_Algorithm_[3]=FUZZY;
  m[3].setfuzzyPIDConstrain(1,20,0,-20,20);
}
void feedback_base_callback(const actuators::Vector4::ConstPtr& msg)
{ 
   for(int i=0;i<4;i++)
  {
  encoder_base_omega.quad[i]=msg->quad[i];
  }
}
void setpoint_base_callback(const actuators::Vector4::ConstPtr& msg)
{ 
   for(int i=0;i<4;i++)
  {
  setpoint_base_omega.quad[i]=msg->quad[i];
  }
}
int main(int argc, char **argv)
{ 
  ros::init(argc, argv, "motor_node");
  ros::NodeHandle nh;
  Motor_config motor_config_base[4];
  motor motor_base[4];
  pid_Algorithm pid_Algorithm_base[4];
  motor_init_base(motor_config_base);
  pid_init_base(motor_base,pid_Algorithm_base);
  for(int i=0;i<4;i++)
     motor_base[i].set_config(&motor_config_base[i]);
  ros::Subscriber sub_enc_base = nh.subscribe<actuators::Vector4>("encoder_base_omega", 1000,&feedback_base_callback); //get encoder feed back
  ros::Subscriber sub_set_base = nh.subscribe<actuators::Vector4>("setpoint_base_omega", 1000,&setpoint_base_callback); //get setpoint for resp motor
  ros::Publisher  pub_base = nh.advertise<actuators::motor_driver_param>("motor_base", 1000); //actuations parameter for motor to stm32f4
  ros::Rate loop_rate(50);
  while(ros::ok())
   {
//      float tunedOmega=motor_base[0].computeOmega(setpoint_base_omega.quad[0],encoder_base_omega.quad[0],pid_Algorithm_base[0]);
//      motor_base[0].set_omega(tunedOmega);
//      pub_base.publish(motor_base[0].get_motorParam());

    for(int i=0;i<4;i++)
      {float tunedOmega=motor_base[i].computeOmega(setpoint_base_omega.quad[i],encoder_base_omega.quad[i],pid_Algorithm_base[i]);
      motor_base[i].set_omega(tunedOmega);
      }
     // ROS_INFO(" omega %f\n",encoder_base_omega.quad[2]);
   for(int i=0;i<4;i++)
     pub_base.publish(motor_base[i].get_motorParam());
         ros::spinOnce();
          loop_rate.sleep();
  }
}
