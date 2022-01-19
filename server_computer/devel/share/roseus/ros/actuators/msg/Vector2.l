;; Auto-generated. Do not edit!


(when (boundp 'actuators::Vector2)
  (if (not (find-package "ACTUATORS"))
    (make-package "ACTUATORS"))
  (shadow 'Vector2 (find-package "ACTUATORS")))
(unless (find-package "ACTUATORS::VECTOR2")
  (make-package "ACTUATORS::VECTOR2"))

(in-package "ROS")
;;//! \htmlinclude Vector2.msg.html


(defclass actuators::Vector2
  :super ros::object
  :slots (_dual ))

(defmethod actuators::Vector2
  (:init
   (&key
    ((:dual __dual) (make-array 2 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _dual __dual)
   self)
  (:dual
   (&optional __dual)
   (if __dual (setq _dual __dual)) _dual)
  (:serialization-length
   ()
   (+
    ;; float32[2] _dual
    (* 4    2)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[2] _dual
     (dotimes (i 2)
       (sys::poke (elt _dual i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[2] _dual
   (dotimes (i (length _dual))
     (setf (elt _dual i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get actuators::Vector2 :md5sum-) "dc6fc6947e0b42110f3e03b6150ecb68")
(setf (get actuators::Vector2 :datatype-) "actuators/Vector2")
(setf (get actuators::Vector2 :definition-)
      "float32[2] dual
")



(provide :actuators/Vector2 "dc6fc6947e0b42110f3e03b6150ecb68")


