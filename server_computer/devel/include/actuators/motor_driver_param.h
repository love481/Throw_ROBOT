// Generated by gencpp from file actuators/motor_driver_param.msg
// DO NOT EDIT!


#ifndef ACTUATORS_MESSAGE_MOTOR_DRIVER_PARAM_H
#define ACTUATORS_MESSAGE_MOTOR_DRIVER_PARAM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace actuators
{
template <class ContainerAllocator>
struct motor_driver_param_
{
  typedef motor_driver_param_<ContainerAllocator> Type;

  motor_driver_param_()
    : id(0)
    , dir1(0)
    , dir2(0)
    , pwm(0)  {
    }
  motor_driver_param_(const ContainerAllocator& _alloc)
    : id(0)
    , dir1(0)
    , dir2(0)
    , pwm(0)  {
  (void)_alloc;
    }



   typedef uint8_t _id_type;
  _id_type id;

   typedef uint8_t _dir1_type;
  _dir1_type dir1;

   typedef uint8_t _dir2_type;
  _dir2_type dir2;

   typedef uint16_t _pwm_type;
  _pwm_type pwm;





  typedef boost::shared_ptr< ::actuators::motor_driver_param_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::actuators::motor_driver_param_<ContainerAllocator> const> ConstPtr;

}; // struct motor_driver_param_

typedef ::actuators::motor_driver_param_<std::allocator<void> > motor_driver_param;

typedef boost::shared_ptr< ::actuators::motor_driver_param > motor_driver_paramPtr;
typedef boost::shared_ptr< ::actuators::motor_driver_param const> motor_driver_paramConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::actuators::motor_driver_param_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::actuators::motor_driver_param_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::actuators::motor_driver_param_<ContainerAllocator1> & lhs, const ::actuators::motor_driver_param_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.dir1 == rhs.dir1 &&
    lhs.dir2 == rhs.dir2 &&
    lhs.pwm == rhs.pwm;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::actuators::motor_driver_param_<ContainerAllocator1> & lhs, const ::actuators::motor_driver_param_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace actuators

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::actuators::motor_driver_param_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::actuators::motor_driver_param_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::actuators::motor_driver_param_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::actuators::motor_driver_param_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::actuators::motor_driver_param_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::actuators::motor_driver_param_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::actuators::motor_driver_param_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4dd7daa3fbb798d83aefe25263d7d1e1";
  }

  static const char* value(const ::actuators::motor_driver_param_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4dd7daa3fbb798d8ULL;
  static const uint64_t static_value2 = 0x3aefe25263d7d1e1ULL;
};

template<class ContainerAllocator>
struct DataType< ::actuators::motor_driver_param_<ContainerAllocator> >
{
  static const char* value()
  {
    return "actuators/motor_driver_param";
  }

  static const char* value(const ::actuators::motor_driver_param_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::actuators::motor_driver_param_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#motor driving param\n"
"uint8 id\n"
"uint8 dir1\n"
"uint8 dir2\n"
"uint16 pwm\n"
;
  }

  static const char* value(const ::actuators::motor_driver_param_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::actuators::motor_driver_param_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.dir1);
      stream.next(m.dir2);
      stream.next(m.pwm);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct motor_driver_param_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::actuators::motor_driver_param_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::actuators::motor_driver_param_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.id);
    s << indent << "dir1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.dir1);
    s << indent << "dir2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.dir2);
    s << indent << "pwm: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.pwm);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ACTUATORS_MESSAGE_MOTOR_DRIVER_PARAM_H
