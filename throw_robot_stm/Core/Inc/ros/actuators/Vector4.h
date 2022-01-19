#ifndef _ROS_actuators_Vector4_h
#define _ROS_actuators_Vector4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace actuators
{

  class Vector4 : public ros::Msg
  {
    public:
      float quad[4];

    Vector4():
      quad()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quadi;
      u_quadi.real = this->quad[i];
      *(outbuffer + offset + 0) = (u_quadi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quadi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quadi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quadi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quad[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quadi;
      u_quadi.base = 0;
      u_quadi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quadi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quadi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quadi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quad[i] = u_quadi.real;
      offset += sizeof(this->quad[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "actuators/Vector4"; };
    virtual const char * getMD5() override { return "390dd8b5493d1ef8649e084b0a6daa79"; };

  };

}
#endif
