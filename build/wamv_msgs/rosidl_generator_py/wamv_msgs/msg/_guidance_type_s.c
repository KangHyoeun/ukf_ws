// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from wamv_msgs:msg/GuidanceType.idl
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
#include "wamv_msgs/msg/detail/guidance_type__struct.h"
#include "wamv_msgs/msg/detail/guidance_type__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool wamv_msgs__msg__guidance_type__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
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
    assert(strncmp("wamv_msgs.msg._guidance_type.GuidanceType", full_classname_dest, 41) == 0);
  }
  wamv_msgs__msg__GuidanceType * ros_message = _ros_message;
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
  {  // desired_psi
    PyObject * field = PyObject_GetAttrString(_pymsg, "desired_psi");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->desired_psi = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // error_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->error_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // error_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->error_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // error_psi
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_psi");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->error_psi = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x_waypoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_waypoint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_waypoint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_waypoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_waypoint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_waypoint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * wamv_msgs__msg__guidance_type__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GuidanceType */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("wamv_msgs.msg._guidance_type");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GuidanceType");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  wamv_msgs__msg__GuidanceType * ros_message = (wamv_msgs__msg__GuidanceType *)raw_ros_message;
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
  {  // desired_psi
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->desired_psi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "desired_psi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->error_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->error_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_psi
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->error_psi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_psi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x_waypoint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_waypoint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_waypoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_waypoint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_waypoint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_waypoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
