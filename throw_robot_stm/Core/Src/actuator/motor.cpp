#include "motor.h"
/* SET DUTYCYCLE primary function */
static void set_pwm(TIM_HandleTypeDef *htim, uint32_t Channel, uint16_t mapped_value)
{
        //htim->Instance->CCR3=299; 
         __HAL_TIM_SET_COMPARE(htim, Channel, mapped_value);
}
static void set_motorDirection(Motor_config *m, Direction d)
{     
        if (d == Direction::CLOCKWISE)
        {
                HAL_GPIO_WritePin(m->in1_port, m->in1_pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(m->in2_port, m->in2_pin, GPIO_PIN_SET);
        }
        else if (d == Direction::ANTICLOCKWISE)
        {
                HAL_GPIO_WritePin(m->in1_port, m->in1_pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(m->in2_port, m->in2_pin, GPIO_PIN_RESET);
        }
        else
        
        {
                HAL_GPIO_WritePin(m->in1_port, m->in1_pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(m->in2_port, m->in2_pin, GPIO_PIN_RESET);
        }
}
void motor::set_motorParam(actuators::motor_driver_param param)
{
        if (param.dir1==1 && param.dir2==0)
        {
                set_motorDirection(motor_, Direction::ANTICLOCKWISE);
                set_pwm(motor_->htim, motor_->channel,param.pwm);
        }
        else if (param.dir1==0 && param.dir2==1)
        {
                set_motorDirection(motor_, Direction::CLOCKWISE);
                set_pwm(motor_->htim, motor_->channel,param.pwm);
        }
        else
        {
                set_motorDirection(motor_, Direction::STOP);
                set_pwm(motor_->htim, motor_->channel,param.pwm);
        }
}
