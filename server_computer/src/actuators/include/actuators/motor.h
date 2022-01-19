/*
 *Author:Love Panta
 *Date:28/10/2021
 */
#pragma once
#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "control/pid.h"
#include "actuators/motor_driver_param.h"
enum Direction
{
	CLOCKWISE,
	ANTICLOCKWISE,
	STOP
};
enum pid_Algorithm
{
   CONTINOUS,
   DISCRETE,
   FUZZY
};
struct Motor_config
{
	float max_omega;
	float tolerance;
    actuators::motor_driver_param motor_param;
};

class motor
{
public:
	motor() 
	{ 
	  _motor = 0;
	}
	motor(Motor_config *Motor_config_) { _motor = Motor_config_; }
	motor(motor &&) = default;
	motor(const motor &) = default;
	motor &operator=(motor &&) = default;
	motor &operator=(const motor &) = default;
	~motor() {}
	void set_config(Motor_config *Motor_config_) { _motor = Motor_config_; }
	actuators::motor_driver_param get_motorParam() { return _motor->motor_param; }
	float get_max_omega() { return _motor->max_omega; }
	void set_omega(float omega);
	void setContinousPIDConstrain(float kp, float ki, float kd, float Min, float Max,int pon= P_ON_E, int Mode = AUTOMATIC, int Direction = DIRECT)
	{
		c_pid.SetOutputLimits(Min, Max);
		c_pid.SetMode(Mode);
		c_pid.SetControllerDirection(Direction);
		c_pid.SetTunings(kp, ki, kd,pon);
	}
	void setDiscretePIDConstrain(float kp, float ki, float kd, float Min, float Max)
	{
		d_pid.SetOutputLimits(Min, Max);
		d_pid.SetTunings(kp, ki, kd);
	}
	float computeOmega(float, float,pid_Algorithm);
private:
	Motor_config *_motor;
	discrete_PID d_pid;
	continuous_PID c_pid;
};

#endif //!_MOTOR_H_