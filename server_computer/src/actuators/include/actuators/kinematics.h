#pragma once
#ifndef _KINEMATICS_H_
#define _KINEMATICS_H_
#include"control/defines.h"
#include"ros/ros.h"
class kinematics
{  private:
	float motor_omega[4];
	float robot_velocity[3];
   public:
	void set_motorOmegaFromInvKin(void);
	void set_robotVelocity(float,float,float=0);
	float get_motorOmegaFromInvKin(int motor_index) { return motor_omega[motor_index];}
	float* get_robotVelocityFromForKin(void);
};
#endif //!_KINEMATICS_H_