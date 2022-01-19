;; Auto-generated. Do not edit!


(when (boundp 'actuators::Vector3)
  (if (not (find-package "ACTUATORS"))
    (make-package "ACTUATORS"))
  (shadow 'Vector3 (find-package "ACTUATORS")))
(unless (find-package "ACTUATORS::VECTOR3")
  (make-package "ACTUATORS::VECTOR3"))

(in-package "ROS")
;;//! \htmlinclude Vector3.msg.html


(defclass actuators::Vector3
  :super ros::object
  :slots (_tri ))

(defmethod actuators::Vector3
  (:init
   (&key
    ((:tri __tri) (make-array 3 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _tri __tri)
   self)
  (:tri
   (&optional __tri)
   (if __tri (setq _tri __tri)) _tri)
  (:serialization-length
   ()
   (+
    ;; float32[3] _tri
    (* 4    3)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[3] _tri
     (dotimes (i 3)
       (sys::poke (elt _tri i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[3] _tri
   (dotimes (i (length _tri))
     (setf (elt _tri i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get actuators::Vector3 :md5sum-) "8c49180465985aea8f1b4c8c15017d58")
(setf (get actuators::Vector3 :datatype-) "actuators/Vector3")
(setf (get actuators::Vector3 :definition-)
      "float32[3] tri
")



(provide :actuators/Vector3 "8c49180465985aea8f1b4c8c15017d58")


