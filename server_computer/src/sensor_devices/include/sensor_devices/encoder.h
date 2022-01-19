#ifndef _ENCODER_H_
#define _ENCODER_H_
#include<ros/ros.h>
#include"control/defines.h"
class encoder
{
private:
    uint16_t ppr;
    float omega;
    float angle,prevAngle;
    int16_t count;
    int16_t cnt;
    int16_t Prevcnt;
    ros::Time prevTime;
    int16_t prevcnt;
public:
    encoder() 
    {   
        omega=0;
        count=0;
        angle=0;
        prevAngle=0;
        ppr=0;
        Prevcnt=0;
        cnt=0;
        prevTime=(ros::Time)0;
        prevcnt=0;
    }
    encoder(encoder &&) = default;
    encoder(const encoder &) = default;
    encoder &operator=(encoder &&) = default;
    encoder &operator=(const encoder &) = default;
    ~encoder() {}
    void encoderInitilize(void);
    float get_omega(void);
    int16_t get_count(void);
    void set_count(int16_t cnt)
    {
        //this->cnt=prevcnt+0.5*(cnt-prevcnt);
        //prevcnt=cnt;
        this->cnt=cnt;
    }
    void set_ppr(int16_t ppr){this->ppr=ppr;}
    float get_angle(void);
    void reset_angle(void){count=0;cnt=0;}
};
#endif //!_ENCODER_H_