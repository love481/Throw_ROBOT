; Auto-generated. Do not edit!


(cl:in-package actuators-msg)


;//! \htmlinclude Vector2.msg.html

(cl:defclass <Vector2> (roslisp-msg-protocol:ros-message)
  ((dual
    :reader dual
    :initarg :dual
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass Vector2 (<Vector2>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Vector2>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Vector2)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name actuators-msg:<Vector2> is deprecated: use actuators-msg:Vector2 instead.")))

(cl:ensure-generic-function 'dual-val :lambda-list '(m))
(cl:defmethod dual-val ((m <Vector2>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader actuators-msg:dual-val is deprecated.  Use actuators-msg:dual instead.")
  (dual m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Vector2>) ostream)
  "Serializes a message object of type '<Vector2>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'dual))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Vector2>) istream)
  "Deserializes a message object of type '<Vector2>"
  (cl:setf (cl:slot-value msg 'dual) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'dual)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Vector2>)))
  "Returns string type for a message object of type '<Vector2>"
  "actuators/Vector2")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Vector2)))
  "Returns string type for a message object of type 'Vector2"
  "actuators/Vector2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Vector2>)))
  "Returns md5sum for a message object of type '<Vector2>"
  "dc6fc6947e0b42110f3e03b6150ecb68")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Vector2)))
  "Returns md5sum for a message object of type 'Vector2"
  "dc6fc6947e0b42110f3e03b6150ecb68")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Vector2>)))
  "Returns full string definition for message of type '<Vector2>"
  (cl:format cl:nil "float32[2] dual~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Vector2)))
  "Returns full string definition for message of type 'Vector2"
  (cl:format cl:nil "float32[2] dual~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Vector2>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'dual) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Vector2>))
  "Converts a ROS message object to a list"
  (cl:list 'Vector2
    (cl:cons ':dual (dual msg))
))
