#pragma once
#ifndef _MOTOR_H_
#define _MOTOR_H_
#include"actuators/motor_driver_param.h"
#include"main.h"
enum Direction
{
	CLOCKWISE,
	ANTICLOCKWISE,
	STOP
};
struct Motor_config
{
	GPIO_TypeDef *in1_port;
	uint16_t in1_pin;
	GPIO_TypeDef *in2_port;
	uint16_t in2_pin;
	TIM_HandleTypeDef *htim; // PWM Generating Timer
	uint32_t channel;			 // PWM Channel
};

class motor
{
public:
	motor() 
	{ 
	  motor_ = 0;
	}
	motor(Motor_config *Motor_config_) { motor_ = Motor_config_; }
	motor(motor &&) = default;
	motor(const motor &) = default;
	motor &operator=(motor &&) = default;
	motor &operator=(const motor &) = default;
	~motor() {}
	void set_config(Motor_config *Motor_config_) { motor_ = Motor_config_; }
	void set_motorParam(actuators::motor_driver_param);
private:
	Motor_config *motor_;
	actuators::motor_driver_param param;
};

#endif //!_MOTOR_H_
