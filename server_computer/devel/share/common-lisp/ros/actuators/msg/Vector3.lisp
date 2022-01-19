; Auto-generated. Do not edit!


(cl:in-package actuators-msg)


;//! \htmlinclude Vector3.msg.html

(cl:defclass <Vector3> (roslisp-msg-protocol:ros-message)
  ((tri
    :reader tri
    :initarg :tri
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass Vector3 (<Vector3>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Vector3>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Vector3)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name actuators-msg:<Vector3> is deprecated: use actuators-msg:Vector3 instead.")))

(cl:ensure-generic-function 'tri-val :lambda-list '(m))
(cl:defmethod tri-val ((m <Vector3>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader actuators-msg:tri-val is deprecated.  Use actuators-msg:tri instead.")
  (tri m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Vector3>) ostream)
  "Serializes a message object of type '<Vector3>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'tri))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Vector3>) istream)
  "Deserializes a message object of type '<Vector3>"
  (cl:setf (cl:slot-value msg 'tri) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'tri)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Vector3>)))
  "Returns string type for a message object of type '<Vector3>"
  "actuators/Vector3")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Vector3)))
  "Returns string type for a message object of type 'Vector3"
  "actuators/Vector3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Vector3>)))
  "Returns md5sum for a message object of type '<Vector3>"
  "8c49180465985aea8f1b4c8c15017d58")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Vector3)))
  "Returns md5sum for a message object of type 'Vector3"
  "8c49180465985aea8f1b4c8c15017d58")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Vector3>)))
  "Returns full string definition for message of type '<Vector3>"
  (cl:format cl:nil "float32[3] tri~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Vector3)))
  "Returns full string definition for message of type 'Vector3"
  (cl:format cl:nil "float32[3] tri~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Vector3>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'tri) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Vector3>))
  "Converts a ROS message object to a list"
  (cl:list 'Vector3
    (cl:cons ':tri (tri msg))
))
