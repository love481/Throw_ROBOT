// Generated by gencpp from file laser_line_extraction/LineSegmentList.msg
// DO NOT EDIT!


#ifndef LASER_LINE_EXTRACTION_MESSAGE_LINESEGMENTLIST_H
#define LASER_LINE_EXTRACTION_MESSAGE_LINESEGMENTLIST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <laser_line_extraction/LineSegment.h>

namespace laser_line_extraction
{
template <class ContainerAllocator>
struct LineSegmentList_
{
  typedef LineSegmentList_<ContainerAllocator> Type;

  LineSegmentList_()
    : header()
    , line_segments()  {
    }
  LineSegmentList_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , line_segments(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::laser_line_extraction::LineSegment_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::laser_line_extraction::LineSegment_<ContainerAllocator> >::other >  _line_segments_type;
  _line_segments_type line_segments;





  typedef boost::shared_ptr< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> const> ConstPtr;

}; // struct LineSegmentList_

typedef ::laser_line_extraction::LineSegmentList_<std::allocator<void> > LineSegmentList;

typedef boost::shared_ptr< ::laser_line_extraction::LineSegmentList > LineSegmentListPtr;
typedef boost::shared_ptr< ::laser_line_extraction::LineSegmentList const> LineSegmentListConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::laser_line_extraction::LineSegmentList_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::laser_line_extraction::LineSegmentList_<ContainerAllocator1> & lhs, const ::laser_line_extraction::LineSegmentList_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.line_segments == rhs.line_segments;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::laser_line_extraction::LineSegmentList_<ContainerAllocator1> & lhs, const ::laser_line_extraction::LineSegmentList_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace laser_line_extraction

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "15c60e2ccf21433a5067160ec144f8c3";
  }

  static const char* value(const ::laser_line_extraction::LineSegmentList_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x15c60e2ccf21433aULL;
  static const uint64_t static_value2 = 0x5067160ec144f8c3ULL;
};

template<class ContainerAllocator>
struct DataType< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "laser_line_extraction/LineSegmentList";
  }

  static const char* value(const ::laser_line_extraction::LineSegmentList_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"LineSegment[] line_segments\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: laser_line_extraction/LineSegment\n"
"float32 radius\n"
"float32 angle\n"
"float32[4] covariance\n"
"float32[2] start\n"
"float32[2] end\n"
;
  }

  static const char* value(const ::laser_line_extraction::LineSegmentList_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.line_segments);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LineSegmentList_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::laser_line_extraction::LineSegmentList_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::laser_line_extraction::LineSegmentList_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "line_segments[]" << std::endl;
    for (size_t i = 0; i < v.line_segments.size(); ++i)
    {
      s << indent << "  line_segments[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::laser_line_extraction::LineSegment_<ContainerAllocator> >::stream(s, indent + "    ", v.line_segments[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // LASER_LINE_EXTRACTION_MESSAGE_LINESEGMENTLIST_H
