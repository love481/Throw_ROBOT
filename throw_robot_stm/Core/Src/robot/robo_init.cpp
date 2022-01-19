#include"robo_init.h"
//initilize all objects and their configurations
static Motor_config motor_configurations[4];
static free_wheel_config ex_config,ey_config;
free_wheel ex,ey;
motor motor_[4];
encoder encoder_[4];
void robo_init()
{
	motorAllInitilize();
	encoderAllInitilize();
	freeWheelAllInitilize();
}
void motorAllInitilize()
{
	motor_configurations[0].htim = &htim8;
	motor_configurations[0].in1_port = GPIOD;
	motor_configurations[0].in1_pin = GPIO_PIN_0;
	motor_configurations[0].in2_port = GPIOE;
	motor_configurations[0].in2_pin = GPIO_PIN_5;
	motor_configurations[0].channel = TIM_CHANNEL_1;

	motor_configurations[1].htim = &htim8;
	motor_configurations[1].in1_port = GPIOA;
	motor_configurations[1].in1_pin = GPIO_PIN_10;
	motor_configurations[1].in2_port = GPIOB;
	motor_configurations[1].in2_pin = GPIO_PIN_5;
	motor_configurations[1].channel = TIM_CHANNEL_2;

	motor_configurations[2].htim = &htim8;
	motor_configurations[2].in1_port = GPIOE;
	motor_configurations[2].in1_pin = GPIO_PIN_3;
	motor_configurations[2].in2_port = GPIOD;
	motor_configurations[2].in2_pin = GPIO_PIN_2;
	motor_configurations[2].channel = TIM_CHANNEL_3;

	motor_configurations[3].htim = &htim8;
	motor_configurations[3].in1_port = GPIOC;
	motor_configurations[3].in1_pin = GPIO_PIN_13;
	motor_configurations[3].in2_port = GPIOE;
	motor_configurations[3].in2_pin = GPIO_PIN_1;
	motor_configurations[3].channel = TIM_CHANNEL_4;
	HAL_TIM_Base_Start(&htim8);
	HAL_TIM_PWM_Start(motor_configurations[0].htim, motor_configurations[0].channel);
	HAL_TIM_PWM_Start(motor_configurations[1].htim, motor_configurations[1].channel);
	HAL_TIM_PWM_Start(motor_configurations[2].htim, motor_configurations[2].channel);
	HAL_TIM_PWM_Start(motor_configurations[3].htim, motor_configurations[3].channel);
	for (int i = 0; i < 4; i++)
	{
		motor_[i].set_config(&motor_configurations[i]);
	}
}
void encoderAllInitilize()
{    //set all handles for all motors
	encoder_[0].set_TimerHandle(&htim1);
	encoder_[1].set_TimerHandle(&htim2);
	encoder_[2].set_TimerHandle(&htim3);
	encoder_[3].set_TimerHandle(&htim4);

    HAL_TIM_Encoder_Start(encoder_[0].get_TimerHandle(), TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(encoder_[1].get_TimerHandle(), TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(encoder_[2].get_TimerHandle(), TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(encoder_[3].get_TimerHandle(), TIM_CHANNEL_ALL);

}
void freeWheelAllInitilize()
{
	ex_config.id='x';
	ex_config.port = GPIOC;
	ex_config.pin = GPIO_PIN_5;
	ex_config.ppr=200;
	ex_config.radius=0.0294;

	ey_config.id='y';
	ey_config.port = GPIOC;
	ey_config.pin = GPIO_PIN_4;
	ey_config.ppr=200;
	ey_config.radius=0.0294;

	ex.set_config(&ex_config);
	ey.set_config(&ey_config);


}