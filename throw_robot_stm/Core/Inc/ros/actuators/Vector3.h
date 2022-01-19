#ifndef _ROS_actuators_Vector3_h
#define _ROS_actuators_Vector3_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace actuators
{

  class Vector3 : public ros::Msg
  {
    public:
      float tri[3];

    Vector3():
      tri()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_trii;
      u_trii.real = this->tri[i];
      *(outbuffer + offset + 0) = (u_trii.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trii.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trii.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trii.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tri[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_trii;
      u_trii.base = 0;
      u_trii.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trii.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trii.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trii.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tri[i] = u_trii.real;
      offset += sizeof(this->tri[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "actuators/Vector3"; };
    virtual const char * getMD5() override { return "8c49180465985aea8f1b4c8c15017d58"; };

  };

}
#endif
