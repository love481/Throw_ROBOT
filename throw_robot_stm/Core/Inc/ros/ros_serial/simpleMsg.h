#ifndef _ROS_ros_serial_simpleMsg_h
#define _ROS_ros_serial_simpleMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_serial
{

  class simpleMsg : public ros::Msg
  {
    public:
      typedef int64_t _s_type;
      _s_type s;

    simpleMsg():
      s(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_s;
      u_s.real = this->s;
      *(outbuffer + offset + 0) = (u_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_s.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_s.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_s.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_s.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_s.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->s);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_s;
      u_s.base = 0;
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_s.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->s = u_s.real;
      offset += sizeof(this->s);
     return offset;
    }

    virtual const char * getType() override { return "ros_serial/simpleMsg"; };
    virtual const char * getMD5() override { return "304c92b24150f0692f4ca17cca2b0719"; };

  };

}
#endif
