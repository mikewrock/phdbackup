/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/mike/catkin_ws/src/rgbdslam_v2-hydro/srv/rgbdslam_ros_ui_s.srv
 *
 */


#ifndef RGBDSLAM_MESSAGE_RGBDSLAM_ROS_UI_SREQUEST_H
#define RGBDSLAM_MESSAGE_RGBDSLAM_ROS_UI_SREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rgbdslam
{
template <class ContainerAllocator>
struct rgbdslam_ros_ui_sRequest_
{
  typedef rgbdslam_ros_ui_sRequest_<ContainerAllocator> Type;

  rgbdslam_ros_ui_sRequest_()
    : command()
    , value()  {
    }
  rgbdslam_ros_ui_sRequest_(const ContainerAllocator& _alloc)
    : command(_alloc)
    , value(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _command_type;
  _command_type command;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _value_type;
  _value_type value;




  typedef boost::shared_ptr< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct rgbdslam_ros_ui_sRequest_

typedef ::rgbdslam::rgbdslam_ros_ui_sRequest_<std::allocator<void> > rgbdslam_ros_ui_sRequest;

typedef boost::shared_ptr< ::rgbdslam::rgbdslam_ros_ui_sRequest > rgbdslam_ros_ui_sRequestPtr;
typedef boost::shared_ptr< ::rgbdslam::rgbdslam_ros_ui_sRequest const> rgbdslam_ros_ui_sRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rgbdslam

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "406bad1a44daaa500258274f332bb924";
  }

  static const char* value(const ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x406bad1a44daaa50ULL;
  static const uint64_t static_value2 = 0x0258274f332bb924ULL;
};

template<class ContainerAllocator>
struct DataType< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rgbdslam/rgbdslam_ros_ui_sRequest";
  }

  static const char* value(const ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string command\n\
string value\n\
";
  }

  static const char* value(const ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct rgbdslam_ros_ui_sRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rgbdslam::rgbdslam_ros_ui_sRequest_<ContainerAllocator>& v)
  {
    s << indent << "command: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.command);
    s << indent << "value: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RGBDSLAM_MESSAGE_RGBDSLAM_ROS_UI_SREQUEST_H
