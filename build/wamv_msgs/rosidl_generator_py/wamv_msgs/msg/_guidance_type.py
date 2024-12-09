# generated from rosidl_generator_py/resource/_idl.py.em
# with input from wamv_msgs:msg/GuidanceType.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GuidanceType(type):
    """Metaclass of message 'GuidanceType'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('wamv_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'wamv_msgs.msg.GuidanceType')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__guidance_type
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__guidance_type
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__guidance_type
            cls._TYPE_SUPPORT = module.type_support_msg__msg__guidance_type
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__guidance_type

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GuidanceType(metaclass=Metaclass_GuidanceType):
    """Message class 'GuidanceType'."""

    __slots__ = [
        '_header',
        '_desired_psi',
        '_error_x',
        '_error_y',
        '_error_psi',
        '_distance',
        '_x_waypoint',
        '_y_waypoint',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'desired_psi': 'double',
        'error_x': 'double',
        'error_y': 'double',
        'error_psi': 'double',
        'distance': 'double',
        'x_waypoint': 'double',
        'y_waypoint': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.desired_psi = kwargs.get('desired_psi', float())
        self.error_x = kwargs.get('error_x', float())
        self.error_y = kwargs.get('error_y', float())
        self.error_psi = kwargs.get('error_psi', float())
        self.distance = kwargs.get('distance', float())
        self.x_waypoint = kwargs.get('x_waypoint', float())
        self.y_waypoint = kwargs.get('y_waypoint', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.desired_psi != other.desired_psi:
            return False
        if self.error_x != other.error_x:
            return False
        if self.error_y != other.error_y:
            return False
        if self.error_psi != other.error_psi:
            return False
        if self.distance != other.distance:
            return False
        if self.x_waypoint != other.x_waypoint:
            return False
        if self.y_waypoint != other.y_waypoint:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def desired_psi(self):
        """Message field 'desired_psi'."""
        return self._desired_psi

    @desired_psi.setter
    def desired_psi(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'desired_psi' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'desired_psi' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._desired_psi = value

    @builtins.property
    def error_x(self):
        """Message field 'error_x'."""
        return self._error_x

    @error_x.setter
    def error_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'error_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._error_x = value

    @builtins.property
    def error_y(self):
        """Message field 'error_y'."""
        return self._error_y

    @error_y.setter
    def error_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'error_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._error_y = value

    @builtins.property
    def error_psi(self):
        """Message field 'error_psi'."""
        return self._error_psi

    @error_psi.setter
    def error_psi(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_psi' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'error_psi' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._error_psi = value

    @builtins.property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._distance = value

    @builtins.property
    def x_waypoint(self):
        """Message field 'x_waypoint'."""
        return self._x_waypoint

    @x_waypoint.setter
    def x_waypoint(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_waypoint' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x_waypoint' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x_waypoint = value

    @builtins.property
    def y_waypoint(self):
        """Message field 'y_waypoint'."""
        return self._y_waypoint

    @y_waypoint.setter
    def y_waypoint(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_waypoint' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y_waypoint' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y_waypoint = value
