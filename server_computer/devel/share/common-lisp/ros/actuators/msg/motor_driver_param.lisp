; Auto-generated. Do not edit!


(cl:in-package actuators-msg)


;//! \htmlinclude motor_driver_param.msg.html

(cl:defclass <motor_driver_param> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (dir1
    :reader dir1
    :initarg :dir1
    :type cl:fixnum
    :initform 0)
   (dir2
    :reader dir2
    :initarg :dir2
    :type cl:fixnum
    :initform 0)
   (pwm
    :reader pwm
    :initarg :pwm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass motor_driver_param (<motor_driver_param>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motor_driver_param>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motor_driver_param)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name actuators-msg:<motor_driver_param> is deprecated: use actuators-msg:motor_driver_param instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <motor_driver_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader actuators-msg:id-val is deprecated.  Use actuators-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'dir1-val :lambda-list '(m))
(cl:defmethod dir1-val ((m <motor_driver_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader actuators-msg:dir1-val is deprecated.  Use actuators-msg:dir1 instead.")
  (dir1 m))

(cl:ensure-generic-function 'dir2-val :lambda-list '(m))
(cl:defmethod dir2-val ((m <motor_driver_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader actuators-msg:dir2-val is deprecated.  Use actuators-msg:dir2 instead.")
  (dir2 m))

(cl:ensure-generic-function 'pwm-val :lambda-list '(m))
(cl:defmethod pwm-val ((m <motor_driver_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader actuators-msg:pwm-val is deprecated.  Use actuators-msg:pwm instead.")
  (pwm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motor_driver_param>) ostream)
  "Serializes a message object of type '<motor_driver_param>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dir1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dir2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pwm)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pwm)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motor_driver_param>) istream)
  "Deserializes a message object of type '<motor_driver_param>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dir1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dir2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pwm)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pwm)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motor_driver_param>)))
  "Returns string type for a message object of type '<motor_driver_param>"
  "actuators/motor_driver_param")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motor_driver_param)))
  "Returns string type for a message object of type 'motor_driver_param"
  "actuators/motor_driver_param")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motor_driver_param>)))
  "Returns md5sum for a message object of type '<motor_driver_param>"
  "4dd7daa3fbb798d83aefe25263d7d1e1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motor_driver_param)))
  "Returns md5sum for a message object of type 'motor_driver_param"
  "4dd7daa3fbb798d83aefe25263d7d1e1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motor_driver_param>)))
  "Returns full string definition for message of type '<motor_driver_param>"
  (cl:format cl:nil "#motor driving param~%uint8 id~%uint8 dir1~%uint8 dir2~%uint16 pwm~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motor_driver_param)))
  "Returns full string definition for message of type 'motor_driver_param"
  (cl:format cl:nil "#motor driving param~%uint8 id~%uint8 dir1~%uint8 dir2~%uint16 pwm~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motor_driver_param>))
  (cl:+ 0
     1
     1
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motor_driver_param>))
  "Converts a ROS message object to a list"
  (cl:list 'motor_driver_param
    (cl:cons ':id (id msg))
    (cl:cons ':dir1 (dir1 msg))
    (cl:cons ':dir2 (dir2 msg))
    (cl:cons ':pwm (pwm msg))
))
