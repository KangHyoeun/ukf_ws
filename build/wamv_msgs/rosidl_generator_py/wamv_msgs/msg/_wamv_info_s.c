// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from wamv_msgs:msg/WAMVInfo.idl
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
#include "wamv_msgs/msg/detail/wamv_info__struct.h"
#include "wamv_msgs/msg/detail/wamv_info__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool wamv_msgs__msg__navigation_type__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * wamv_msgs__msg__navigation_type__convert_to_py(void * raw_ros_message);
bool wamv_msgs__msg__navigation_type__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * wamv_msgs__msg__navigation_type__convert_to_py(void * raw_ros_message);
bool wamv_msgs__msg__guidance_type__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * wamv_msgs__msg__guidance_type__convert_to_py(void * raw_ros_message);
bool wamv_msgs__msg__control_type__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * wamv_msgs__msg__control_type__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool wamv_msgs__msg__wamv_info__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[34];
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
    assert(strncmp("wamv_msgs.msg._wamv_info.WAMVInfo", full_classname_dest, 33) == 0);
  }
  wamv_msgs__msg__WAMVInfo * ros_message = _ros_message;
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
  {  // ukf_navigation
    PyObject * field = PyObject_GetAttrString(_pymsg, "ukf_navigation");
    if (!field) {
      return false;
    }
    if (!wamv_msgs__msg__navigation_type__convert_from_py(field, &ros_message->ukf_navigation)) {
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
  {  // guidance
    PyObject * field = PyObject_GetAttrString(_pymsg, "guidance");
    if (!field) {
      return false;
    }
    if (!wamv_msgs__msg__guidance_type__convert_from_py(field, &ros_message->guidance)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // control
    PyObject * field = PyObject_GetAttrString(_pymsg, "control");
    if (!field) {
      return false;
    }
    if (!wamv_msgs__msg__control_type__convert_from_py(field, &ros_message->control)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * wamv_msgs__msg__wamv_info__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of WAMVInfo */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("wamv_msgs.msg._wamv_info");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "WAMVInfo");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  wamv_msgs__msg__WAMVInfo * ros_message = (wamv_msgs__msg__WAMVInfo *)raw_ros_message;
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
  {  // ukf_navigation
    PyObject * field = NULL;
    field = wamv_msgs__msg__navigation_type__convert_to_py(&ros_message->ukf_navigation);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "ukf_navigation", field);
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
  {  // guidance
    PyObject * field = NULL;
    field = wamv_msgs__msg__guidance_type__convert_to_py(&ros_message->guidance);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "guidance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // control
    PyObject * field = NULL;
    field = wamv_msgs__msg__control_type__convert_to_py(&ros_message->control);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "control", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
