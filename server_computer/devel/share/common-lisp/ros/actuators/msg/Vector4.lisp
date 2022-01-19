; Auto-generated. Do not edit!


(cl:in-package actuators-msg)


;//! \htmlinclude Vector4.msg.html

(cl:defclass <Vector4> (roslisp-msg-protocol:ros-message)
  ((quad
    :reader quad
    :initarg :quad
    :type (cl:vector cl:float)
   :initform (cl:make-array 4 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass Vector4 (<Vector4>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Vector4>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Vector4)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name actuators-msg:<Vector4> is deprecated: use actuators-msg:Vector4 instead.")))

(cl:ensure-generic-function 'quad-val :lambda-list '(m))
(cl:defmethod quad-val ((m <Vector4>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader actuators-msg:quad-val is deprecated.  Use actuators-msg:quad instead.")
  (quad m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Vector4>) ostream)
  "Serializes a message object of type '<Vector4>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'quad))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Vector4>) istream)
  "Deserializes a message object of type '<Vector4>"
  (cl:setf (cl:slot-value msg 'quad) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'quad)))
    (cl:dotimes (i 4)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Vector4>)))
  "Returns string type for a message object of type '<Vector4>"
  "actuators/Vector4")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Vector4)))
  "Returns string type for a message object of type 'Vector4"
  "actuators/Vector4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Vector4>)))
  "Returns md5sum for a message object of type '<Vector4>"
  "390dd8b5493d1ef8649e084b0a6daa79")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Vector4)))
  "Returns md5sum for a message object of type 'Vector4"
  "390dd8b5493d1ef8649e084b0a6daa79")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Vector4>)))
  "Returns full string definition for message of type '<Vector4>"
  (cl:format cl:nil "float32[4] quad~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Vector4)))
  "Returns full string definition for message of type 'Vector4"
  (cl:format cl:nil "float32[4] quad~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Vector4>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'quad) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Vector4>))
  "Converts a ROS message object to a list"
  (cl:list 'Vector4
    (cl:cons ':quad (quad msg))
))
