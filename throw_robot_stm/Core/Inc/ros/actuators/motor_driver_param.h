#ifndef _ROS_actuators_motor_driver_param_h
#define _ROS_actuators_motor_driver_param_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace actuators
{

  class motor_driver_param : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef uint8_t _dir1_type;
      _dir1_type dir1;
      typedef uint8_t _dir2_type;
      _dir2_type dir2;
      typedef uint16_t _pwm_type;
      _pwm_type pwm;

    motor_driver_param():
      id(0),
      dir1(0),
      dir2(0),
      pwm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->dir1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dir1);
      *(outbuffer + offset + 0) = (this->dir2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dir2);
      *(outbuffer + offset + 0) = (this->pwm >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pwm >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pwm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->dir1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dir1);
      this->dir2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dir2);
      this->pwm =  ((uint16_t) (*(inbuffer + offset)));
      this->pwm |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pwm);
     return offset;
    }

    virtual const char * getType() override { return "actuators/motor_driver_param"; };
    virtual const char * getMD5() override { return "4dd7daa3fbb798d83aefe25263d7d1e1"; };

  };

}
#endif
