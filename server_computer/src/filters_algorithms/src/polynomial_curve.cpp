/*
 *Author:Love Panta
 *Date:28/10/2021
 */
#include"filters_algorithms/polynomial_curve.h"
#include<ros/ros.h>
#include<geometry_msgs/Pose2D.h>
#include<filters_algorithms/math_utils.h>
#include<std_msgs/Bool.h>
int coor_nbr=0;
int NbrPoint=50;
std::vector<std::vector<float>> coor(4, std::vector<float>(3,0));
std::vector<float>coor_;
std::vector<float>lastPose{1,1,0};
geometry_msgs::Pose2D pose_;
geometry_msgs::Pose2D pose_final;
std_msgs::Bool R_to_L;
std_msgs::Bool L_to_R;
std_msgs::Bool L_to_RA;
std_msgs::Bool S_to_R;
std_msgs::Bool RA_to_L;
std_msgs::Bool rotate_c;
std_msgs::Bool rotate_a;
 std_msgs::Bool stopState;
geometry_msgs::Pose2D feedback_path_point;
PolynomialCurve curve_state[5];//0:start to right pot,1:rightpot to left pot ,2:left pot to arrowrack ,3 :arrowrack to left pot,4:left pot to right pot                                 
std::vector<std::vector<float>> splineCo{{6.5,0.5,0,0},
                                         {3.5,1,2,2},
                                         {3.5,1,2,2},
                                        {0.5,0.5,0,0}
};
std::vector<std::vector<float>> co_(4, std::vector<float>(3,0));
void bezier_function(geometry_msgs::Pose2D pose)
{
 if(coor_nbr<4)
 {
    coor[coor_nbr]={(float)pose.x,(float)pose.y,(float)pose.theta};
    coor_nbr++;
 }
//cubic curve based on the last point of one segment=first point of second segment
 if(coor_nbr<3)
 {
   if(coor_nbr==0)
   {
       coor[coor_nbr]=lastPose;
   }
    coor_nbr++;
    coor[coor_nbr]={(float)pose.x,(float)pose.y,(float)pose.theta};
 }
}
void gen_bezier_traj_based_on_shortest_path(ros::Publisher chatter_pub,ros::Rate  loop_rate)
{
   if (coor_nbr>3)
         {  coor_nbr=0;
             for(int i=0;i<NbrPoint;i++)
             { coor_=bezier_eqn(coor,(float)i/NbrPoint);
               std::cout<<coor_[0]<<"\t"<<coor_[1]<<"\t"<<(float)i/NbrPoint<<std::endl;
               pose_.x=coor_[0];
			         pose_.y=coor_[1];
			         pose_.theta=0;
               chatter_pub.publish(pose_);
			        loop_rate.sleep();
             }
         }
}
void rotate_robot()
{ 


}
void gen_bezier_traj_based_on_user_path(ros::Publisher chatter_pub,ros::Rate  loop_rate,std::vector<std::vector<float>> co)
{
   if (coor_nbr<co.size()/4)
         {
             for(int j=0;j<4;j++)
             {
               for(int i=0;i<3;i++)
                    co_[coor_nbr*4+j][i]=co[coor_nbr*4+j][i];
             }
             for(int i=0;i<=NbrPoint;i++)
             { coor_=bezier_eqn(co_,(float)i/NbrPoint);
               std::cout<<coor_[0]<<"\t"<<coor_[1]<<"\t"<<(float)i/NbrPoint<<std::endl;
               pose_.x=coor_[0];
			         pose_.y=coor_[1];
			         pose_.theta=0;
               chatter_pub.publish(pose_);
			         loop_rate.sleep();
             }
         }
         coor_nbr++;
}
void gen_spline_traj_based_on_user_path(ros::Publisher chatter_pub,ros::Rate  loop_rate)
{ std::vector<float>posX(2);
  std::vector<float>velX(2);
  std::vector<float>posY(2);
  std::vector<float>velY(2);
  float T=1;
  std::vector<float>polyX;
  std::vector<float>polyY;
   for(int i=0;i<splineCo.size()/2;i++)
   {
     posX[0]=splineCo[i*2][0];
     posY[0]=splineCo[i*2][1];
     posX[1]=splineCo[2*i+1][0];
     posY[1]=splineCo[2*i+1][1];
     velX[0]=splineCo[i*2][2];
     velY[0]=splineCo[i*2][3];
     velX[1]=splineCo[i*2+1][2];
     velY[1]=splineCo[i*2+1][3];
     polyX=min_accel(posX,velX,T);
     polyY=min_accel(posY,velY,T);
     std::cout<<polyX[0]<<" + "<<polyX[1]<<"x + "<<polyX[2]<<"x^2 + "<<polyX[3]<<"x^3"<<std::endl;
     std::cout<<polyY[0]<<" + "<<polyY[1]<<"y + "<<polyY[2]<<"y^2 + "<<polyY[3]<<"y^3"<<std::endl;
     for(float j=0.0;j<T;j=j+0.05)
     {
        pose_.x=polynomial_val(polyX,j);
        pose_.y=polynomial_val(polyY,j);
        std::cout<<i*T+j<<"\t"<<pose_.x<<std::endl;
        pose_.theta=0;
        chatter_pub.publish(pose_);
			  loop_rate.sleep();
     }
   }
}
void gen_linear_traj(ros::Publisher chatter_pub,ros::Rate  loop_rate)
{ std::vector<float>pos{0,1};
  std::vector<float>vel{0,0};
  float T=10;
  std::vector<float>poly=min_accel(pos,vel,T);
  std::vector<float>X{0,4};
  std::vector<float>Y{0,0};
  std::vector<float>theta{0,0};
  //std::cout<<poly[0]<<" + "<<poly[1]<<"x + "<<poly[2]<<"x^2 + "<<poly[3]<<"x^3"<<std::endl;
  for(float t=0.0;t<T;t=t+0.5)
     {
        pose_.x=lerp(X,poly,t);
        pose_.y=lerp(Y,poly,t);
        pose_.theta=lerp(theta,poly,t);
        chatter_pub.publish(pose_);
			  loop_rate.sleep();
     }
}
void go_potR_to_potL_callback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data==true && R_to_L.data==false)
  {
   R_to_L.data=true;
  }
}
void go_potL_to_potR_callback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data==true && L_to_R.data==false)
  {
   L_to_R.data=true;
  }
}
void go_potL_to_Rack_callback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data==true && L_to_RA.data==false)
  {
   L_to_RA.data=true;
  }
}
void go_Rack_to_potL_callback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data==true && RA_to_L.data==false)
  {
   RA_to_L.data=true;
  }
}
void go_start_to_potR_callback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data==true && S_to_R.data==false)
  {
   S_to_R.data=true;
  }
}
void rotate_a_callback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data==true)
  {
   rotate_a.data=true;
  }
}
void rotate_c_callback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data==true)
  {
   rotate_c.data=true;
  }
}
void feedback_callback(const geometry_msgs::Pose2D::ConstPtr& msg)
{  
  feedback_path_point=*msg;

}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "path_node");
  ros::NodeHandle nh;
  ros::Subscriber sub[8];
  curve_state[0].pathCoor={{0,0,0},
                          {0.4,0,0},
                          {0.4,0,0},
                          {0.8,0,0}};

  curve_state[1].pathCoor={{0,0,0},
                          {0,1,0},
                          {5,1,0},
                          {5,0,0}};

  curve_state[2].pathCoor={{4,0,0},
                          {4.9,1,0},
                          {4.9,1,0},
                          {5.3,0,0}};

  curve_state[3].pathCoor={{5.2,0,0},
                          {4.9,1,0},
                          {4.9,1,0},
                          {4,0,0}};

  curve_state[4].pathCoor={{5,0,0},
                          {2.5,1,0},
                          {2.5,1,0},
                          {0,0,0}};
  L_to_R.data=false;
  R_to_L.data=false;
  L_to_RA.data=false;
  RA_to_L.data=false;
  S_to_R.data=false;
  rotate_a.data=false;
  rotate_c.data=false;
  stopState.data=false;
  ros::Publisher pub = nh.advertise<geometry_msgs::Pose2D>("path_planning",1000);
  ros::Publisher pub_start = nh.advertise<std_msgs::Bool>("start_navigation",1000);
  ros::Publisher pub_pose_final= nh.advertise<geometry_msgs::Pose2D>("pose_final",1000);
  sub[0] = nh.subscribe<std_msgs::Bool>("go_potR_to_potL",10,&go_potR_to_potL_callback);
  sub[1]= nh.subscribe<std_msgs::Bool>("go_potL_to_Rack",10,&go_potL_to_Rack_callback);
  sub[2]= nh.subscribe<std_msgs::Bool>("go_Rack_to_potL",10,&go_Rack_to_potL_callback);
  sub[3]= nh.subscribe<std_msgs::Bool>("go_potL_to_potR",10,&go_potL_to_potR_callback);
  sub[4]= nh.subscribe<std_msgs::Bool>("go_start_to_potR",10,&go_start_to_potR_callback);
  sub[5]= nh.subscribe<std_msgs::Bool>("rotate_a",10,&rotate_a_callback);
  sub[6]= nh.subscribe<std_msgs::Bool>("rotate_c",10,&rotate_c_callback);
  sub[7]= nh.subscribe<geometry_msgs::Pose2D>("robot_pose", 1000,&feedback_callback);
  ros::Rate loop_rate(5);
   //ros::Subscriber sub = nh.subscribe<geometry_msgs::Pose2D>("path_planning", 1000,&bezier_function);
  //gen_bezier_traj_based_on_user_path(chatter_pub,loop_rate);
   //gen_linear_traj(chatter_pub,loop_rate);

  while(ros::ok())
 {
   if(R_to_L.data==true)
    {  
      pub_start.publish(R_to_L);
      gen_bezier_traj_based_on_user_path(pub,loop_rate,curve_state[1].pathCoor);
      pose_final.x=curve_state[1].pathCoor[3][0];
      pose_final.y=curve_state[1].pathCoor[3][1];
      pose_final.theta=curve_state[1].pathCoor[3][2];
      pub_pose_final.publish(pose_final);
      if(coor_nbr>=curve_state[1].pathCoor.size()/4)
      {
        R_to_L.data=false;
        coor_nbr=0;
      }
    }
    else if(L_to_R.data==true)
    {   
      pub_start.publish(L_to_R);
      gen_bezier_traj_based_on_user_path(pub,loop_rate,curve_state[4].pathCoor);
      pose_final.x=curve_state[4].pathCoor[curve_state[4].pathCoor.size()-1][0];
      pose_final.y=curve_state[4].pathCoor[curve_state[4].pathCoor.size()-1][1];
      pose_final.theta=curve_state[4].pathCoor[curve_state[4].pathCoor.size()-1][2];
      pub_pose_final.publish(pose_final);
      if(coor_nbr>=curve_state[4].pathCoor.size()/4)
      {
        L_to_R.data=false;
        coor_nbr=0;
      }

    }
    else if(L_to_RA.data==true)
    {   
       pub_start.publish(L_to_RA);
      gen_bezier_traj_based_on_user_path(pub,loop_rate,curve_state[2].pathCoor);
      pose_final.x=curve_state[2].pathCoor[curve_state[2].pathCoor.size()-1][0];
      pose_final.y=curve_state[2].pathCoor[curve_state[2].pathCoor.size()-1][1];
      pose_final.theta=curve_state[2].pathCoor[curve_state[2].pathCoor.size()-1][2];
      pub_pose_final.publish(pose_final);
      if(coor_nbr>=curve_state[2].pathCoor.size()/4)
      {
        L_to_RA.data=false;
        coor_nbr=0;
      }

    }
    else if(S_to_R.data==true)
    {   
      pub_start.publish(S_to_R);
      gen_bezier_traj_based_on_user_path(pub,loop_rate,curve_state[0].pathCoor);
      pose_final.x=curve_state[0].pathCoor[curve_state[0].pathCoor.size()-1][0];
      pose_final.y=curve_state[0].pathCoor[curve_state[0].pathCoor.size()-1][1];
      pose_final.theta=curve_state[0].pathCoor[curve_state[0].pathCoor.size()-1][2];
      pub_pose_final.publish(pose_final);
      if(coor_nbr>=curve_state[0].pathCoor.size()/4)
      {
        S_to_R.data=false;
        coor_nbr=0;
      }

    }
    else if(RA_to_L.data==true)
    {   
       pub_start.publish(RA_to_L);
       gen_bezier_traj_based_on_user_path(pub,loop_rate,curve_state[3].pathCoor);
       pose_final.x=curve_state[3].pathCoor[curve_state[3].pathCoor.size()-1][0];
      pose_final.y=curve_state[3].pathCoor[curve_state[3].pathCoor.size()-1][1];
      pose_final.theta=curve_state[3].pathCoor[curve_state[3].pathCoor.size()-1][2];
      pub_pose_final.publish(pose_final);
      if(coor_nbr>=curve_state[3].pathCoor.size()/4)
      {
        RA_to_L.data=false;
        coor_nbr=0;
      }
    }
    else if(rotate_a.data==true)
    {
      pose_.x=feedback_path_point.x;
      pose_.y=feedback_path_point.y;
      pose_.theta=M_PI/4;
      pub_start.publish(rotate_a);
      pub.publish(pose_);
      rotate_a.data=false;
    }
    else if(rotate_c.data==true)
    {
      pose_.x=feedback_path_point.x;
      pose_.y=feedback_path_point.y;
      pose_.theta=0;
      pub_start.publish(rotate_c);
      pub.publish(pose_);
      rotate_c.data=false;
    }
    ros::spinOnce();
 }

}
