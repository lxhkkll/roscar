// Generated by gencpp from file interface/info.msg
// DO NOT EDIT!


#ifndef INTERFACE_MESSAGE_INFO_H
#define INTERFACE_MESSAGE_INFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace interface
{
template <class ContainerAllocator>
struct info_
{
  typedef info_<ContainerAllocator> Type;

  info_()
    {
    }
  info_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::interface::info_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::interface::info_<ContainerAllocator> const> ConstPtr;

}; // struct info_

typedef ::interface::info_<std::allocator<void> > info;

typedef boost::shared_ptr< ::interface::info > infoPtr;
typedef boost::shared_ptr< ::interface::info const> infoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::interface::info_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::interface::info_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace interface

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'interface': ['/home/allen/linux/catkin_ws/src/interface/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::interface::info_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::interface::info_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::interface::info_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::interface::info_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::interface::info_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::interface::info_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::interface::info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::interface::info_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::interface::info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "interface/info";
  }

  static const char* value(const ::interface::info_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::interface::info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::interface::info_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::interface::info_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct info_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::interface::info_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::interface::info_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // INTERFACE_MESSAGE_INFO_H