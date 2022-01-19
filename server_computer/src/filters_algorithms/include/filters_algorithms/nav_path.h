#pragma once
#ifndef _NAV_PATH_
#define _NAV_PATH_
#include"control/pid.h"
#include"filters_algorithms/polynomial_curve.h"
bool firstTime=false;
enum pid_Algorithm
{
   CONTINOUS,
   DISCRETE,
   FUZZY
};
struct robot_pose
{
  float x, y, theta;
};
struct robot_twist
{

float velocity, omega, direction;

};
class nav_path
{   
private:
    robot_pose *crp;//current robot pose
	robot_pose *prp;//previous robot pose
    robot_twist *rt;//robot twist
	robot_pose s_pose;
	robot_pose s_pose_final;
	robot_twist s_twist;
	robot_pose pose_error;
	discrete_PID d_pid;
	continuous_PID c_pid;
	float dia_tol_area;
public:
	nav_path()
	{  
        crp=new robot_pose();
		prp=new robot_pose();
        rt= new robot_twist();
		setRobotPositionState(0,0,0);
		setRobotVelocityState(0,0,0);
		dia_tol_area=0.01;

	}
	~nav_path(){}
	void setTargetPosition(float x_, float y_, float theta_)
	{
      s_pose.x=x_;
	  s_pose.y=y_;
	  s_pose.theta=theta_;

	}
	void setTargetPositionFinal(float x_, float y_, float theta_)
	{
      s_pose_final.x=x_;
	  s_pose_final.y=y_;
	  s_pose_final.theta=theta_;

	}
	void setTargetVelocity(float velocity, float direction, float omega)
	{
      s_twist.velocity=velocity;
	  s_twist.direction=direction;
	  s_twist.omega=omega;

	}
	void setRobotPositionState(float x_, float y_, float theta_)
	{
		if(firstTime==false)
		{
		crp->x = x_;
		crp->y = y_;
		crp->theta = theta_;
		prp=crp;
		firstTime=true;
		}
		else
		{

        crp->x = x_;
		crp->y = y_;
		crp->theta = theta_;

		}
	}
	void setRobotVelocityState(float velocity_, float omega_, float direction_)
	{
		
	    rt->velocity = velocity_;
		rt->omega = omega_;
		rt->direction = direction_;
	}
	void setPIDConstrain(float kp, float ki, float kd, float Min, float Max, int pon = P_ON_E, int Mode = AUTOMATIC, int Direction = DIRECT)
	{
		c_pid.SetOutputLimits(Min, Max);
		c_pid.SetMode(Mode);
		c_pid.SetControllerDirection(Direction);
		c_pid.SetTunings(kp, ki, kd, pon);
	}
	void setDiscretePIDConstrain(float kp, float ki, float kd, float Min, float Max)
	{
		d_pid.SetOutputLimits(Min, Max);
		d_pid.SetTunings(kp, ki, kd);
	}
	float computeOmega(float, float,pid_Algorithm);
	robot_twist computeOmegaBasedOnPose_velocity();
	robot_twist computeOmegaBasedOnPose_velocityUsingPID(pid_Algorithm);
    void reset_state(){
		crp->x=0;
		crp->y=0;
		crp->theta=0;
	}
	bool check_update_status()
	{return (sqrt((s_pose_final.x-crp->x)*(s_pose_final.x-crp->x)+(s_pose_final.y-crp->y)*(s_pose_final.y-crp->y))<=dia_tol_area);}
};
#endif //!_NAV_PATH_