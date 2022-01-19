#ifndef _ENCODER_H_
#define _ENCODER_H_
#include"tim.h"
#include"gpio.h"
class encoder
{
private:
    TIM_HandleTypeDef *henc;
    int16_t count;
public:
    encoder() 
    {  
        count=0;
    }
    encoder(encoder &&) = default;
    encoder(const encoder &) = default;
    encoder &operator=(encoder &&) = default;
    encoder &operator=(const encoder &) = default;
    ~encoder() {}
    void set_TimerHandle(TIM_HandleTypeDef *henc_){henc=henc_;}
    TIM_HandleTypeDef* get_TimerHandle(){return henc;}
    int16_t get_count()
       {	
        count=(int16_t)henc->Instance->CNT;
        henc->Instance->CNT=0;
	    return count;
        }
};
#endif //!_ENCODER_H_