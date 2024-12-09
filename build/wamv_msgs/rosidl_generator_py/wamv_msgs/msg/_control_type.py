# generated from rosidl_generator_py/resource/_idl.py.em
# with input from wamv_msgs:msg/ControlType.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ControlType(type):
    """Metaclass of message 'ControlType'."""

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
                'wamv_msgs.msg.ControlType')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__control_type
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__control_type
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__control_type
            cls._TYPE_SUPPORT = module.type_support_msg__msg__control_type
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__control_type

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


class ControlType(metaclass=Metaclass_ControlType):
    """Message class 'ControlType'."""

    __slots__ = [
        '_header',
        '_delta_x',
        '_delta_y',
        '_delta_psi',
        '_pwm_standard',
        '_thruster_pwm_port',
        '_thruster_pwm_stbd',
        '_azimuth_angle_port',
        '_azimuth_angle_stbd',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'delta_x': 'double',
        'delta_y': 'double',
        'delta_psi': 'double',
        'pwm_standard': 'double',
        'thruster_pwm_port': 'double',
        'thruster_pwm_stbd': 'double',
        'azimuth_angle_port': 'double',
        'azimuth_angle_stbd': 'double',
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
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.delta_x = kwargs.get('delta_x', float())
        self.delta_y = kwargs.get('delta_y', float())
        self.delta_psi = kwargs.get('delta_psi', float())
        self.pwm_standard = kwargs.get('pwm_standard', float())
        self.thruster_pwm_port = kwargs.get('thruster_pwm_port', float())
        self.thruster_pwm_stbd = kwargs.get('thruster_pwm_stbd', float())
        self.azimuth_angle_port = kwargs.get('azimuth_angle_port', float())
        self.azimuth_angle_stbd = kwargs.get('azimuth_angle_stbd', float())

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
        if self.delta_x != other.delta_x:
            return False
        if self.delta_y != other.delta_y:
            return False
        if self.delta_psi != other.delta_psi:
            return False
        if self.pwm_standard != other.pwm_standard:
            return False
        if self.thruster_pwm_port != other.thruster_pwm_port:
            return False
        if self.thruster_pwm_stbd != other.thruster_pwm_stbd:
            return False
        if self.azimuth_angle_port != other.azimuth_angle_port:
            return False
        if self.azimuth_angle_stbd != other.azimuth_angle_stbd:
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
    def delta_x(self):
        """Message field 'delta_x'."""
        return self._delta_x

    @delta_x.setter
    def delta_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'delta_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._delta_x = value

    @builtins.property
    def delta_y(self):
        """Message field 'delta_y'."""
        return self._delta_y

    @delta_y.setter
    def delta_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'delta_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._delta_y = value

    @builtins.property
    def delta_psi(self):
        """Message field 'delta_psi'."""
        return self._delta_psi

    @delta_psi.setter
    def delta_psi(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_psi' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'delta_psi' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._delta_psi = value

    @builtins.property
    def pwm_standard(self):
        """Message field 'pwm_standard'."""
        return self._pwm_standard

    @pwm_standard.setter
    def pwm_standard(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pwm_standard' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pwm_standard' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pwm_standard = value

    @builtins.property
    def thruster_pwm_port(self):
        """Message field 'thruster_pwm_port'."""
        return self._thruster_pwm_port

    @thruster_pwm_port.setter
    def thruster_pwm_port(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'thruster_pwm_port' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'thruster_pwm_port' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._thruster_pwm_port = value

    @builtins.property
    def thruster_pwm_stbd(self):
        """Message field 'thruster_pwm_stbd'."""
        return self._thruster_pwm_stbd

    @thruster_pwm_stbd.setter
    def thruster_pwm_stbd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'thruster_pwm_stbd' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'thruster_pwm_stbd' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._thruster_pwm_stbd = value

    @builtins.property
    def azimuth_angle_port(self):
        """Message field 'azimuth_angle_port'."""
        return self._azimuth_angle_port

    @azimuth_angle_port.setter
    def azimuth_angle_port(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'azimuth_angle_port' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'azimuth_angle_port' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._azimuth_angle_port = value

    @builtins.property
    def azimuth_angle_stbd(self):
        """Message field 'azimuth_angle_stbd'."""
        return self._azimuth_angle_stbd

    @azimuth_angle_stbd.setter
    def azimuth_angle_stbd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'azimuth_angle_stbd' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'azimuth_angle_stbd' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._azimuth_angle_stbd = value
