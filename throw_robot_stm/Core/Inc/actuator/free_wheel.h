#ifndef _FREE_WHEEL_H_
#define _FREE_WHEEL_H_
#include"gpio.h"
struct free_wheel_config
{

    GPIO_TypeDef *port;
    uint16_t pin;
    int32_t count;
    float radius;
    float ppr;
    char id;
};
class free_wheel
{
private:
free_wheel_config *config;
float ds;
public:
    free_wheel() 
    {  config=new free_wheel_config;
    }
    free_wheel(free_wheel &&) = default;
    free_wheel(const free_wheel &) = default;
    free_wheel &operator=(free_wheel &&) = default;
    free_wheel &operator=(const free_wheel&) = default;
    ~free_wheel() {}
    void set_config(free_wheel_config *config)
    {
        this->config=config;
    }
    int16_t get_count()
       {	
         if (HAL_GPIO_ReadPin(config->port, config->pin) != GPIO_PIN_RESET) {
                ++config->count;
        } else {
                --config->count;
        }

        return config->count;
    }
    float get_distance()
    {
        get_count();
        ds=config->count*config->radius*2*3.1415926/config->ppr;
        config->count=0;
        return ds;
    }
};
#endif //!_FREE_WHEEL_H_