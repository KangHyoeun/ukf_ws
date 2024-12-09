// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from wamv_msgs:msg/WAMVInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "wamv_msgs/msg/detail/wamv_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace wamv_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void WAMVInfo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) wamv_msgs::msg::WAMVInfo(_init);
}

void WAMVInfo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<wamv_msgs::msg::WAMVInfo *>(message_memory);
  typed_message->~WAMVInfo();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WAMVInfo_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs::msg::WAMVInfo, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ukf_navigation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wamv_msgs::msg::NavigationType>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs::msg::WAMVInfo, ukf_navigation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "navigation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wamv_msgs::msg::NavigationType>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs::msg::WAMVInfo, navigation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "guidance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wamv_msgs::msg::GuidanceType>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs::msg::WAMVInfo, guidance),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "control",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wamv_msgs::msg::ControlType>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wamv_msgs::msg::WAMVInfo, control),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WAMVInfo_message_members = {
  "wamv_msgs::msg",  // message namespace
  "WAMVInfo",  // message name
  5,  // number of fields
  sizeof(wamv_msgs::msg::WAMVInfo),
  WAMVInfo_message_member_array,  // message members
  WAMVInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  WAMVInfo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WAMVInfo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WAMVInfo_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace wamv_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wamv_msgs::msg::WAMVInfo>()
{
  return &::wamv_msgs::msg::rosidl_typesupport_introspection_cpp::WAMVInfo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wamv_msgs, msg, WAMVInfo)() {
  return &::wamv_msgs::msg::rosidl_typesupport_introspection_cpp::WAMVInfo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
