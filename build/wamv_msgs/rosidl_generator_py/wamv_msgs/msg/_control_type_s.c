// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from wamv_msgs:msg/ControlType.idl
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
#include "wamv_msgs/msg/detail/control_type__struct.h"
#include "wamv_msgs/msg/detail/control_type__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool wamv_msgs__msg__control_type__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("wamv_msgs.msg._control_type.ControlType", full_classname_dest, 39) == 0);
  }
  wamv_msgs__msg__ControlType * ros_message = _ros_message;
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
  {  // delta_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // delta_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // delta_psi
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_psi");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_psi = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pwm_standard
    PyObject * field = PyObject_GetAttrString(_pymsg, "pwm_standard");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pwm_standard = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // thruster_pwm_port
    PyObject * field = PyObject_GetAttrString(_pymsg, "thruster_pwm_port");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->thruster_pwm_port = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // thruster_pwm_stbd
    PyObject * field = PyObject_GetAttrString(_pymsg, "thruster_pwm_stbd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->thruster_pwm_stbd = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // azimuth_angle_port
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth_angle_port");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->azimuth_angle_port = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // azimuth_angle_stbd
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth_angle_stbd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->azimuth_angle_stbd = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * wamv_msgs__msg__control_type__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ControlType */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("wamv_msgs.msg._control_type");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ControlType");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  wamv_msgs__msg__ControlType * ros_message = (wamv_msgs__msg__ControlType *)raw_ros_message;
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
  {  // delta_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_psi
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_psi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_psi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pwm_standard
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pwm_standard);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pwm_standard", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thruster_pwm_port
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->thruster_pwm_port);
    {
      int rc = PyObject_SetAttrString(_pymessage, "thruster_pwm_port", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thruster_pwm_stbd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->thruster_pwm_stbd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "thruster_pwm_stbd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // azimuth_angle_port
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->azimuth_angle_port);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azimuth_angle_port", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // azimuth_angle_stbd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->azimuth_angle_stbd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azimuth_angle_stbd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
