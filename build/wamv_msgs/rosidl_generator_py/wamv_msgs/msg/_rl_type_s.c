// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from wamv_msgs:msg/RLType.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "wamv_msgs/msg/detail/rl_type__struct.h"
#include "wamv_msgs/msg/detail/rl_type__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool wamv_msgs__msg__navigation_type__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * wamv_msgs__msg__navigation_type__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool wamv_msgs__msg__rl_type__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[30];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("wamv_msgs.msg._rl_type.RLType", full_classname_dest, 29) == 0);
  }
  wamv_msgs__msg__RLType * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // navigation
    PyObject * field = PyObject_GetAttrString(_pymsg, "navigation");
    if (!field) {
      return false;
    }
    if (!wamv_msgs__msg__navigation_type__convert_from_py(field, &ros_message->navigation)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // left_thrust
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_thrust");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_thrust = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_thrust
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_thrust");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_thrust = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * wamv_msgs__msg__rl_type__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RLType */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("wamv_msgs.msg._rl_type");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RLType");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  wamv_msgs__msg__RLType * ros_message = (wamv_msgs__msg__RLType *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // navigation
    PyObject * field = NULL;
    field = wamv_msgs__msg__navigation_type__convert_to_py(&ros_message->navigation);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "navigation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_thrust
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_thrust);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_thrust", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_thrust
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_thrust);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_thrust", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
