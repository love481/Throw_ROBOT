#include"robo_init.h"
#include"operation.h"
#include<ros.h>
#include"actuators/Vector4.h"
#include"actuators/motor_driver_param.h"
#include"actuators/Vector2.h"
ros::NodeHandle nh;
actuators::Vector4 encoder_count;
actuators::Vector2 free_wheel_e;
extern motor motor_[4];
extern encoder encoder_[4];
extern free_wheel ex;
extern free_wheel ey;
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}
ros::Publisher pub1("encoder_base_count", &encoder_count);
ros::Publisher pub2("free_wheel_distance", &free_wheel_e);
void motor_base_callback(const actuators::motor_driver_param& msg)
{
  motor_[msg.id].set_motorParam(msg);
  //  if(msg.id==0){  
  //     printf("d1 %d\n",msg.dir1);
  //  printf("d2 %d\n",msg.dir2);
  //  printf("pwm %d\n", msg.pwm);
  //  }
}
ros::Subscriber<actuators::motor_driver_param> sub("motor_base",motor_base_callback);
void init()
{
  
 robo_init();
 nh.initNode();
 nh.advertise(pub1);
 nh.advertise(pub2);
 nh.subscribe(sub);
}
void run()
{
 for(int i=0;i<4;i++)
 {
  encoder_count.quad[i]=encoder_[i].get_count();
 }
  free_wheel_e.dual[0]=ex.get_distance();
  free_wheel_e.dual[1]=ey.get_distance();
  pub1.publish(&encoder_count);
  pub2.publish(&free_wheel_e);
  nh.spinOnce();
  HAL_Delay(10);
}