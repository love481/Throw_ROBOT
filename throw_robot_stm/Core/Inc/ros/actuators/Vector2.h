#ifndef _ROS_actuators_Vector2_h
#define _ROS_actuators_Vector2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace actuators
{

  class Vector2 : public ros::Msg
  {
    public:
      float dual[2];

    Vector2():
      dual()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_duali;
      u_duali.real = this->dual[i];
      *(outbuffer + offset + 0) = (u_duali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dual[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_duali;
      u_duali.base = 0;
      u_duali.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duali.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duali.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duali.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dual[i] = u_duali.real;
      offset += sizeof(this->dual[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "actuators/Vector2"; };
    virtual const char * getMD5() override { return "dc6fc6947e0b42110f3e03b6150ecb68"; };

  };

}
#endif
