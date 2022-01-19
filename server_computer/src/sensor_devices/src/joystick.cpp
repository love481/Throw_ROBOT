#include "sensor_devices/joystick.h"
float vel=1;
drive_mode mode=drive_mode::MANUAL;
potColor color=potColor::blue;
sensor_msgs::Joy joy_msg;
std_msgs::Bool send_manual;
std_msgs::Bool send_auto;
void JoyStick::initStep()
{
  pub[0]=nh.advertise<geometry_msgs::Vector3>("robot_vel_input",1000);
  // pub[1]=nh.advertise<sensor_msgs::Joy>("upper_command",10);
  pub[2]=nh.advertise<std_msgs::Bool>("rotate_c",10);
  pub[3]=nh.advertise<std_msgs::Bool>("rotate_a",10);
  pub[4]=nh.advertise<std_msgs::Bool>("go_start_to_potR",10);
  pub[5]=nh.advertise<std_msgs::Bool>("go_potR_to_potL",10);
  pub[6]=nh.advertise<std_msgs::Bool>("go_potL_to_Rack",10);
  pub[7]=nh.advertise<std_msgs::Bool>("go_Rack_to_potL",10);
  pub[8]=nh.advertise<std_msgs::Bool>("go_potL_to_potR",10);
  pub[9]=nh.advertise<std_msgs::Bool>("send_potColorRed",10);
  pub[10]=nh.advertise<std_msgs::Bool>("send_manual_cmd",10);
  pub[11]=nh.advertise<std_msgs::Bool>("send_auto_cmd",10);
  sub=nh.subscribe("joy",1000,&JoyStick::joy_callback,this);
  joy_.axes={0,0,0,0,0,0,0,0};
  joy_.buttons={0,0,0,0,0,0,0,0,0,0,0};
  joy_msg.axes={0,0,0,0,0,0,0,0};
  joy_msg.buttons={0,0,0,0,0,0,0,0,0,0,0};
  c_joy.robot_vel.x=0;
  c_joy.robot_vel.y=0;
  c_joy.robot_vel.z=0;
  for(int i=0;i<8;i++)
     c_joy.state[i].data=false;
}
void JoyStick::joy_callback(const sensor_msgs::Joy::ConstPtr& msg)
{
  for(int i=0;i<8;i++)
    {
      joy_.axes[i]=msg->axes[i];
      joy_.buttons[i]=msg->buttons[i];
      joy_msg.axes[i]=msg->axes[i];
      joy_msg.buttons[i]=msg->buttons[i];
    }
}
void JoyStick::processData()
{ /**************base actuation ***********/
  // if(joy_.buttons[7]==1)
  //    {mode=AUTO;
  //    send_auto.data=true;

  //    }
  // else if(joy_.buttons[6]==1)
  // {
  //   mode=MANUAL;
  //   send_manual.data=true;
  // }
  // else{
  //    send_manual.data=false;
  //     send_auto.data=false;
  // }
  // if(mode==MANUAL)
  // {
  //   ROS_INFO("manual mode activated\n");
  // if(joy_.axes[axes_LH_Y]>0.2)
  // {
  //  c_joy.robot_vel.x=joy_.axes[axes_LH_Y]*vel;
  //  c_joy.robot_vel.y=90;
  //  c_joy.robot_vel.z=0;
  // }
  // else if(joy_.axes[axes_LH_Y]<-0.2 )
  // {
  //  c_joy.robot_vel.x=-joy_.axes[axes_LH_Y]*vel;
  //  c_joy.robot_vel.y=-90;
  //  c_joy.robot_vel.z=0;
  // }
  // else if(joy_.axes[axes_RH_X]>0.2)
  // {
  //  c_joy.robot_vel.x=joy_.axes[axes_RH_X]*vel;
  //  c_joy.robot_vel.y=180;
  //  c_joy.robot_vel.z=0;
  // }
  //  else if(joy_.axes[axes_RH_X]<-0.2)
  // {
  //  c_joy.robot_vel.x=-joy_.axes[axes_RH_X]*vel;
  //  c_joy.robot_vel.y=0;
  //  c_joy.robot_vel.z=0;
  // }
  // else if(joy_.axes[axes_RT]<0)
  //  {
  //   c_joy.robot_vel.x=0;
  //   c_joy.robot_vel.y=0;
  //   c_joy.robot_vel.z=0.2*joy_.axes[axes_RT];
  //  }
  // else if(joy_.axes[axes_LT]<0)
  //  {
  //   c_joy.robot_vel.x=0;
  //   c_joy.robot_vel.y=0;
  //   c_joy.robot_vel.z=-0.2*joy_.axes[axes_LT];
  //  }
  // else
  // {
  // c_joy.robot_vel.x=0;
  // c_joy.robot_vel.y=0;
  // c_joy.robot_vel.z=0;
  // }
  // }
  // if(mode==AUTO)
  {
      ROS_INFO("Auto mode activated\n");
    if(color==potColor::red)
      c_joy.state[7].data=true;
  if(joy_.axes[axes_RH_X]>0.2)
  {
    c_joy.state[3].data=true;
  }
  else if(joy_.axes[axes_RH_X]<-0.2)
  {
     c_joy.state[6].data=true;
  }
  else if (joy_.axes[axes_LT]<0)
  {
    c_joy.state[1].data=true;
  }
  else if(joy_.axes[axes_RT]<0)
  {
    c_joy.state[0].data=true;
  }  
  else
  {
       c_joy.state[0].data=false;
        c_joy.state[1].data=false;
         c_joy.state[6].data=false;
           c_joy.state[3].data=false;


  }
  }
}
int main(int argc, char **argv)
{ 
   ros::init(argc, argv, "xboxnode");
   ros::NodeHandle nh;
   JoyStick joy;
   ros::Rate loop_rate(100);
   while (ros::ok())
   {
    
    joy.processData();
    //  if(mode==MANUAL)
    //  {
    //     joy.getPublisher_handle(0).publish(joy.c_joy.robot_vel);
    //     joy.getPublisher_handle(10).publish(send_manual);
    //  }
    // else
     {
      for(int i=0;i<8;i++)
        joy.getPublisher_handle(i+2).publish(joy.c_joy.state[i]);
      // joy.getPublisher_handle(11).publish(send_auto);
      }
     //joy.getPublisher_handle(1).publish(joy_msg);
    loop_rate.sleep();
    ros::spinOnce();
   }
   
}