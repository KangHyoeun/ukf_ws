# generated from rosidl_generator_py/resource/_idl.py.em
# with input from wamv_msgs:msg/WAMVInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WAMVInfo(type):
    """Metaclass of message 'WAMVInfo'."""

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
                'wamv_msgs.msg.WAMVInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__wamv_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__wamv_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__wamv_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__wamv_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__wamv_info

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from wamv_msgs.msg import ControlType
            if ControlType.__class__._TYPE_SUPPORT is None:
                ControlType.__class__.__import_type_support__()

            from wamv_msgs.msg import GuidanceType
            if GuidanceType.__class__._TYPE_SUPPORT is None:
                GuidanceType.__class__.__import_type_support__()

            from wamv_msgs.msg import NavigationType
            if NavigationType.__class__._TYPE_SUPPORT is None:
                NavigationType.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class WAMVInfo(metaclass=Metaclass_WAMVInfo):
    """Message class 'WAMVInfo'."""

    __slots__ = [
        '_header',
        '_ukf_navigation',
        '_navigation',
        '_guidance',
        '_control',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'ukf_navigation': 'wamv_msgs/NavigationType',
        'navigation': 'wamv_msgs/NavigationType',
        'guidance': 'wamv_msgs/GuidanceType',
        'control': 'wamv_msgs/ControlType',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['wamv_msgs', 'msg'], 'NavigationType'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['wamv_msgs', 'msg'], 'NavigationType'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['wamv_msgs', 'msg'], 'GuidanceType'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['wamv_msgs', 'msg'], 'ControlType'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from wamv_msgs.msg import NavigationType
        self.ukf_navigation = kwargs.get('ukf_navigation', NavigationType())
        from wamv_msgs.msg import NavigationType
        self.navigation = kwargs.get('navigation', NavigationType())
        from wamv_msgs.msg import GuidanceType
        self.guidance = kwargs.get('guidance', GuidanceType())
        from wamv_msgs.msg import ControlType
        self.control = kwargs.get('control', ControlType())

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
        if self.ukf_navigation != other.ukf_navigation:
            return False
        if self.navigation != other.navigation:
            return False
        if self.guidance != other.guidance:
            return False
        if self.control != other.control:
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
    def ukf_navigation(self):
        """Message field 'ukf_navigation'."""
        return self._ukf_navigation

    @ukf_navigation.setter
    def ukf_navigation(self, value):
        if __debug__:
            from wamv_msgs.msg import NavigationType
            assert \
                isinstance(value, NavigationType), \
                "The 'ukf_navigation' field must be a sub message of type 'NavigationType'"
        self._ukf_navigation = value

    @builtins.property
    def navigation(self):
        """Message field 'navigation'."""
        return self._navigation

    @navigation.setter
    def navigation(self, value):
        if __debug__:
            from wamv_msgs.msg import NavigationType
            assert \
                isinstance(value, NavigationType), \
                "The 'navigation' field must be a sub message of type 'NavigationType'"
        self._navigation = value

    @builtins.property
    def guidance(self):
        """Message field 'guidance'."""
        return self._guidance

    @guidance.setter
    def guidance(self, value):
        if __debug__:
            from wamv_msgs.msg import GuidanceType
            assert \
                isinstance(value, GuidanceType), \
                "The 'guidance' field must be a sub message of type 'GuidanceType'"
        self._guidance = value

    @builtins.property
    def control(self):
        """Message field 'control'."""
        return self._control

    @control.setter
    def control(self, value):
        if __debug__:
            from wamv_msgs.msg import ControlType
            assert \
                isinstance(value, ControlType), \
                "The 'control' field must be a sub message of type 'ControlType'"
        self._control = value
