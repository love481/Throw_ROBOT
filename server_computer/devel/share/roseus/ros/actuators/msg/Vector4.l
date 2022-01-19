;; Auto-generated. Do not edit!


(when (boundp 'actuators::Vector4)
  (if (not (find-package "ACTUATORS"))
    (make-package "ACTUATORS"))
  (shadow 'Vector4 (find-package "ACTUATORS")))
(unless (find-package "ACTUATORS::VECTOR4")
  (make-package "ACTUATORS::VECTOR4"))

(in-package "ROS")
;;//! \htmlinclude Vector4.msg.html


(defclass actuators::Vector4
  :super ros::object
  :slots (_quad ))

(defmethod actuators::Vector4
  (:init
   (&key
    ((:quad __quad) (make-array 4 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _quad __quad)
   self)
  (:quad
   (&optional __quad)
   (if __quad (setq _quad __quad)) _quad)
  (:serialization-length
   ()
   (+
    ;; float32[4] _quad
    (* 4    4)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[4] _quad
     (dotimes (i 4)
       (sys::poke (elt _quad i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[4] _quad
   (dotimes (i (length _quad))
     (setf (elt _quad i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get actuators::Vector4 :md5sum-) "390dd8b5493d1ef8649e084b0a6daa79")
(setf (get actuators::Vector4 :datatype-) "actuators/Vector4")
(setf (get actuators::Vector4 :definition-)
      "float32[4] quad
")



(provide :actuators/Vector4 "390dd8b5493d1ef8649e084b0a6daa79")


