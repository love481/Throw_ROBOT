/*
 *Author:Love Panta
 *Date:28/10/2021
 */
#pragma once
#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_
#include<ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Vector3.h>
#include"std_msgs/Bool.h"
#define axes_LH_X 0  //1 to -1 left right
#define axes_LH_Y 1  //1 to -1 up down
#define axes_LT   2  //decrease from 1 to -1(final)
#define axes_RH_X 3  //1 to -1  left right
#define axes_RH_Y 4  //1 to -1  up down
#define axes_RT   5  //decrease from 1 to -1(final)
#define axes_up_down   6   //1 & -1 resp
#define axes_left_right 7  //1 & -1 resp
#define buttons_A  0  //all buttons 1
#define buttons_B  1
#define buttons_X  2
#define buttons_Y  3
#define buttons_LB 4
#define buttons_RB 5
#define buttons_BACK 6
#define buttons_START 7
#define buttons_XBOX 8
enum drive_mode
{AUTO,MANUAL
};
enum potColor{
  red,blue
};
struct joy_command
{
  geometry_msgs::Vector3 robot_vel;
  std_msgs::Bool state[8];
                         // std_msgs::Bool rotate_c;
                          // std_msgs::Bool rotate_a;
                          // std_msgs::Bool go_start_to_potR;
                          // std_msgs::Bool  go_arrowR_to_potL;
                          // std_msgs::Bool go_potL_to_Rack;
                          // std_msgs::Bool go_Rack_to_potL;
                          // std_msgs::Bool go_potL_to_potR;
                          // std_msgs::Bool send_potColorRed;
};
class JoyStick
{   private:
    ros::NodeHandle nh;
    ros::Publisher pub[12];
    ros::Subscriber sub;
    sensor_msgs::Joy joy_;
    void initStep();
    void joy_callback(const sensor_msgs::Joy::ConstPtr&);
    public:
    joy_command c_joy;
    JoyStick(){initStep();}
    JoyStick(JoyStick &&) = default;
    JoyStick(const JoyStick &) = default;
    JoyStick &operator=(JoyStick &&) = default;
    JoyStick &operator=(const JoyStick &) = default;
    ros::Publisher getPublisher_handle(int i){return pub[i];}
    ~JoyStick() { }
    void processData(void);

};
#endif // !_JOYSTICK_H_