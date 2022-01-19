/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */
#include <mainpp.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt8.h>
#include <stdio.h>
ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[] = "Hello world!";

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}
void messageCb(const std_msgs::UInt8& msg) {
    printf("%d\n",msg.data);
}
ros::Subscriber<std_msgs::UInt8> sub("hello",messageCb);
void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);

}

void loop(void)
{
  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_6);
  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();

  HAL_Delay(1000);
}
