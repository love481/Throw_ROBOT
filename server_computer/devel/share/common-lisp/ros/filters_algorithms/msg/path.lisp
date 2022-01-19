; Auto-generated. Do not edit!


(cl:in-package filters_algorithms-msg)


;//! \htmlinclude path.msg.html

(cl:defclass <path> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass path (<path>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <path>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'path)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name filters_algorithms-msg:<path> is deprecated: use filters_algorithms-msg:path instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <path>) ostream)
  "Serializes a message object of type '<path>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <path>) istream)
  "Deserializes a message object of type '<path>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<path>)))
  "Returns string type for a message object of type '<path>"
  "filters_algorithms/path")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'path)))
  "Returns string type for a message object of type 'path"
  "filters_algorithms/path")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<path>)))
  "Returns md5sum for a message object of type '<path>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'path)))
  "Returns md5sum for a message object of type 'path"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<path>)))
  "Returns full string definition for message of type '<path>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'path)))
  "Returns full string definition for message of type 'path"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <path>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <path>))
  "Converts a ROS message object to a list"
  (cl:list 'path
))
